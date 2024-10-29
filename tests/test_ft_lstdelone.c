/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstdelone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:17:27 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/29 15:42:34 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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

MU_TEST(test_ft_lstdelone_free_string_node)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	t_list	*node;
	char	*content;

	// ACT
	node = malloc(sizeof(t_list));
	content = strdup("42");
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

MU_TEST(test_ft_lstdelone_delete_string_node_content)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	t_list	*node;
	char	*content;

	// ACT
	node = malloc(sizeof(t_list));
	content = strdup("42");
	node->content = content;
	node->next = NULL;
	mock_free_failure_active = 1;
	ft_lstdelone(node, &reset_string_pointer);
	mock_free_failure_active = 0;
	expected_result = strdup("");
	actual_result = (char *)node->content;

	// ASSERT
	mu_assert(strcmp(expected_result, actual_result) == 0, "String content was not properly deleted");

	// CLEANUP
	free(expected_result);
	free(content);
	free(node);
}

MU_TEST(test_ft_lstdelone_free_null_node)
{
	// ARRANGE
	t_list *node = NULL;

	// ACT
	ft_lstdelone(node, &do_nothing);

	// ASSERT
	mu_assert(node == NULL, "Node should remain NULL");
}

MU_TEST_SUITE(ft_lstdelone_test_suite)
{
	MU_RUN_TEST(test_ft_lstdelone_free_int_node);
	MU_RUN_TEST(test_ft_lstdelone_delete_int_node_content);
	MU_RUN_TEST(test_ft_lstdelone_free_string_node);
	MU_RUN_TEST(test_ft_lstdelone_delete_string_node_content);
	MU_RUN_TEST(test_ft_lstdelone_free_null_node);
}

int	main(void) {
	MU_RUN_SUITE(ft_lstdelone_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
