/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstdelone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:17:27 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/30 12:12:27 by jarao-de         ###   ########.fr       */
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

extern int mock_free_counter_active;

extern int mock_free_counter;

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

int	delete_function_counter;

void	increment_delete_function_counter(void *ptr)
{
	free(ptr);
	delete_function_counter++;
}

MU_TEST(test_ft_lstdelone_free_int_node)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	t_list *node;
	int *content;
	char	message[80];

	// ACT
	node = malloc(sizeof(t_list));
	content = malloc(sizeof(int));
	*content = 42;
	node->content = content;
	node->next = NULL;
	mock_free_counter_active = 1;
	mock_free_counter = 0;
	ft_lstdelone(node, free);
	mock_free_counter_active = 0;
	expected_result = 2;
	actual_result = mock_free_counter;
	snprintf(message, sizeof(message), "Expected %d memory allocations to be freed, but %d were not freed.\n", expected_result, expected_result - actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);
}

MU_TEST(test_ft_lstdelone_delete_int_node_content)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	t_list *node;
	int *content;
	char	message[80];

	// ACT
	node = malloc(sizeof(t_list));
	content = malloc(sizeof(int));
	*content = 42;
	node->content = content;
	node->next = NULL;
	delete_function_counter = 0;
	ft_lstdelone(node, increment_delete_function_counter);
	expected_result = 1;
	actual_result = delete_function_counter;
	snprintf(message, sizeof(message), "Expected delete function to be called %d times, but it was called %d times.\n", expected_result, actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);
}

MU_TEST(test_ft_lstdelone_null_node_pointer)
{
	int		expected_result;
	int		actual_result;

	// ACT & ASSERT
	expected_result = 1;
	actual_result = capture_segfault_ft_lstdelone(&ft_lstdelone, NULL, free);
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
