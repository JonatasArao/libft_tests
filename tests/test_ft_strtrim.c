/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:53:32 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/23 11:24:34 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include "minunit.h"

char	*ft_strtrim(char const *s1, char const *set);

extern int mock_malloc_memset_active;

extern int mock_malloc_failure_active;

int capture_segfault_ft_strtrim(char *(*f)(const char *, const char *), char const *s1, char const *set)
{
	pid_t pid = fork();
	if (pid == 0)
	{
		// Child process executes the test
		f(s1, set);
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

MU_TEST(test_ft_strtrim_is_null_terminated)
{
	// ARRANGE
	char	*actual_result;

	// ACT
	actual_result = ft_strtrim("   42   ", " ");
	if (!actual_result) {
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	mu_assert(actual_result[2] == '\0', "Expected the duplicated string to be null-terminated");

	// CLEANUP
	free(actual_result);
}

MU_TEST(test_ft_strtrim_trims_spaces)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("forty two");
	if (!expected_result) {
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_strtrim("   forty two   ", " ");
	if (!actual_result) {
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_strtrim_trims_multiple_chars)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("forty two");
	if (!expected_result) {
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_strtrim("FTFTFTforty twoFTFTFT", "FT");
	if (!actual_result) {
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_strtrim_no_trim_needed)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("forty two");
	if (!expected_result) {
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_strtrim("forty two", " ");
	if (!actual_result) {
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_strtrim_trim_all_chars)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("");
	if (!expected_result) {
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_strtrim("FTFTFTFT", "FT");
	if (!actual_result) {
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_strtrim_trim_middle_chars)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("forty FT two");
	if (!expected_result) {
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_strtrim("forty FT two", "FT");
	if (!actual_result) {
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_strtrim_trim_numbers)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("forty two");
	if (!expected_result) {
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_strtrim("123forty two123", "123");
	if (!actual_result) {
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_strtrim_trim_mixed_chars)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("forty two");
	if (!expected_result) {
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_strtrim("abc123forty two123abc", "abc123");
	if (!actual_result) {
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_strtrim_case_sensitive)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("Forty Two");
	if (!expected_result) {
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_strtrim("abcForty Twoabc", "abc");
	if (!actual_result) {
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_strtrim_case_sensitive_no_trim)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("abcForty Twoabc");
	if (!expected_result) {
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_strtrim("abcForty Twoabc", "ABC");
	if (!actual_result) {
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_strtrim_s1_empty)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("");
	if (!expected_result) {
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_strtrim("", "42");
	if (!actual_result) {
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_strtrim_s2_empty)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("42");
	if (!expected_result) {
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_strtrim("42", "");
	if (!actual_result) {
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_strtrim_s1_empty_s2_empty)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("");
	if (!expected_result) {
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_strtrim("", "");
	if (!actual_result) {
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_strtrim_s1_null)
{
	int		expected_result;
	int		actual_result;

	// ACT & ASSERT
	actual_result = 1;
	expected_result = capture_segfault_ft_strtrim(&ft_strtrim, NULL, "42");
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST(test_ft_strtrim_s2_null)
{
	int		expected_result;
	int		actual_result;

	// ACT & ASSERT
	actual_result = 1;
	expected_result = capture_segfault_ft_strtrim(&ft_strtrim, "42", NULL);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST(test_ft_strtrim_s1_null_s2_null)
{
	int		expected_result;
	int		actual_result;

	// ACT & ASSERT
	actual_result = 1;
	expected_result = capture_segfault_ft_strtrim(&ft_strtrim, NULL, NULL);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST(test_ft_strtrim_malloc_fail)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	int		segfaulted;

	// ACT
	expected_result = NULL;
	mock_malloc_failure_active = 1;
	segfaulted = capture_segfault_ft_strtrim(&ft_strtrim, "forty ", "fty");
	if (!segfaulted)
		actual_result = ft_strtrim("forty ", "fty");
	mock_malloc_failure_active = 0;

	// ASSERT
	if (!segfaulted)
	{
		mu_assert(actual_result == expected_result, "Expected NULL pointer");
		free(actual_result);
	}
	else
		mu_fail("Function should not cause a segmentation fault.");
}

MU_TEST_SUITE(ft_strtrim_test_suite)
{
	MU_RUN_TEST(test_ft_strtrim_is_null_terminated);
	MU_RUN_TEST(test_ft_strtrim_trims_spaces);
	MU_RUN_TEST(test_ft_strtrim_trims_multiple_chars);
	MU_RUN_TEST(test_ft_strtrim_no_trim_needed);
	MU_RUN_TEST(test_ft_strtrim_trim_all_chars);
	MU_RUN_TEST(test_ft_strtrim_trim_middle_chars);
	MU_RUN_TEST(test_ft_strtrim_trim_numbers);
	MU_RUN_TEST(test_ft_strtrim_trim_mixed_chars);
	MU_RUN_TEST(test_ft_strtrim_case_sensitive);
	MU_RUN_TEST(test_ft_strtrim_case_sensitive_no_trim);
	MU_RUN_TEST(test_ft_strtrim_s1_empty);
	MU_RUN_TEST(test_ft_strtrim_s2_empty);
	MU_RUN_TEST(test_ft_strtrim_s1_empty_s2_empty);
	MU_RUN_TEST(test_ft_strtrim_s1_null);
	MU_RUN_TEST(test_ft_strtrim_s2_null);
	MU_RUN_TEST(test_ft_strtrim_s1_null_s2_null);
	MU_RUN_TEST(test_ft_strtrim_malloc_fail);
}

int	main(void) {
	mock_malloc_memset_active = 1;
	MU_RUN_SUITE(ft_strtrim_test_suite);
	MU_REPORT();
	mock_malloc_memset_active = 0;
	return MU_EXIT_CODE;
}
