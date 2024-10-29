/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:00:10 by jarao-de          #+#    #+#             */
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

int	ft_atoi(const char *nptr);

int	capture_segfault_ft_atoi(int (*f)(const char *), const char *nptr)
{
	pid_t pid = fork();
	if (pid == 0)
	{
		// Child process executes the test
		f(nptr);
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

MU_TEST(test_ft_atoi_convert_0_string_to_0_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_atoi("0");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_convert_1_string_to_1_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 1;
	actual_result = ft_atoi("1");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_convert_10_string_to_10_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 10;
	actual_result = ft_atoi("10");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_convert_100_string_to_100_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 100;
	actual_result = ft_atoi("100");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_convert_1000_string_to_1000_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 1000;
	actual_result = ft_atoi("1000");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_convert_10000_string_to_10000_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 10000;
	actual_result = ft_atoi("10000");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_convert_100000_string_to_100000_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 100000;
	actual_result = ft_atoi("100000");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_convert_1000000_string_to_1000000_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 1000000;
	actual_result = ft_atoi("1000000");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_convert_10000000_string_to_10000000_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 10000000;
	actual_result = ft_atoi("10000000");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_convert_100000000_string_to_100000000_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 100000000;
	actual_result = ft_atoi("100000000");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_convert_1000000000_string_to_1000000000_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 1000000000;
	actual_result = ft_atoi("1000000000");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_convert_minus_1_string_to_minus_1_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = -1;
	actual_result = ft_atoi("-1");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_convert_minus_10_string_to_minus_10_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = -10;
	actual_result = ft_atoi("-10");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_convert_minus_100_string_to_minus_100_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = -100;
	actual_result = ft_atoi("-100");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_convert_minus_1000_string_to_minus_1000_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = -1000;
	actual_result = ft_atoi("-1000");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_convert_minus_10000_string_to_minus_10000_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = -10000;
	actual_result = ft_atoi("-10000");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_convert_minus_100000_string_to_minus_100000_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = -100000;
	actual_result = ft_atoi("-100000");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_convert_minus_1000000_string_to_minus_1000000_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = -1000000;
	actual_result = ft_atoi("-1000000");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_convert_minus_10000000_string_to_minus_10000000_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = -10000000;
	actual_result = ft_atoi("-10000000");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_convert_minus_100000000_string_to_minus_100000000_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = -100000000;
	actual_result = ft_atoi("-100000000");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_convert_minus_1000000000_string_to_minus_1000000000_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = -1000000000;
	actual_result = ft_atoi("-1000000000");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_convert_minint_string_to_minint_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = -2147483648;
	actual_result = ft_atoi("-2147483648");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_convert_maxint_string_to_maxint_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 2147483647;
	actual_result = ft_atoi("2147483647");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_convert_42_with_spaces_string_to_42_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 42;
	actual_result = ft_atoi(" \f\n\r\t\v42");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_convert_42_signal_after_spaces_string_to_42_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 42;
	actual_result = ft_atoi(" \f\n\r\t\v+42");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_convert_42_signal_surrounded_by_spaces_string_to_42_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_atoi(" \f\n+\r\t\v42");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_convert_42_signal_before_spaces_string_to_42_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_atoi("+ \f\n\r\t\v42");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_convert_minus_42_signal_after_spaces_string_to_minus_42_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = -42;
	actual_result = ft_atoi(" \f\n\r\t\v-42");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_convert_minus_42_signal_surrounded_by_spaces_string_to_minus_42_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_atoi(" \f\n-\r\t\v42");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_convert_minus_42_signal_before_spaces_string_to_minus_42_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_atoi("- \f\n\r\t\v42");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_convert_42_more_than_one_signal_string_to_42_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_atoi("++42");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_convert_minus_42_more_than_one_signal_string_to_minus_42_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_atoi("++42");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_null_pointer)
{
	int		expected_result;
	int		actual_result;

	// ACT & ASSERT
	expected_result = 1;
	actual_result = capture_segfault_ft_atoi(&ft_atoi, NULL);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST_SUITE(ft_atoi_test_suite)
{
	MU_RUN_TEST(test_ft_atoi_convert_0_string_to_0_integer);
	MU_RUN_TEST(test_ft_atoi_convert_1_string_to_1_integer);
	MU_RUN_TEST(test_ft_atoi_convert_10_string_to_10_integer);
	MU_RUN_TEST(test_ft_atoi_convert_100_string_to_100_integer);
	MU_RUN_TEST(test_ft_atoi_convert_1000_string_to_1000_integer);
	MU_RUN_TEST(test_ft_atoi_convert_10000_string_to_10000_integer);
	MU_RUN_TEST(test_ft_atoi_convert_100000_string_to_100000_integer);
	MU_RUN_TEST(test_ft_atoi_convert_1000000_string_to_1000000_integer);
	MU_RUN_TEST(test_ft_atoi_convert_10000000_string_to_10000000_integer);
	MU_RUN_TEST(test_ft_atoi_convert_100000000_string_to_100000000_integer);
	MU_RUN_TEST(test_ft_atoi_convert_1000000000_string_to_1000000000_integer);
	MU_RUN_TEST(test_ft_atoi_convert_minus_1_string_to_minus_1_integer);
	MU_RUN_TEST(test_ft_atoi_convert_minus_10_string_to_minus_10_integer);
	MU_RUN_TEST(test_ft_atoi_convert_minus_100_string_to_minus_100_integer);
	MU_RUN_TEST(test_ft_atoi_convert_minus_1000_string_to_minus_1000_integer);
	MU_RUN_TEST(test_ft_atoi_convert_minus_10000_string_to_minus_10000_integer);
	MU_RUN_TEST(test_ft_atoi_convert_minus_100000_string_to_minus_100000_integer);
	MU_RUN_TEST(test_ft_atoi_convert_minus_1000000_string_to_minus_1000000_integer);
	MU_RUN_TEST(test_ft_atoi_convert_minus_10000000_string_to_minus_10000000_integer);
	MU_RUN_TEST(test_ft_atoi_convert_minus_100000000_string_to_minus_100000000_integer);
	MU_RUN_TEST(test_ft_atoi_convert_minus_1000000000_string_to_minus_1000000000_integer);
	MU_RUN_TEST(test_ft_atoi_convert_minint_string_to_minint_integer);
	MU_RUN_TEST(test_ft_atoi_convert_maxint_string_to_maxint_integer);
	MU_RUN_TEST(test_ft_atoi_convert_42_with_spaces_string_to_42_integer);
	MU_RUN_TEST(test_ft_atoi_convert_42_signal_after_spaces_string_to_42_integer);
	MU_RUN_TEST(test_ft_atoi_convert_42_signal_surrounded_by_spaces_string_to_42_integer);
	MU_RUN_TEST(test_ft_atoi_convert_42_signal_before_spaces_string_to_42_integer);
	MU_RUN_TEST(test_ft_atoi_convert_minus_42_signal_after_spaces_string_to_minus_42_integer);
	MU_RUN_TEST(test_ft_atoi_convert_minus_42_signal_surrounded_by_spaces_string_to_minus_42_integer);
	MU_RUN_TEST(test_ft_atoi_convert_minus_42_signal_before_spaces_string_to_minus_42_integer);
	MU_RUN_TEST(test_ft_atoi_convert_42_more_than_one_signal_string_to_42_integer);
	MU_RUN_TEST(test_ft_atoi_convert_minus_42_more_than_one_signal_string_to_minus_42_integer);
	MU_RUN_TEST(test_ft_atoi_null_pointer);
}

int	main(void) {
	MU_RUN_SUITE(ft_atoi_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
