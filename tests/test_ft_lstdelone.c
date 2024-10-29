/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstdelone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:17:27 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/29 17:32:23 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include "minunit.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	ft_lstdelone(t_list *lst, void (*del)(void *));

extern int mock_free_failure_active;

extern int mock_free_memset_active;

extern int mock_free_memset_size;

int	capture_segfault_ft_lstdelone(void (*f)(t_list *, void (*)(void *)), t_list *lst, void (*del)(void *))
{
	pid_t pid = fork();
	if (pid == 0)
	{
		// Child process executes the test
		f(lst, del);
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

void	reset_int_pointer(void *ptr)
{
	int *int_ptr;

	int_ptr = (int *)ptr;
	*int_ptr = 0;
}

void	do_nothing(void *ptr)
{
	(void) ptr;
}

MU_TEST(test_ft_lstdelone_free_int_node)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	t_list *node;
	int *content;

	// ACT
	node = malloc(sizeof(t_list));
	content = malloc(sizeof(int));
	*content = 42;
	node->content = content;
	node->next = NULL;
	mock_free_memset_active = 1;
	mock_free_memset_size = sizeof(t_list);
	ft_lstdelone(node, &do_nothing);
	mock_free_memset_active = 0;
	mock_free_memset_size = 0;
	expected_result = malloc(sizeof(t_list));
	memset(expected_result, 0xFF, sizeof(t_list));
	actual_result = node;

	// ASSERT
	mu_assert(memcmp(expected_result, actual_result, sizeof(t_list)) == 0, "Node memory was not properly freed");

	// CLEANUP
	free(expected_result);
	free(content);
	free(node);
}

MU_TEST(test_ft_lstdelone_delete_int_node_content)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	t_list *node;
	int *content;

	// ACT
	node = malloc(sizeof(t_list));
	content = malloc(sizeof(int));
	*content = 42;
	node->content = content;
	node->next = NULL;
	mock_free_failure_active = 1;
	ft_lstdelone(node, &reset_int_pointer);
	mock_free_failure_active = 0;
	expected_result = 0;
	actual_result = *(int *)node->content;

	// ASSERT
	mu_assert(expected_result == actual_result, "Integer content was not properly deleted");

	// CLEANUP
	free(content);
	free(node);
}

MU_TEST(test_ft_lstdelone_null_node_pointer)
{
	int		expected_result;
	int		actual_result;

	// ACT & ASSERT
	expected_result = 1;
	actual_result = capture_segfault_ft_lstdelone(&ft_lstdelone, NULL, &do_nothing);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST(test_ft_lstdelone_null_function_pointer)
{
	int		expected_result;
	int		actual_result;
	t_list	*node;
	int *content;

	// ACT & ASSERT
	node = malloc(sizeof(t_list));
	content = malloc(sizeof(int));
	*content = 42;
	node->content = content;
	node->next = NULL;
	expected_result = 1;
	actual_result = capture_segfault_ft_lstdelone(&ft_lstdelone, node, NULL);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");

	// CLEANUP
	free(content);
	free(node);
}

MU_TEST_SUITE(ft_lstdelone_test_suite)
{
	MU_RUN_TEST(test_ft_lstdelone_free_int_node);
	MU_RUN_TEST(test_ft_lstdelone_delete_int_node_content);
	MU_RUN_TEST(test_ft_lstdelone_null_node_pointer);
	MU_RUN_TEST(test_ft_lstdelone_null_function_pointer);
}

int	main(void) {
	MU_RUN_SUITE(ft_lstdelone_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
