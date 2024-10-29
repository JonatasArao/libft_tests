/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:56:36 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/29 17:30:23 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include "minunit.h"

char	*ft_strnstr(const char *big, const char *little, size_t len);

int	capture_segfault_ft_strnstr(char *(*f)(const char *, const char *, size_t), const char *big, const char *little, size_t len)
{
	pid_t pid = fork();
	if (pid == 0)
	{
		// Child process executes the test
		f(big, little, len);
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

MU_TEST(test_ft_strnstr_empty_little_in_big_fortytwo_school)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*big;
	char	message[50];

	// ACT
	big = strdup("fortytwo school");
	if (!big) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = big;
	actual_result = ft_strnstr(big, "", 1);
	snprintf(message, sizeof(message), "Expected memory address %p but was %p\n", (void *)expected_result, (void *)actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);

	// CLEANUP
	free(big);
}

MU_TEST(test_ft_strnstr_little_two_in_big_fortytwo_school_size_15)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*big;
	char	message[50];

	// ACT
	big = strdup("fortytwo school");
	if (!big) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = &big[5];
	actual_result = ft_strnstr(big, "two", 15);
	snprintf(message, sizeof(message), "Expected memory address %p but was %p\n", (void *)expected_result, (void *)actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);

	// CLEANUP
	free(big);
}

MU_TEST(test_ft_strnstr_little_two_in_big_fortytwo_school_size_8)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*big;
	char	message[50];

	// ACT
	big = strdup("fortytwo school");
	if (!big) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = &big[5];
	actual_result = ft_strnstr(big, "two", 8);
	snprintf(message, sizeof(message), "Expected memory address %p but was %p\n", (void *)expected_result, (void *)actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);

	// CLEANUP
	free(big);
}

MU_TEST(test_ft_strnstr_little_two_in_big_fortytwo_school_size_7)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*big;

	// ACT
	big = strdup("fortytwo school");
	if (!big) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = NULL;
	actual_result = ft_strnstr(big, "two", 7);

	// ASSERT
	mu_assert(actual_result == expected_result, "Expected NULL pointer");

	// CLEANUP
	free(big);
}

MU_TEST(test_ft_strnstr_little_two_in_big_fortytwo_school_size_5)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*big;

	// ACT
	big = strdup("fortytwo school");
	if (!big) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = NULL;
	actual_result = ft_strnstr(big, "two", 5);

	// ASSERT
	mu_assert(actual_result == expected_result, "Expected NULL pointer");

	// CLEANUP
	free(big);
}

MU_TEST(test_ft_strnstr_little_forty_in_big_fortytwo_school_size_15)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*big;
	char	message[50];

	// ACT
	big = strdup("fortytwo school");
	if (!big) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = &big[0];
	actual_result = ft_strnstr(big, "forty", 15);
	snprintf(message, sizeof(message), "Expected memory address %p but was %p\n", (void *)expected_result, (void *)actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);

	// CLEANUP
	free(big);
}

MU_TEST(test_ft_strnstr_little_forty_in_big_fortytwo_school_size_4)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*big;

	// ACT
	big = strdup("fortytwo school");
	if (!big) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = NULL;
	actual_result = ft_strnstr(big, "forty", 4);

	// ASSERT
	mu_assert(actual_result == expected_result, "Expected NULL pointer");

	// CLEANUP
	free(big);
}

MU_TEST(test_ft_strnstr_little_forty_in_big_fortytwo_school_size_5)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*big;
	char	message[50];

	// ACT
	big = strdup("fortytwo school");
	if (!big) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = &big[0];
	actual_result = ft_strnstr(big, "forty", 5);
	snprintf(message, sizeof(message), "Expected memory address %p but was %p\n", (void *)expected_result, (void *)actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);

	// CLEANUP
	free(big);
}

MU_TEST(test_ft_strnstr_little_school_in_big_fortytwo_school_size_15)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*big;
	char	message[50];

	// ACT
	big = strdup("fortytwo school");
	if (!big) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = &big[9];
	actual_result = ft_strnstr(big, "school", 15);
	snprintf(message, sizeof(message), "Expected memory address %p but was %p\n", (void *)expected_result, (void *)actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);

	// CLEANUP
	free(big);
}

MU_TEST(test_ft_strnstr_little_school_in_big_fortytwo_school_size_14)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*big;

	// ACT
	big = strdup("fortytwo school");
	if (!big) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = NULL;
	actual_result = ft_strnstr(big, "school", 14);

	// ASSERT
	mu_assert(actual_result == expected_result, "Expected NULL pointer");

	// CLEANUP
	free(big);
}

