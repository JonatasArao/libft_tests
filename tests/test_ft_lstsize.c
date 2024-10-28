/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstsize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:09:43 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/28 15:02:15 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int	ft_lstsize(t_list *lst);

MU_TEST(test_ft_lstsize_one_node_list)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	t_list	list;
	int		list_value;

	// ACT
	list_value = 21;
	list.content = &list_value;
	list.next = NULL;
	expected_result = 1;
	actual_result = ft_lstsize(&list);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_lstsize_multiple_nodes)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
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
	expected_result = 3;
	actual_result = ft_lstsize(&first_node);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_lstsize_null_list)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	t_list	*list;

	// ACT
	list = NULL;
	expected_result = 0;
	actual_result = ft_lstsize(list);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_lstsize_test_suite)
{
	MU_RUN_TEST(test_ft_lstsize_one_node_list);
	MU_RUN_TEST(test_ft_lstsize_multiple_nodes);
	MU_RUN_TEST(test_ft_lstsize_null_list);
}

int	main(void) {
	MU_RUN_SUITE(ft_lstsize_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
