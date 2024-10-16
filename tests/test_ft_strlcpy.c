/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:07:17 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/16 19:25:33 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include "minunit.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

int capture_segfault_ft_strlcpy(size_t (*f)(char *, const char *, size_t), char *dst, const char *src, size_t size)
{
	pid_t pid = fork();
	if (pid == 0)
	{
		// Child process executes the test
		f(dst, src, size);
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

MU_TEST(test_ft_strlcpy_null_src)
{
	int		expected_result;
	int		actual_result;
	char	dst[2];

	// ACT & ASSERT
	actual_result = 1;
	expected_result = capture_segfault_ft_strlcpy(&ft_strlcpy, dst, NULL, 3);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST(test_ft_strlcpy_null_dst)
{
	int		expected_result;
	int		actual_result;

	// ACT & ASSERT
	actual_result = 1;
	expected_result = capture_segfault_ft_strlcpy(&ft_strlcpy, NULL, "", 3);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
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
	MU_RUN_TEST(test_ft_strlcpy_empty_source_assignment);
	MU_RUN_TEST(test_ft_strlcpy_empty_source_return);
	MU_RUN_TEST(test_ft_strlcpy_null_src);
	MU_RUN_TEST(test_ft_strlcpy_null_dst);
}

int	main(void) {
	MU_RUN_SUITE(ft_strlcpy_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
