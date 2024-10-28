/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstadd_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:35:34 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/28 15:52:21 by jarao-de         ###   ########.fr       */
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

void	ft_lstadd_back(t_list **lst, t_list *new);

int capture_segfault_ft_lstadd_back(void (*f)(t_list **, t_list *), t_list **lst, t_list *new)
{
	pid_t pid = fork();
	if (pid == 0)
	{
		// Child process executes the test
		f(lst, new);
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

MU_TEST(test_ft_lstadd_back_null_list)
{
	// ARRANGE
	t_list	*actual_result;
	t_list	new_list;
	int		new_list_value;

	// ACT
	actual_result = NULL;
	new_list_value = 42;
	new_list.content = &new_list_value;
	new_list.next = NULL;
	ft_lstadd_back(&actual_result, &new_list);

	// ASSERT
	mu_assert(actual_result == &new_list, "The new node should be the head of the list");
	mu_assert(actual_result->content == &new_list_value, "The content of the new node should be correct");
	mu_assert(actual_result->next == NULL, "The next of the new node should be NULL");
}

MU_TEST(test_ft_lstadd_back_existing_list)
{
	// ARRANGE
	t_list	*actual_result;
	t_list	existing_node;
	t_list	new_node;
	int		existing_value;
	int		new_value;

	// ACT
	existing_value = 21;
	existing_node.content = &existing_value;
	existing_node.next = NULL;
	actual_result = &existing_node;
	new_value = 42;
	new_node.content = &new_value;
	new_node.next = NULL;
	ft_lstadd_back(&actual_result, &new_node);

	// ASSERT
	mu_assert(actual_result == &existing_node, "The head of the list should remain the same");
	mu_assert(actual_result->next == &new_node, "The new node should be added at the end of the list");
	mu_assert(actual_result->next->content == &new_value, "The content of the new node should be correct");
	mu_assert(actual_result->next->next == NULL, "The next of the new node should be NULL");
}

MU_TEST(test_ft_lstadd_back_multiple_nodes)
{
	// ARRANGE
	t_list	*actual_result;
	t_list	first_node;
	t_list	second_node;
	t_list	new_node;
	int		first_value;
	int		second_value;
	int		new_value;

	// ACT
	first_value = 24;
	first_node.content = &first_value;
	first_node.next = NULL;
	second_value = 84;
	second_node.content = &second_value;
	second_node.next = &first_node;
	actual_result = &second_node;
	new_value = 42;
	new_node.content = &new_value;
	new_node.next = NULL;
	ft_lstadd_back(&actual_result, &new_node);

	// ASSERT
	mu_assert(actual_result == &second_node, "The head of the list should remain the same");
	mu_assert(actual_result->next == &first_node, "The second node should remain the same");
	mu_assert(actual_result->next->next == &new_node, "The new node should be added at the end of the list");
	mu_assert(actual_result->next->next->content == &new_value, "The content of the new node should be correct");
	mu_assert(actual_result->next->next->next == NULL, "The next of the new node should be NULL");
}

MU_TEST(test_ft_lstadd_back_with_null_content)
{
	// ARRANGE
	t_list	*actual_result;
	t_list	existing_node;
	t_list	new_node;
	int		existing_value;

	// ACT
	existing_value = 21;
	existing_node.content = &existing_value;
	existing_node.next = NULL;
	actual_result = &existing_node;
	new_node.content = NULL;
	new_node.next = NULL;
	ft_lstadd_back(&actual_result, &new_node);

	// ASSERT
	mu_assert(actual_result == &existing_node, "The head of the list should remain the same");
	mu_assert(actual_result->next == &new_node, "The new node should be added at the end of the list");
	mu_assert(actual_result->next->content == NULL, "The content of the new node should be NULL");
	mu_assert(actual_result->next->next == NULL, "The next of the new node should be NULL");
}

MU_TEST(test_ft_lstadd_back_null_new_node)
{
	// ARRANGE
	t_list	*actual_result;
	t_list	existing_node;
	int		existing_value;
	int		segfaulted;

	// ACT
	existing_value = 21;
	existing_node.content = &existing_value;
	existing_node.next = NULL;
	actual_result = &existing_node;
	segfaulted = capture_segfault_ft_lstadd_back(&ft_lstadd_back, &actual_result, NULL);
	if (!segfaulted)
		ft_lstadd_back(&actual_result, NULL);

	// ASSERT
	if (!segfaulted)
	{
		mu_assert(actual_result == &existing_node, "The list should remain unchanged when new node is NULL");
		mu_assert(actual_result->content == &existing_value, "The content of the existing node should be correct");
		mu_assert(actual_result->next == NULL, "The next of the existing node should be NULL");
	}
	else
		mu_fail("Function should not cause a segmentation fault.");
}

MU_TEST_SUITE(ft_lstadd_back_test_suite)
{
	MU_RUN_TEST(test_ft_lstadd_back_null_list);
	MU_RUN_TEST(test_ft_lstadd_back_existing_list);
	MU_RUN_TEST(test_ft_lstadd_back_multiple_nodes);
	MU_RUN_TEST(test_ft_lstadd_back_with_null_content);
	MU_RUN_TEST(test_ft_lstadd_back_null_new_node);
}

int	main(void) {
	MU_RUN_SUITE(ft_lstadd_back_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}

