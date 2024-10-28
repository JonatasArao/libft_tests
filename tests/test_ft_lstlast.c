/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstlast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:00:45 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/28 15:08:16 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstlast(t_list *lst);

MU_TEST(test_ft_lstlast_one_node_list)
{
	// ARRANGE
	t_list	*expected_result;
	t_list	*actual_result;
	t_list	list;
	int		list_value;

	// ACT
	list_value = 21;
	list.content = &list_value;
	list.next = NULL;
	expected_result = &list;
	actual_result = ft_lstlast(&list);

	// ASSERT
	mu_assert(actual_result == expected_result, "The new node should be the head of the list");
	mu_assert(actual_result->content == expected_result->content, "The content of the new node should be correct");
	mu_assert(actual_result->next == NULL, "The next of the new node should be NULL");
}

MU_TEST(test_ft_lstlast_multiple_nodes)
{
	// ARRANGE
	t_list	*expected_result;
	t_list	*actual_result;
	t_list	first_node;
	t_list	second_node;
	t_list	third_node;
	int		first_value;
	int		second_value;
	int		third_value;

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
	expected_result = &third_node;
	actual_result = ft_lstlast(&first_node);

	// ASSERT
	mu_assert(actual_result == expected_result, "The last node should be the third node");
	mu_assert(actual_result->content == expected_result->content, "The content of the last node should be correct");
	mu_assert(actual_result->next == NULL, "The next of the last node should be NULL");
}

MU_TEST(test_ft_lstlast_null_list)
{
	// ARRANGE
	t_list	*expected_result;
	t_list	*actual_result;
	t_list	*list;

	// ACT
	list = NULL;
	expected_result = NULL;
	actual_result = ft_lstlast(list);

	// ASSERT
	mu_assert(actual_result == expected_result, "The result should be NULL for an empty list");
}

MU_TEST_SUITE(ft_lstlast_test_suite)
{
	MU_RUN_TEST(test_ft_lstlast_one_node_list);
	MU_RUN_TEST(test_ft_lstlast_multiple_nodes);
	MU_RUN_TEST(test_ft_lstlast_null_list);
}

int	main(void) {
	MU_RUN_SUITE(ft_lstlast_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
