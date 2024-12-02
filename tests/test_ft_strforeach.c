/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strforeach.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:59:35 by jarao-de          #+#    #+#             */
/*   Updated: 2024/12/02 13:45:22 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minunit.h"

void	ft_strforeach(char *tab, int (*f)(int));

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

MU_TEST(test_ft_strforeach_null_pointer)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	expected_result = NULL;
	actual_result = NULL;

	// ACT
	ft_strforeach(actual_result, ft_toupper);

	// ASSERT
	mu_assert(expected_result == actual_result, "The tab should remain NULL");
}

MU_TEST(test_ft_strforeach_no_change)
{
	// ARRANGE
	char	expected_result[6];
	char	actual_result[6];

	strcpy(actual_result, "abcde");
	strcpy(expected_result, "abcde");

	// ACT
	ft_strforeach(actual_result, ft_tolower);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strforeach_all_lowercase)
{
	// ARRANGE
	char	expected_result[6];
	char	actual_result[6];

	strcpy(actual_result, "abcde");
	strcpy(expected_result, "abcde");

	// ACT
	ft_strforeach(actual_result, ft_tolower);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strforeach_mixed_case_to_lower)
{
	// ARRANGE
	char	expected_result[6];
	char	actual_result[6];

	strcpy(actual_result, "aBcDe");
	strcpy(expected_result, "abcde");

	// ACT
	ft_strforeach(actual_result, ft_tolower);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strforeach_all_uppercase_to_upper)
{
	// ARRANGE
	char	expected_result[6];
	char	actual_result[6];

	strcpy(actual_result, "ABCDE");
	strcpy(expected_result, "ABCDE");

	// ACT
	ft_strforeach(actual_result, ft_toupper);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strforeach_numbers_to_lower)
{
	// ARRANGE
	char	expected_result[6];
	char	actual_result[6];

	strcpy(actual_result, "12345");
	strcpy(expected_result, "12345");

	// ACT
	ft_strforeach(actual_result, ft_tolower);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strforeach_special_characters_to_lower)
{
	// ARRANGE
	char	expected_result[6];
	char	actual_result[6];

	strcpy(actual_result, "!@#$%");
	strcpy(expected_result, "!@#$%");

	// ACT
	ft_strforeach(actual_result, ft_tolower);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strforeach_mixed_characters_to_lower)
{
	// ARRANGE
	char	expected_result[6];
	char	actual_result[6];

	strcpy(actual_result, "A1b2C");
	strcpy(expected_result, "a1b2c");

	// ACT
	ft_strforeach(actual_result, ft_tolower);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_strforeach_test_suite)
{
	MU_RUN_TEST(test_ft_strforeach_null_pointer);
	MU_RUN_TEST(test_ft_strforeach_no_change);
	MU_RUN_TEST(test_ft_strforeach_all_lowercase);
	MU_RUN_TEST(test_ft_strforeach_mixed_case_to_lower);
	MU_RUN_TEST(test_ft_strforeach_all_uppercase_to_upper);
	MU_RUN_TEST(test_ft_strforeach_numbers_to_lower);
	MU_RUN_TEST(test_ft_strforeach_special_characters_to_lower);
	MU_RUN_TEST(test_ft_strforeach_mixed_characters_to_lower);
}

int	main(void) {
	MU_RUN_SUITE(ft_strforeach_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
