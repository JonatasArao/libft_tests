/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:09:43 by jarao-de          #+#    #+#             */
/*   Updated: 2024/11/01 14:42:44 by jarao-de         ###   ########.fr       */
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

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

extern int mock_malloc_memset_active;

extern int mock_malloc_failure_active;

extern int mock_malloc_failure_threshold;

extern int mock_malloc_counter_active;

extern int mock_malloc_counter;

extern int mock_free_failure_active;

extern int mock_free_counter_active;

extern int mock_free_counter;

int	capture_segfault_ft_lstmap(t_list *(*func)(t_list *, void *(*)(void *), void (*)(void *)), t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	pid_t pid = fork();
	if (pid == 0)
	{
		// Child process executes the test
		func(lst, f, del);
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

void	*double_int_number(void *number)
{
	int	*int_number;
	int	*new_number;

	int_number = (int *)number;
	new_number = malloc(sizeof(int));
	if (new_number == NULL)
		return (NULL);
	*new_number = *int_number * 2;
	return (new_number);
}

int	delete_function_counter;

void	increment_delete_function_counter(void *ptr)
{
	free(ptr);
	delete_function_counter++;
}

MU_TEST(test_ft_lstmap_single_node_list)
{
	// ARRANGE
	t_list	list;
	int		list_value;
	t_list	*mapped_list;
	int		expected_value;
	int		actual_value;

	// ACT
	list_value = 21;
	expected_value = 42;
	list.content = &list_value;
	list.next = NULL;
	mapped_list = ft_lstmap(&list, double_int_number, free);
	actual_value = *(int *)mapped_list->content;

	// ASSERT
	mu_assert_int_eq(expected_value, actual_value);

	// CLEANUP
	free(mapped_list);
}

MU_TEST(test_ft_lstmap_delete_int_single_node_content)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	t_list *node;
	t_list *mapped_node;
	int *content;
	char	message[80];

	// ACT
	node = malloc(sizeof(t_list));
	content = malloc(sizeof(int));
	*content = 42;
	node->content = content;
	node->next = NULL;
	mock_malloc_failure_active = 1;
	mock_malloc_failure_threshold = 2;
	delete_function_counter = 0;
	mapped_node = ft_lstmap(node, double_int_number, increment_delete_function_counter);
	mock_malloc_failure_active = 0;
	expected_result = 1;
	actual_result = delete_function_counter;
	snprintf(message, sizeof(message), "Expected delete function to be called %d times, but it was called %d times.\n", expected_result, actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);

	// CLEANUP
	free(content);
	free(node);
}

MU_TEST(test_ft_lstmap_multiple_nodes)
{
	// ARRANGE
	t_list	first_node;
	t_list	second_node;
	t_list	third_node;
	int		first_value;
	int		second_value;
	int		third_value;
	t_list	*mapped_list;
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
	mapped_list = ft_lstmap(&first_node, double_int_number, free);
	actual_first_value = *(int *)mapped_list->content;
	actual_second_value = *(int *)mapped_list->next->content;
	actual_third_value = *(int *)mapped_list->next->next->content;

	// ASSERT
	mu_assert_int_eq(expected_first_value, actual_first_value);
	mu_assert_int_eq(expected_second_value, actual_second_value);
	mu_assert_int_eq(expected_third_value, actual_third_value);

	// CLEANUP
	free(mapped_list->next->next);
	free(mapped_list->next);
	free(mapped_list);
}

MU_TEST(test_ft_lstmap_free_int_multiple_nodes)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	t_list	*first_node;
	t_list	*second_node;
	t_list	*third_node;
	int		*first_value;
	int		*second_value;
	int		*third_value;
	char	message[80];

	// ACT
	first_node = malloc(sizeof(t_list));
	second_node = malloc(sizeof(t_list));
	third_node = malloc(sizeof(t_list));
	first_value = malloc(sizeof(int));
	second_value = malloc(sizeof(int));
	third_value = malloc(sizeof(int));
	*first_value = 24;
	first_node->content = first_value;
	first_node->next = second_node;
	*second_value = 84;
	second_node->content = second_value;
	second_node->next = third_node;
	*third_value = 42;
	third_node->content = third_value;
	third_node->next = NULL;
	mock_malloc_failure_active = 1;
	mock_malloc_failure_threshold = 6;
	mock_malloc_counter_active = 1;
	mock_malloc_counter = 0;
	mock_free_counter_active = 1;
	mock_free_counter = 0;
	ft_lstmap(first_node, double_int_number, free);
	mock_malloc_counter_active = 0;
	mock_free_counter_active = 0;
	mock_malloc_failure_active = 0;
	expected_result = mock_malloc_counter;
	actual_result = mock_free_counter;
	snprintf(message, sizeof(message), "Expected %d memory allocations to be freed, but %d were not freed.\n", expected_result, expected_result - actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);

	// CLEANUP
	free(first_value);
	free(second_value);
	free(third_value);
	free(first_node);
	free(second_node);
	free(third_node);
}

