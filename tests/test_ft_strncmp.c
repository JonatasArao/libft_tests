/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:59:13 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/17 17:03:04 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include "minunit.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n);

int	capture_segfault_ft_strncmp(int (*f)(const char *, const char *, size_t), const char *s1, const char *s2, size_t n)
{
	pid_t pid = fork();
	if (pid == 0)
	{
		// Child process executes the test
		f(s1, s2, n);
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

MU_TEST(test_ft_strncmp_s1_fortytwo_s2_fortyTWO_size_6)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 't' - 'T';
	actual_result = ft_strncmp("fortytwo", "fortyTWO", 6);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strncmp_s1_fortyTWO_s2_fortytwo_size_6)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 'T' - 't';
	actual_result = ft_strncmp("fortyTWO", "fortytwo", 6);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strncmp_s1_fortytwo_s2_fortyTWO_size_3)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_strncmp("fortytwo", "fortyTWO", 3);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strncmp_s1_fortyTWO_s2_fortytwo_size_3)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_strncmp("fortyTWO", "fortytwo", 3);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strncmp_size_0)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_strncmp("fortyTWO", "fortytwo", 0);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strncmp_s1_empty_s2_empty_size_0)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_strncmp("", "", 0);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strncmp_s1_empty_s2_empty_size_1)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_strncmp("", "", 1);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strncmp_s1_empty_s2_non_empty_size_0)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_strncmp("", "42", 0);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strncmp_s1_empty_s2_non_empty_size_1)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = -'4';
	actual_result = ft_strncmp("", "42", 1);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strncmp_s1_non_empty_s2_empty_size_0)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_strncmp("42", "", 0);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strncmp_s1_non_empty_s2_empty_size_1)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = '4';
	actual_result = ft_strncmp("42", "", 1);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strncmp_s1_shorter_than_s2)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = -'t';
	actual_result = ft_strncmp("forty", "fortytwo", 8);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strncmp_s1_longer_than_s2)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 't';
	actual_result = ft_strncmp("fortytwo", "forty", 8);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strncmp_s1_equal_s2)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_strncmp("fortytwo", "fortytwo", 8);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strncmp_s1_equal_s2_n_greater_than_length)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_strncmp("fortytwo", "fortytwo", 20);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strncmp_s1_different_s2_n_greater_than_length)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 't' - 'T';
	actual_result = ft_strncmp("fortytwo", "fortyTWO", 20);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strncmp_unsigned_char_handling)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = (unsigned char)'A' - (unsigned char)'\xFF';
	actual_result = ft_strncmp("A", "\xFF", 1);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strncmp_with_null_characters)
{
	// ARRANGE
	int expected_result;
	int actual_result;
	char *s1 = "fortytwo\0abc";
	char *s2 = "fortytwo\0xyz";

	// ACT
	expected_result = 0;
	actual_result = ft_strncmp(s1, s2, 12);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strncmp_s1_null_pointer)
{
	int expected_result;
	int actual_result;

	// ACT & ASSERT
	actual_result = 1;
	expected_result = capture_segfault_ft_strncmp(&ft_strncmp, NULL, "42", 2);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST(test_ft_strncmp_s2_null_pointer)
{
	int expected_result;
	int actual_result;

	// ACT & ASSERT
	actual_result = 1;
	expected_result = capture_segfault_ft_strncmp(&ft_strncmp, "42", NULL, 2);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST(test_ft_strncmp_s1_and_s2_null_pointer)
{
	int expected_result;
	int actual_result;

	// ACT & ASSERT
	actual_result = 1;
	expected_result = capture_segfault_ft_strncmp(&ft_strncmp, NULL, NULL, 2);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST_SUITE(ft_strncmp_test_suite)
{
	MU_RUN_TEST(test_ft_strncmp_s1_fortytwo_s2_fortyTWO_size_6);
	MU_RUN_TEST(test_ft_strncmp_s1_fortyTWO_s2_fortytwo_size_6);
	MU_RUN_TEST(test_ft_strncmp_s1_fortytwo_s2_fortyTWO_size_3);
	MU_RUN_TEST(test_ft_strncmp_s1_fortyTWO_s2_fortytwo_size_3);
	MU_RUN_TEST(test_ft_strncmp_size_0);
	MU_RUN_TEST(test_ft_strncmp_s1_empty_s2_empty_size_0);
	MU_RUN_TEST(test_ft_strncmp_s1_empty_s2_empty_size_1);
	MU_RUN_TEST(test_ft_strncmp_s1_empty_s2_non_empty_size_0);
	MU_RUN_TEST(test_ft_strncmp_s1_empty_s2_non_empty_size_1);
	MU_RUN_TEST(test_ft_strncmp_s1_non_empty_s2_empty_size_0);
	MU_RUN_TEST(test_ft_strncmp_s1_non_empty_s2_empty_size_1);
	MU_RUN_TEST(test_ft_strncmp_s1_shorter_than_s2);
	MU_RUN_TEST(test_ft_strncmp_s1_longer_than_s2);
	MU_RUN_TEST(test_ft_strncmp_s1_equal_s2);
	MU_RUN_TEST(test_ft_strncmp_s1_equal_s2_n_greater_than_length);
	MU_RUN_TEST(test_ft_strncmp_s1_different_s2_n_greater_than_length);
	MU_RUN_TEST(test_ft_strncmp_unsigned_char_handling);
	MU_RUN_TEST(test_ft_strncmp_with_null_characters);
	MU_RUN_TEST(test_ft_strncmp_s1_null_pointer);
	MU_RUN_TEST(test_ft_strncmp_s2_null_pointer);
	MU_RUN_TEST(test_ft_strncmp_s1_and_s2_null_pointer);
}

int main(void)
{
	MU_RUN_SUITE(ft_strncmp_test_suite);
	MU_REPORT();
	return 0;
}
