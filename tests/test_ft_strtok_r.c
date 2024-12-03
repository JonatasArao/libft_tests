/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtok_r.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:00:39 by jarao-de          #+#    #+#             */
/*   Updated: 2024/12/03 09:31:37 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "minunit.h"

char	*ft_strtok_r(char *str, const char *delim, char **saveptr);

MU_TEST(test_ft_strtok_r_basic)
{
	// ARRANGE
	char str[14];
	char *expected_result;
	char *actual_result;
	char *saveptr;

	strcpy(str, "Hello, world!");

	// ACT & ASSERT
	expected_result = "Hello";
	actual_result = ft_strtok_r(str, ", ", &saveptr);
	mu_assert_string_eq(expected_result, actual_result);

	expected_result = "world!";
	actual_result = ft_strtok_r(NULL, ", ", &saveptr);
	mu_assert_string_eq(expected_result, actual_result);

	expected_result = NULL;
	actual_result = ft_strtok_r(NULL, ", ", &saveptr);
	mu_assert(expected_result == actual_result, "Expected NULL but got a different result");
}

MU_TEST(test_ft_strtok_r_multiple_delimiters)
{
	// ARRANGE
	char str[30];
	char *expected_result;
	char *actual_result;
	char *saveptr;

	strcpy(str, "Hello,, world!,,42,,school");

	// ACT & ASSERT
	expected_result = "Hello";
	actual_result = ft_strtok_r(str, ", ", &saveptr);
	mu_assert_string_eq(expected_result, actual_result);

	expected_result = "world!";
	actual_result = ft_strtok_r(NULL, ", ", &saveptr);
	mu_assert_string_eq(expected_result, actual_result);

	expected_result = "42";
	actual_result = ft_strtok_r(NULL, ", ", &saveptr);
	mu_assert_string_eq(expected_result, actual_result);

	expected_result = "school";
	actual_result = ft_strtok_r(NULL, ", ", &saveptr);
	mu_assert_string_eq(expected_result, actual_result);

	expected_result = NULL;
	actual_result = ft_strtok_r(NULL, ", ", &saveptr);
	mu_assert(expected_result == actual_result, "Expected NULL but got a different result");
}

MU_TEST(test_ft_strtok_r_no_delimiters)
{
	// ARRANGE
	char str[14];
	char *expected_result;
	char *actual_result;
	char *saveptr;

	strcpy(str, "HelloWorld");

	// ACT & ASSERT
	expected_result = "HelloWorld";
	actual_result = ft_strtok_r(str, ", ", &saveptr);
	mu_assert_string_eq(expected_result, actual_result);

	expected_result = NULL;
	actual_result = ft_strtok_r(NULL, ", ", &saveptr);
	mu_assert(expected_result == actual_result, "Expected NULL but got a different result");
}

MU_TEST(test_ft_strtok_r_only_delimiters)
{
	// ARRANGE
	char str[5];
	char *expected_result;
	char *actual_result;
	char *saveptr;

	strcpy(str, ", ,,");

	// ACT & ASSERT
	expected_result = NULL;
	actual_result = ft_strtok_r(str, ", ", &saveptr);
	mu_assert(expected_result == actual_result, "Expected NULL but got a different result");
}

MU_TEST(test_ft_strtok_r_empty_string)
{
	// ARRANGE
	char str[1];
	char *expected_result;
	char *actual_result;
	char *saveptr;

	strcpy(str, "");

	// ACT & ASSERT
	expected_result = NULL;
	actual_result = ft_strtok_r(str, ", ", &saveptr);
	mu_assert(expected_result == actual_result, "Expected NULL but got a different result");
}

MU_TEST(test_ft_strtok_r_single_character_delimiter)
{
	// ARRANGE
	char str[2];
	char *expected_result;
	char *actual_result;
	char *saveptr;

	strcpy(str, ",");

	// ACT & ASSERT
	expected_result = NULL;
	actual_result = ft_strtok_r(str, ",", &saveptr);
	mu_assert(expected_result == actual_result, "Expected NULL but got a different result");
}

MU_TEST(test_ft_strtok_r_single_character_non_delimiter)
{
	// ARRANGE
	char str[2];
	char *expected_result;
	char *actual_result;
	char *saveptr;

	strcpy(str, "a");

	// ACT & ASSERT
	expected_result = "a";
	actual_result = ft_strtok_r(str, ",", &saveptr);
	mu_assert_string_eq(expected_result, actual_result);

	expected_result = NULL;
	actual_result = ft_strtok_r(NULL, ",", &saveptr);
	mu_assert(expected_result == actual_result, "Expected NULL but got a different result");
}

MU_TEST(test_ft_strtok_r_consecutive_delimiters)
{
	// ARRANGE
	char str[10];
	char *expected_result;
	char *actual_result;
	char *saveptr;

	strcpy(str, ",,Hello,,,");

	// ACT & ASSERT
	expected_result = "Hello";
	actual_result = ft_strtok_r(str, ",", &saveptr);
	mu_assert_string_eq(expected_result, actual_result);

	expected_result = NULL;
	actual_result = ft_strtok_r(NULL, ",", &saveptr);
	mu_assert(expected_result == actual_result, "Expected NULL but got a different result");
}

MU_TEST(test_ft_strtok_r_interleaved_strings)
{
	// ARRANGE
	char str1[14];
	char str2[14];
	char *expected_result;
	char *actual_result;
	char *saveptr1;
	char *saveptr2;

	strcpy(str1, "Hello, world!");
	strcpy(str2, "42, school");

	// ACT & ASSERT
	expected_result = "Hello";
	actual_result = ft_strtok_r(str1, ", ", &saveptr1);
	mu_assert_string_eq(expected_result, actual_result);

	expected_result = "42";
	actual_result = ft_strtok_r(str2, ", ", &saveptr2);
	mu_assert_string_eq(expected_result, actual_result);

	expected_result = "world!";
	actual_result = ft_strtok_r(NULL, ", ", &saveptr1);
	mu_assert_string_eq(expected_result, actual_result);

	expected_result = "school";
	actual_result = ft_strtok_r(NULL, ", ", &saveptr2);
	mu_assert_string_eq(expected_result, actual_result);

	expected_result = NULL;
	actual_result = ft_strtok_r(NULL, ", ", &saveptr1);
	mu_assert(expected_result == actual_result, "Expected NULL but got a different result");

	expected_result = NULL;
	actual_result = ft_strtok_r(NULL, ", ", &saveptr2);
	mu_assert(expected_result == actual_result, "Expected NULL but got a different result");
}

MU_TEST_SUITE(ft_strtok_r_test_suite)
{
	MU_RUN_TEST(test_ft_strtok_r_basic);
	MU_RUN_TEST(test_ft_strtok_r_multiple_delimiters);
	MU_RUN_TEST(test_ft_strtok_r_no_delimiters);
	MU_RUN_TEST(test_ft_strtok_r_only_delimiters);
	MU_RUN_TEST(test_ft_strtok_r_empty_string);
	MU_RUN_TEST(test_ft_strtok_r_single_character_delimiter);
	MU_RUN_TEST(test_ft_strtok_r_single_character_non_delimiter);
	MU_RUN_TEST(test_ft_strtok_r_consecutive_delimiters);
	MU_RUN_TEST(test_ft_strtok_r_interleaved_strings);
}

int	main(void)
{
	MU_RUN_SUITE(ft_strtok_r_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