MU_TEST(test_ft_lstmap_delete_int_multiple_nodes_content)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	t_list	*mapped_node;
	t_list	*first_node;
	t_list	*second_node;
	t_list	*third_node;
	int		*first_value;
	int		*second_value;
	int		*third_value;
	char	message[80];

	// ACT
	first_node = malloc(sizeof(t_list));
	second_node = malloc(sizeof(t_list));
	third_node = malloc(sizeof(t_list));
	first_value = malloc(sizeof(int));
	second_value = malloc(sizeof(int));
	third_value = malloc(sizeof(int));
	*first_value = 24;
	first_node->content = first_value;
	first_node->next = second_node;
	*second_value = 84;
	second_node->content = second_value;
	second_node->next = third_node;
	*third_value = 42;
	third_node->content = third_value;
	third_node->next = NULL;
	mock_malloc_failure_active = 1;
	mock_malloc_failure_threshold = 6;
	delete_function_counter = 0;
	mapped_node = ft_lstmap(first_node, double_int_number, increment_delete_function_counter);
	mock_malloc_failure_active = 0;
	expected_result = 3;
	actual_result = delete_function_counter;
	snprintf(message, sizeof(message), "Expected delete function to be called %d times, but it was called %d times.\n", expected_result, actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);

	// CLEANUP
	free(first_value);
	free(second_value);
	free(third_value);
	free(first_node);
	free(second_node);
	free(third_node);
}

MU_TEST(test_ft_lstmap_null_list)
{
	// ARRANGE
	t_list	*list;

	// ACT
	list = NULL;
	ft_lstmap(list, double_int_number, free);

	// ASSERT
	mu_assert(NULL == list, "List should remain NULL");
}

MU_TEST(test_ft_lstmap_null_node_pointer)
{
	int		expected_result;
	int		actual_result;

	// ACT & ASSERT
	expected_result = 0;
	actual_result = capture_segfault_ft_lstmap(&ft_lstmap, NULL, double_int_number, free);
	mu_assert(expected_result == actual_result, "Function should not cause a segmentation fault.");
}

MU_TEST(test_ft_lstmap_null_function_pointer)
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
	expected_result = 0;
	actual_result = capture_segfault_ft_lstmap(&ft_lstmap, node, NULL, free);
	mu_assert(expected_result == actual_result, "Function should not cause a segmentation fault.");

	// CLEANUP
	free(content);
	free(node);
}

MU_TEST(test_ft_lstmap_null_del_function_pointer)
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
	expected_result = 0;
	actual_result = capture_segfault_ft_lstmap(&ft_lstmap, node, double_int_number, NULL);
	mu_assert(expected_result == actual_result, "Function should not cause a segmentation fault.");

	// CLEANUP
	free(content);
	free(node);
}

MU_TEST(test_ft_lstmap_first_malloc_fail)
{
	// ARRANGE
	t_list	first_node;
	t_list	second_node;
	t_list	third_node;
	int		first_value;
	int		second_value;
	int		third_value;
	t_list	*expected_result;
	t_list	*actual_result;
	int		segfaulted;

	// ACT
	first_value = 24;
	first_node.content = &first_value;
	first_node.next = &second_node;
	second_value = 84;
	second_node.content = &second_value;
	second_node.next = &third_node;
	third_value = 42;
	third_node.content = &third_value;
	third_node.next = NULL;
	expected_result = NULL;
	mock_malloc_failure_active = 1;
	mock_malloc_failure_threshold = 1;
	segfaulted = capture_segfault_ft_lstmap(&ft_lstmap, &first_node, double_int_number, free);
	if (!segfaulted)
		actual_result = ft_lstmap(&first_node, double_int_number, free);
	mock_malloc_failure_active = 0;

	// ASSERT
	if (!segfaulted)
	{
		mu_assert(actual_result == expected_result, "Expected NULL pointer");
	}
	else
		mu_fail("Function should not cause a segmentation fault.");
}

