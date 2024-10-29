/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstclear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:17:27 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/29 17:34:49 by jarao-de         ###   ########.fr       */
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

void	ft_lstclear(t_list **lst, void (*del)(void *));

extern int mock_free_failure_active;

extern int mock_free_memset_active;

extern int mock_free_memset_size;

int	capture_segfault_ft_lstclear(void (*f)(t_list **, void (*)(void *)), t_list **lst, void (*del)(void *))
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

void	reset_string_pointer(void *ptr)
{
	char *string_ptr;

	string_ptr = (char *)ptr;
	while (*string_ptr)
		*string_ptr++ = '\0';
}

void	do_nothing(void *ptr)
{
	(void) ptr;
}

MU_TEST(test_ft_lstclear_free_int_single_node)
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
	actual_result = node;
	mock_free_memset_active = 1;
	mock_free_memset_size = sizeof(t_list);
	ft_lstclear(&node, &do_nothing);
	mock_free_memset_active = 0;
	mock_free_memset_size = 0;
	expected_result = malloc(sizeof(t_list));
	memset(expected_result, 0xFF, sizeof(t_list));

	// ASSERT
	mu_assert(memcmp(expected_result, actual_result, sizeof(t_list)) == 0, "Node memory was not properly freed");

	// CLEANUP
	free(expected_result);
	free(content);
	free(node);
}

MU_TEST(test_ft_lstclear_delete_int_single_node_content)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	t_list *node;
	t_list *node_backup;
	int *content;

	// ACT
	node = malloc(sizeof(t_list));
	content = malloc(sizeof(int));
	*content = 42;
	node->content = content;
	node->next = NULL;
	node_backup = node;
	mock_free_failure_active = 1;
	ft_lstclear(&node, &reset_int_pointer);
	mock_free_failure_active = 0;
	expected_result = 0;
	actual_result = *(int *)node_backup->content;

	// ASSERT
	mu_assert(expected_result == actual_result, "Integer content was not properly deleted");

	// CLEANUP
	free(content);
	free(node);
}

MU_TEST(test_ft_lstclear_free_multiple_single_node)
{
	// ARRANGE
	void	*expected_result;
	t_list	*first_node;
	t_list	*second_node;
	t_list	*third_node;
	int		*first_value;
	int		*second_value;
	int		*third_value;
	void	*mem_second_node;
	void	*mem_third_node;

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
	mem_second_node = second_node;
	mem_third_node = third_node;
	mock_free_memset_active = 1;
	mock_free_memset_size = sizeof(t_list);
	ft_lstclear(&second_node, &do_nothing);
	mock_free_memset_active = 0;
	mock_free_memset_size = 0;
	expected_result = malloc(sizeof(t_list));
	memset(expected_result, 0xFF, sizeof(t_list));

	// ASSERT
	mu_assert(memcmp(expected_result, mem_second_node, sizeof(t_list)) == 0, "Second node memory was not properly freed");
	mu_assert(memcmp(expected_result, mem_third_node, sizeof(t_list)) == 0, "Third node memory was not properly freed");

	// CLEANUP
	free(expected_result);
	free(first_value);
	free(second_value);
	free(third_value);
	free(first_node);
	free(second_node);
	free(third_node);
}

MU_TEST(test_ft_lstclear_delete_int_multiple_node_content)
{
	// ARRANGE
	int		expected_result;
	t_list	*first_node;
	t_list	*second_node;
	t_list	*third_node;
	t_list	*second_node_backup;
	t_list	*third_node_backup;
	int		*first_value;
	int		*second_value;
	int		*third_value;

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
	second_node_backup = second_node;
	third_node_backup = third_node;
	mock_free_failure_active = 1;
	ft_lstclear(&second_node, &reset_int_pointer);
	mock_free_failure_active = 0;
	expected_result = 0;

	// ASSERT
	mu_assert(expected_result == *(int *)second_node_backup->content, "Integer content of second node was not properly deleted");
	mu_assert(expected_result == *(int *)third_node_backup->content, "Integer content of third node was not properly deleted");

	// CLEANUP
	free(second_value);
	free(third_value);
	free(second_node);
	free(third_node);
}

MU_TEST(test_ft_lstclear_null_node_pointer)
{
	int		expected_result;
	int		actual_result;

	// ACT & ASSERT
	expected_result = 1;
	actual_result = capture_segfault_ft_lstclear(&ft_lstclear, NULL, &do_nothing);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST(test_ft_lstclear_null_function_pointer)
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
	actual_result = capture_segfault_ft_lstclear(&ft_lstclear, &node, NULL);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");

	// CLEANUP
	free(content);
	free(node);
}

MU_TEST_SUITE(ft_lstclear_test_suite)
{
	MU_RUN_TEST(test_ft_lstclear_free_int_single_node);
	MU_RUN_TEST(test_ft_lstclear_delete_int_single_node_content);
	MU_RUN_TEST(test_ft_lstclear_free_multiple_single_node);
	MU_RUN_TEST(test_ft_lstclear_delete_int_multiple_node_content);
	MU_RUN_TEST(test_ft_lstclear_null_node_pointer);
	MU_RUN_TEST(test_ft_lstclear_null_function_pointer);
}

int	main(void) {
	MU_RUN_SUITE(ft_lstclear_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
