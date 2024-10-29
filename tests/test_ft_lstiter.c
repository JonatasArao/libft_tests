/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstiter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:09:43 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/29 18:00:08 by jarao-de         ###   ########.fr       */
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

void	ft_lstiter(t_list *lst, void (*f)(void *));

int	capture_segfault_ft_lstiter(void (*func)(t_list *, void (*)(void *)), t_list *lst, void (*f)(void *))
{
	pid_t pid = fork();
	if (pid == 0)
	{
		// Child process executes the test
		func(lst, f);
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

void double_int_number(void *number)
{
	int	*int_number;

	int_number = (int *)number;
	*int_number *= 2;
}

MU_TEST(test_ft_lstiter_one_node_list)
{
	// ARRANGE
	t_list	list;
	int		list_value;
	int		expected_value;
	int		actual_value;

	// ACT
	list_value = 21;
	expected_value = 42;
	list.content = &list_value;
	list.next = NULL;
	ft_lstiter(&list, double_int_number);
	actual_value = list_value;

	// ASSERT
	mu_assert_int_eq(expected_value, actual_value);
}

MU_TEST(test_ft_lstiter_multiple_nodes)
{
	// ARRANGE
	t_list	first_node;
	t_list	second_node;
	t_list	third_node;
	int		first_value;
	int		second_value;
	int		third_value;
	int		expected_first_value;
	int		expected_second_value;
	int		expected_third_value;
	int		actual_first_value;
	int		actual_second_value;
	int		actual_third_value;

	// ACT
	first_value = 24;
	expected_first_value = 48;
	first_node.content = &first_value;
	first_node.next = &second_node;
	second_value = 84;
	expected_second_value = 168;
	second_node.content = &second_value;
	second_node.next = &third_node;
	third_value = 42;
	expected_third_value = 84;
	third_node.content = &third_value;
	third_node.next = NULL;
	ft_lstiter(&first_node, double_int_number);
	actual_first_value = first_value;
	actual_second_value = second_value;
	actual_third_value = third_value;

	// ASSERT
	mu_assert_int_eq(expected_first_value, actual_first_value);
	mu_assert_int_eq(expected_second_value, actual_second_value);
	mu_assert_int_eq(expected_third_value, actual_third_value);
}

MU_TEST(test_ft_lstiter_null_list)
{
	// ARRANGE
	t_list	*list;

	// ACT
	list = NULL;
	ft_lstiter(list, double_int_number);

	// ASSERT
	mu_assert(NULL == list, "List should remain NULL");
}

MU_TEST(test_ft_lstiter_null_node_pointer)
{
	int		expected_result;
	int		actual_result;

	// ACT & ASSERT
	expected_result = 0;
	actual_result = capture_segfault_ft_lstiter(&ft_lstiter, NULL, double_int_number);
	mu_assert(expected_result == actual_result, "Function should not cause a segmentation fault.");
}

MU_TEST(test_ft_lstiter_null_function_pointer)
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
	actual_result = capture_segfault_ft_lstiter(&ft_lstiter, node, NULL);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");

	// CLEANUP
	free(content);
	free(node);
}

MU_TEST_SUITE(ft_lstiter_test_suite)
{
	MU_RUN_TEST(test_ft_lstiter_one_node_list);
	MU_RUN_TEST(test_ft_lstiter_multiple_nodes);
	MU_RUN_TEST(test_ft_lstiter_null_list);
	MU_RUN_TEST(test_ft_lstiter_null_node_pointer);
	MU_RUN_TEST(test_ft_lstiter_null_function_pointer);
}

int	main(void) {
	MU_RUN_SUITE(ft_lstiter_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