MU_TEST(test_ft_strnstr_little_school_in_big_fortytwo_school_size_9)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*big;

	// ACT
	big = strdup("fortytwo school");
	if (!big) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = NULL;
	actual_result = ft_strnstr(big, "school", 9);

	// ASSERT
	mu_assert(actual_result == expected_result, "Expected NULL pointer");

	// CLEANUP
	free(big);
}

MU_TEST(test_ft_strnstr_little_fortytwo_school_in_big_fortytwo_school_size_15)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*big;
	char	message[50];

	// ACT
	big = strdup("fortytwo school");
	if (!big) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = &big[0];
	actual_result = ft_strnstr(big, "fortytwo school", 15);
	snprintf(message, sizeof(message), "Expected memory address %p but was %p\n", (void *)expected_result, (void *)actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);

	// CLEANUP
	free(big);
}

MU_TEST(test_ft_strnstr_little_fortytwo_school_in_big_fortytwo_school_size_14)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*big;

	// ACT
	big = strdup("fortytwo school");
	if (!big) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = NULL;
	actual_result = ft_strnstr(big, "fortytwo school", 14);

	// ASSERT
	mu_assert(actual_result == expected_result, "Expected NULL pointer");

	// CLEANUP
	free(big);
}

MU_TEST(test_ft_strnstr_little_fortytwo_school_in_big_fortytwo_school_size_0)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*big;

	// ACT
	big = strdup("fortytwo school");
	if (!big) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = NULL;
	actual_result = ft_strnstr(big, "fortytwo school", 0);

	// ASSERT
	mu_assert(actual_result == expected_result, "Expected NULL pointer");

	// CLEANUP
	free(big);
}

MU_TEST(test_ft_strnstr_little_ft_in_big_fortytwo_school_size_15)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*big;

	// ACT
	big = strdup("fortytwo school");
	if (!big) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = NULL;
	actual_result = ft_strnstr(big, "ft", 15);

	// ASSERT
	mu_assert(actual_result == expected_result, "Expected NULL pointer");

	// CLEANUP
	free(big);
}

MU_TEST(test_ft_strnstr_special_characters_in_big_fortytwo_school_size_15)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*big;
	char	message[50];

	// ACT
	big = strdup("fortytwo@school");
	if (!big) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = &big[5];
	actual_result = ft_strnstr(big, "two@", 15);
	snprintf(message, sizeof(message), "Expected memory address %p but was %p\n", (void *)expected_result, (void *)actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);

	// CLEANUP
	free(big);
}

MU_TEST(test_ft_strnstr_special_characters_in_big_fortytwo_school_size_8)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*big;

	// ACT
	big = strdup("fortytwo@school");
	if (!big) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = NULL;
	actual_result = ft_strnstr(big, "two@", 8);

	// ASSERT
	mu_assert(actual_result == expected_result, "Expected NULL pointer");

	// CLEANUP
	free(big);
}

MU_TEST(test_ft_strnstr_special_characters_in_big_fortytwo_school_size_7)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*big;

	// ACT
	big = strdup("fortytwo@school");
	if (!big) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = NULL;
	actual_result = ft_strnstr(big, "two@", 7);

	// ASSERT
	mu_assert(actual_result == expected_result, "Expected NULL pointer");

	// CLEANUP
	free(big);
}

MU_TEST(test_ft_strnstr_special_characters_in_big_fortytwo_school_size_5)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*big;

	// ACT
	big = strdup("fortytwo@school");
	if (!big) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = NULL;
	actual_result = ft_strnstr(big, "two@", 5);

	// ASSERT
	mu_assert(actual_result == expected_result, "Expected NULL pointer");

	// CLEANUP
	free(big);
}

MU_TEST(test_ft_strnstr_non_ascii_in_big_fortytwo_school_size_15)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*big;
	char	message[50];

	// ACT
	big = strdup("fortytwø school");
	if (!big) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = &big[5];
	actual_result = ft_strnstr(big, "twø ", 15);
	snprintf(message, sizeof(message), "Expected memory address %p but was %p\n", (void *)expected_result, (void *)actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);

	// CLEANUP
	free(big);
}

MU_TEST(test_ft_strnstr_non_ascii_in_big_fortytwo_school_size_8)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*big;

	// ACT
	big = strdup("fortytwø school");
	if (!big) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = NULL;
	actual_result = ft_strnstr(big, "twø ", 8);

	// ASSERT
	mu_assert(actual_result == expected_result, "Expected NULL pointer");

	// CLEANUP
	free(big);
}

