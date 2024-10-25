/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstnew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:23:14 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/25 16:17:02 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include "minunit.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);

extern int mock_malloc_memset_active;

extern int mock_malloc_failure_active;

int capture_segfault_ft_lstnew(t_list	*(*f)(void *), void *content)
{
	pid_t pid = fork();
	if (pid == 0)
	{
		// Child process executes the test
		f(content);
		exit(0);
	}
	else if (pid > 0)
	{
		// Parent process waits for the child
		int status;
		waitpid(pid, &status, 0);
		if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
		{
			return 1;
		}
		return 0;
	}
	else
	{
		perror("fork");
		exit(1);
	}
}

MU_TEST(test_ft_lstnew_int)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	t_list	*lst;

	// ACT
	expected_result = 42;
	lst = ft_lstnew(&expected_result);
	if (!lst) {
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = *(int *)lst->content;

	// ASSERT
	if (memcmp((unsigned char *)lst + sizeof(t_list), "\xFF\xFF", 2) == 0)
		mu_fail("Allocation size is larger than expected for the substring");
	else if (memcmp((unsigned char *)lst + sizeof(t_list), "\xFF", 1) != 0)
		mu_fail("Allocation size is shorter than expected for the substring");
	else
		mu_assert_int_eq(expected_result, actual_result);

	// CLEANUP;
	free(lst);
}

MU_TEST(test_ft_lstnew_string)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	t_list	*lst;

	// ACT
	expected_result = strdup("forty two");
	lst = ft_lstnew(expected_result);
	if (!lst) {
		mu_fail("Memory allocation failed");
		free(expected_result);
		return;
	}
	actual_result = (char *)lst->content;

	// ASSERT
	if (memcmp((unsigned char *)lst + sizeof(t_list), "\xFF\xFF", 2) == 0)
		mu_fail("Allocation size is larger than expected for the substring");
	else if (memcmp((unsigned char *)lst + sizeof(t_list), "\xFF", 1) != 0)
		mu_fail("Allocation size is shorter than expected for the substring");
	else
		mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(expected_result);
	free(lst);
}

MU_TEST(test_ft_lstnew_null)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	t_list	*lst;

	// ACT
	expected_result = NULL;
	lst = ft_lstnew(NULL);
	if (!lst) {
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = lst->content;

	// ASSERT
	if (memcmp((unsigned char *)lst + sizeof(t_list), "\xFF\xFF", 2) == 0)
		mu_fail("Allocation size is larger than expected for the substring");
	else if (memcmp((unsigned char *)lst + sizeof(t_list), "\xFF", 1) != 0)
		mu_fail("Allocation size is shorter than expected for the substring");
	else
		mu_assert(actual_result == expected_result, "Expected NULL pointer");

	// CLEANUP
	free(lst);
}

MU_TEST(test_ft_lstnew_next)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	t_list	*lst;

	// ACT
	expected_result = NULL;
	lst = ft_lstnew("42");
	actual_result = lst->next;

	// ASSERT
	mu_assert(actual_result == expected_result, "Expected NULL pointer");

	// CLEANUP
	free(lst);
}

MU_TEST(test_ft_lstnew_malloc_fail)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	int		segfaulted;

	// ACT
	expected_result = NULL;
	mock_malloc_failure_active = 1;
	segfaulted = capture_segfault_ft_lstnew(&ft_lstnew, "42");
	if (!segfaulted)
		actual_result = ft_lstnew("42");
	mock_malloc_failure_active = 0;

	// ASSERT
	if (!segfaulted)
	{
		mu_assert(actual_result == expected_result, "Expected NULL pointer in lst->next");
		free(actual_result);
	}
	else
		mu_fail("Function should not cause a segmentation fault.");
}

MU_TEST_SUITE(ft_lstnew_test_suite)
{
	MU_RUN_TEST(test_ft_lstnew_int);
	MU_RUN_TEST(test_ft_lstnew_string);
	MU_RUN_TEST(test_ft_lstnew_null);
	MU_RUN_TEST(test_ft_lstnew_next);
	MU_RUN_TEST(test_ft_lstnew_malloc_fail);
}

int	main(void) {
	mock_malloc_memset_active = 1;
	MU_RUN_SUITE(ft_lstnew_test_suite);
	mock_malloc_memset_active = 0;
	MU_REPORT();
	return MU_EXIT_CODE;
}