MU_TEST(test_ft_lstmap_second_malloc_fail)
{
	// ARRANGE
	t_list	first_node;
	t_list	second_node;
	t_list	third_node;
	int		first_value;
	int		second_value;
	int		third_value;
	t_list	*expected_result;
	t_list	*actual_result;
	int		segfaulted;

	// ACT
	first_value = 24;
	first_node.content = &first_value;
	first_node.next = &second_node;
	second_value = 84;
	second_node.content = &second_value;
	second_node.next = &third_node;
	third_value = 42;
	third_node.content = &third_value;
	third_node.next = NULL;
	expected_result = NULL;
	mock_malloc_failure_active = 1;
	mock_malloc_failure_threshold = 2;
	segfaulted = capture_segfault_ft_lstmap(&ft_lstmap, &first_node, double_int_number, free);
	if (!segfaulted)
		actual_result = ft_lstmap(&first_node, double_int_number, free);
	mock_malloc_failure_active = 0;

	// ASSERT
	if (!segfaulted)
	{
		mu_assert(actual_result == expected_result, "Expected NULL pointer");
	}
	else
		mu_fail("Function should not cause a segmentation fault.");
}

MU_TEST(test_ft_lstmap_third_malloc_fail)
{
	// ARRANGE
	t_list	first_node;
	t_list	second_node;
	t_list	third_node;
	int		first_value;
	int		second_value;
	int		third_value;
	t_list	*expected_result;
	t_list	*actual_result;
	int		segfaulted;

	// ACT
	first_value = 24;
	first_node.content = &first_value;
	first_node.next = &second_node;
	second_value = 84;
	second_node.content = &second_value;
	second_node.next = &third_node;
	third_value = 42;
	third_node.content = &third_value;
	third_node.next = NULL;
	expected_result = NULL;
	mock_malloc_failure_active = 1;
	mock_malloc_failure_threshold = 3;
	segfaulted = capture_segfault_ft_lstmap(&ft_lstmap, &first_node, double_int_number, free);
	if (!segfaulted)
		actual_result = ft_lstmap(&first_node, double_int_number, free);
	mock_malloc_failure_active = 0;

	// ASSERT
	if (!segfaulted)
	{
		mu_assert(actual_result == expected_result, "Expected NULL pointer");
	}
	else
		mu_fail("Function should not cause a segmentation fault.");
}

MU_TEST_SUITE(ft_lstmap_test_suite)
{
	MU_RUN_TEST(test_ft_lstmap_single_node_list);
	MU_RUN_TEST(test_ft_lstmap_delete_int_single_node_content);
	MU_RUN_TEST(test_ft_lstmap_multiple_nodes);
	MU_RUN_TEST(test_ft_lstmap_free_int_multiple_nodes);
	MU_RUN_TEST(test_ft_lstmap_delete_int_multiple_nodes_content);
	MU_RUN_TEST(test_ft_lstmap_null_list);
	MU_RUN_TEST(test_ft_lstmap_null_node_pointer);
	MU_RUN_TEST(test_ft_lstmap_null_function_pointer);
	MU_RUN_TEST(test_ft_lstmap_null_del_function_pointer);
	MU_RUN_TEST(test_ft_lstmap_first_malloc_fail);
	MU_RUN_TEST(test_ft_lstmap_second_malloc_fail);
	MU_RUN_TEST(test_ft_lstmap_third_malloc_fail);
}

int	main(void) {
	mock_malloc_memset_active = 1;
	MU_RUN_SUITE(ft_lstmap_test_suite);
	mock_malloc_memset_active = 0;
	MU_REPORT();
	return MU_EXIT_CODE;
}