MU_TEST(test_ft_strnstr_non_ascii_in_big_fortytwo_school_size_7)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*big;

	// ACT
	big = strdup("fortytwø school");
	if (!big) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = NULL;
	actual_result = ft_strnstr(big, "twø ", 7);

	// ASSERT
	mu_assert(actual_result == expected_result, "Expected NULL pointer");

	// CLEANUP
	free(big);
}

MU_TEST(test_ft_strnstr_non_ascii_in_big_fortytwo_school_size_5)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*big;

	// ACT
	big = strdup("fortytwø school");
	if (!big) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = NULL;
	actual_result = ft_strnstr(big, "twø ", 5);

	// ASSERT
	mu_assert(actual_result == expected_result, "Expected NULL pointer");

	// CLEANUP
	free(big);
}

MU_TEST(test_ft_strnstr_little_null_pointer)
{
	int expected_result;
	int actual_result;

	// ACT & ASSERT
	expected_result = 1;
	actual_result = capture_segfault_ft_strnstr(&ft_strnstr, NULL, "42", 2);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST(test_ft_strnstr_big_null_pointer)
{
	int expected_result;
	int actual_result;

	// ACT & ASSERT
	expected_result = 1;
	actual_result = capture_segfault_ft_strnstr(&ft_strnstr, "42", NULL, 2);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST(test_ft_strnstr_little_and_big_null_pointer)
{
	int expected_result;
	int actual_result;

	// ACT & ASSERT
	expected_result = 1;
	actual_result = capture_segfault_ft_strnstr(&ft_strnstr, NULL, NULL, 2);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST_SUITE(ft_strnstr_test_suite)
{
	MU_RUN_TEST(test_ft_strnstr_empty_little_in_big_fortytwo_school);
	MU_RUN_TEST(test_ft_strnstr_little_two_in_big_fortytwo_school_size_15);
	MU_RUN_TEST(test_ft_strnstr_little_two_in_big_fortytwo_school_size_7);
	MU_RUN_TEST(test_ft_strnstr_little_two_in_big_fortytwo_school_size_8);
	MU_RUN_TEST(test_ft_strnstr_little_two_in_big_fortytwo_school_size_5);
	MU_RUN_TEST(test_ft_strnstr_little_forty_in_big_fortytwo_school_size_15);
	MU_RUN_TEST(test_ft_strnstr_little_forty_in_big_fortytwo_school_size_4);
	MU_RUN_TEST(test_ft_strnstr_little_forty_in_big_fortytwo_school_size_5);
	MU_RUN_TEST(test_ft_strnstr_little_school_in_big_fortytwo_school_size_15);
	MU_RUN_TEST(test_ft_strnstr_little_school_in_big_fortytwo_school_size_14);
	MU_RUN_TEST(test_ft_strnstr_little_school_in_big_fortytwo_school_size_9);
	MU_RUN_TEST(test_ft_strnstr_little_fortytwo_school_in_big_fortytwo_school_size_15);
	MU_RUN_TEST(test_ft_strnstr_little_fortytwo_school_in_big_fortytwo_school_size_14);
	MU_RUN_TEST(test_ft_strnstr_little_fortytwo_school_in_big_fortytwo_school_size_0);
	MU_RUN_TEST(test_ft_strnstr_little_ft_in_big_fortytwo_school_size_15);
	MU_RUN_TEST(test_ft_strnstr_special_characters_in_big_fortytwo_school_size_15);
	MU_RUN_TEST(test_ft_strnstr_special_characters_in_big_fortytwo_school_size_8);
	MU_RUN_TEST(test_ft_strnstr_special_characters_in_big_fortytwo_school_size_7);
	MU_RUN_TEST(test_ft_strnstr_special_characters_in_big_fortytwo_school_size_5);
	MU_RUN_TEST(test_ft_strnstr_non_ascii_in_big_fortytwo_school_size_15);
	MU_RUN_TEST(test_ft_strnstr_non_ascii_in_big_fortytwo_school_size_8);
	MU_RUN_TEST(test_ft_strnstr_non_ascii_in_big_fortytwo_school_size_7);
	MU_RUN_TEST(test_ft_strnstr_non_ascii_in_big_fortytwo_school_size_5);
	MU_RUN_TEST(test_ft_strnstr_little_null_pointer);
	MU_RUN_TEST(test_ft_strnstr_big_null_pointer);
	MU_RUN_TEST(test_ft_strnstr_little_and_big_null_pointer);
}

int	main(void) {
	MU_RUN_SUITE(ft_strnstr_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
