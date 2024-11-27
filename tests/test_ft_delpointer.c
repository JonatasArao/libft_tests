/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_delpointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:37:57 by jarao-de          #+#    #+#             */
/*   Updated: 2024/11/27 11:44:04 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minunit.h"

void	*ft_delpointer(void **ptr);

extern int mock_free_counter_active;

extern int mock_free_counter;

MU_TEST(test_ft_delpointer)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	void	*ptr;
	char	message[80];

	// Allocate memory for the pointer
	ptr = malloc(10);

	// ACT
	mock_free_counter_active = 1;
	mock_free_counter = 0;
	actual_result = ft_delpointer(&ptr);
	mock_free_counter_active = 0;
	expected_result = NULL;

	// ASSERT
	snprintf(message, sizeof(message), "Expected return value to be NULL, but it was not.");
	mu_assert(expected_result == actual_result, message);
	mu_assert(ptr == NULL, "Expected pointer to be NULL, but it was not.");
	mu_assert(mock_free_counter == 1, "Expected memory allocation to be freed, but it was not.");
}

MU_TEST(test_ft_delpointer_null_pointer)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	void	*ptr = NULL;
	char	message[80];

	// ACT
	mock_free_counter_active = 1;
	mock_free_counter = 0;
	actual_result = ft_delpointer(&ptr);
	mock_free_counter_active = 0;
	expected_result = NULL;

	// ASSERT
	snprintf(message, sizeof(message), "Expected return value to be NULL, but it was not.");
	mu_assert(expected_result == actual_result, message);
	mu_assert(ptr == NULL, "Expected pointer to be NULL, but it was not.");
	mu_assert(mock_free_counter == 0, "Expected no memory allocations to be freed, but some were.");
}

MU_TEST_SUITE(ft_delpointer_test_suite)
{
	MU_RUN_TEST(test_ft_delpointer);
	MU_RUN_TEST(test_ft_delpointer_null_pointer);
}

int	main(void) {
	MU_RUN_SUITE(ft_delpointer_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
