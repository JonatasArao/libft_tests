/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:31:05 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/15 11:12:30 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minunit.h"

char	*ft_strdup(const char *src);

MU_TEST(test_ft_strdup_forty_two)
{
	// ARRANGE
	char	expected_result[3];
	char	*actual_result;

	// ACT
	strcpy(expected_result, "42");
	actual_result = ft_strdup("42");

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
}

MU_TEST(test_ft_strdup_empty_string)
{
	// ARRANGE
	char	expected_result[1];
	char	*actual_result;

	// ACT
	strcpy(expected_result, "");
	actual_result = ft_strdup("");

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
}

MU_TEST(test_ft_strdup_long_string)
{
	// ARRANGE
	char	expected_result[59];
	char	*actual_result;

	// ACT
	strcpy(expected_result, "This is a very long string to test the ft_strdup function.");
	actual_result = ft_strdup("This is a very long string to test the ft_strdup function.");

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
}

MU_TEST(test_ft_strdup_special_characters)
{
	// ARRANGE
	char	expected_result[9];
	char	*actual_result;

	// ACT
	strcpy(expected_result, "Hello\n\t!");
	actual_result = ft_strdup("Hello\n\t!");

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
}

MU_TEST(test_ft_strdup_spaces)
{
	// ARRANGE
	char	expected_result[4];
	char	*actual_result;

	// ACT
	strcpy(expected_result, "   ");
	actual_result = ft_strdup("   ");

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
}

MU_TEST(test_ft_strdup_unicode_string)
{
	// ARRANGE
	char	expected_result[16];
	char	*actual_result;

	// ACT
	strcpy(expected_result, "こんにちは");
	actual_result = ft_strdup("こんにちは");

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
}

MU_TEST(test_ft_strdup_escape_characters)
{
	// ARRANGE
	char	expected_result[14];
	char	*actual_result;

	// ACT
	strcpy(expected_result, "Hello\nWorld\t!");
	actual_result = ft_strdup("Hello\nWorld\t!");

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
}

MU_TEST(test_ft_strdup_very_long_string)
{
	// ARRANGE
	char	expected_result[10000];
	char	*actual_result;

	// ACT
	memset(expected_result, 'a', 9999);
	expected_result[9999] = '\0';
	actual_result = ft_strdup(expected_result);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
}

MU_TEST_SUITE(ft_strdup_test_suite)
{
	MU_RUN_TEST(test_ft_strdup_forty_two);
	MU_RUN_TEST(test_ft_strdup_empty_string);
	MU_RUN_TEST(test_ft_strdup_long_string);
	MU_RUN_TEST(test_ft_strdup_special_characters);
	MU_RUN_TEST(test_ft_strdup_spaces);
	MU_RUN_TEST(test_ft_strdup_unicode_string);
	MU_RUN_TEST(test_ft_strdup_escape_characters);
	MU_RUN_TEST(test_ft_strdup_very_long_string);
}

int	main(void) {
	MU_RUN_SUITE(ft_strdup_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
