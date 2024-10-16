/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:07:17 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/16 15:40:37 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

MU_TEST(test_ft_strlcpy_forty_two_assignment)
{
	// ARRANGE
	char	expected_result[3];
	char	actual_result[3];

	// ACT
	strcpy(expected_result, "42");
	ft_strlcpy(actual_result, "42 School", 3);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlcpy_forty_two_return)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	char	buffer[3];

	// ACT
	expected_result = 9;
	actual_result = ft_strlcpy(buffer, "42 School", 3);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlcpy_forty_two_zero_size_assignment)
{
	// ARRANGE
	char	expected_result[1];
	char	actual_result[1];

	// ACT
	strcpy(expected_result, "");
	ft_strlcpy(actual_result, "42 School", 0);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlcpy_forty_two_zero_size_return)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	char	buffer[1];

	// ACT
	expected_result = 9;
	actual_result = ft_strlcpy(buffer, "42 School", 0);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}
MU_TEST(test_ft_strlcpy_buffer_larger_than_source_assignment)
{
	// ARRANGE
	char	expected_result[20];
	char	actual_result[20];

	// ACT
	strcpy(expected_result, "42 School");
	ft_strlcpy(actual_result, "42 School", 20);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlcpy_buffer_larger_than_source_return)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	char	buffer[20];

	// ACT
	expected_result = 9;
	actual_result = ft_strlcpy(buffer, "42 School", 20);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlcpy_buffer_smaller_than_source_assignment)
{
	// ARRANGE
	char	expected_result[5];
	char	actual_result[5];

	// ACT
	strcpy(expected_result, "42 S");
	ft_strlcpy(actual_result, "42 School", 5);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlcpy_buffer_smaller_than_source_return)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	char	buffer[5];

	// ACT
	expected_result = 9;
	actual_result = ft_strlcpy(buffer, "42 School", 5);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlcpy_buffer_exact_size_assignment)
{
	// ARRANGE
	char	expected_result[10];
	char	actual_result[10];

	// ACT
	strcpy(expected_result, "42 School");
	ft_strlcpy(actual_result, "42 School", 10);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlcpy_buffer_exact_size_return)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	char	buffer[10];

	// ACT
	expected_result = 9;
	actual_result = ft_strlcpy(buffer, "42 School", 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlcpy_empty_source_assignment)
{
	// ARRANGE
	char	expected_result[10];
	char	actual_result[10];

	// ACT
	strcpy(expected_result, "");
	ft_strlcpy(actual_result, "", 10);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlcpy_empty_source_return)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	char	buffer[10];

	// ACT
	expected_result = 0;
	actual_result = ft_strlcpy(buffer, "", 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_strlcpy_test_suite)
{
	MU_RUN_TEST(test_ft_strlcpy_forty_two_assignment);
	MU_RUN_TEST(test_ft_strlcpy_forty_two_return);
	MU_RUN_TEST(test_ft_strlcpy_forty_two_zero_size_assignment);
	MU_RUN_TEST(test_ft_strlcpy_forty_two_zero_size_return);
	MU_RUN_TEST(test_ft_strlcpy_buffer_larger_than_source_assignment);
	MU_RUN_TEST(test_ft_strlcpy_buffer_larger_than_source_return);
	MU_RUN_TEST(test_ft_strlcpy_buffer_smaller_than_source_assignment);
	MU_RUN_TEST(test_ft_strlcpy_buffer_smaller_than_source_return);
	MU_RUN_TEST(test_ft_strlcpy_buffer_exact_size_assignment);
	MU_RUN_TEST(test_ft_strlcpy_buffer_exact_size_return);
	MU_RUN_TEST(test_ft_strlcpy_empty_source_assignment);
	MU_RUN_TEST(test_ft_strlcpy_empty_source_return);
}

int	main(void) {
	MU_RUN_SUITE(ft_strlcpy_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
