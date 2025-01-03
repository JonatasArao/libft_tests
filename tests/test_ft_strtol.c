/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtol.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:23:53 by jarao-de          #+#    #+#             */
/*   Updated: 2024/11/27 09:36:05 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <limits.h>
#include "minunit.h"

long	ft_strtol(const char *nptr, char **endptr, int base);

int	capture_segfault_ft_strtol(int (*f)(const char *, char **, int), const char *nptr, char **endptr, int base)
{
	pid_t pid = fork();
	if (pid == 0)
	{
		// Child process executes the test
		f(nptr, endptr, base);
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

MU_TEST(test_ft_strtol_convert_0_string_to_0_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 0;
	actual_result = ft_strtol("0", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_1_string_to_1_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 1;
	actual_result = ft_strtol("1", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_10_string_to_10_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 10;
	actual_result = ft_strtol("10", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_100_string_to_100_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 100;
	actual_result = ft_strtol("100", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_1000_string_to_1000_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 1000;
	actual_result = ft_strtol("1000", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_10000_string_to_10000_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 10000;
	actual_result = ft_strtol("10000", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_100000_string_to_100000_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 100000;
	actual_result = ft_strtol("100000", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_1000000_string_to_1000000_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 1000000;
	actual_result = ft_strtol("1000000", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_10000000_string_to_10000000_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 10000000;
	actual_result = ft_strtol("10000000", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_100000000_string_to_100000000_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 100000000;
	actual_result = ft_strtol("100000000", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_1000000000_string_to_1000000000_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 1000000000;
	actual_result = ft_strtol("1000000000", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_minus_1_string_to_minus_1_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = -1;
	actual_result = ft_strtol("-1", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_minus_10_string_to_minus_10_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = -10;
	actual_result = ft_strtol("-10", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_minus_100_string_to_minus_100_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = -100;
	actual_result = ft_strtol("-100", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_minus_1000_string_to_minus_1000_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = -1000;
	actual_result = ft_strtol("-1000", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_minus_10000_string_to_minus_10000_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = -10000;
	actual_result = ft_strtol("-10000", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_minus_100000_string_to_minus_100000_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = -100000;
	actual_result = ft_strtol("-100000", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_minus_1000000_string_to_minus_1000000_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = -1000000;
	actual_result = ft_strtol("-1000000", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_minus_10000000_string_to_minus_10000000_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = -10000000;
	actual_result = ft_strtol("-10000000", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_minus_100000000_string_to_minus_100000000_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = -100000000;
	actual_result = ft_strtol("-100000000", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_minus_1000000000_string_to_minus_1000000000_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = -1000000000;
	actual_result = ft_strtol("-1000000000", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_minint_string_to_minint_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = -2147483648;
	actual_result = ft_strtol("-2147483648", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_maxint_string_to_maxint_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 2147483647;
	actual_result = ft_strtol("2147483647", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_42_with_spaces_string_to_42_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 42;
	actual_result = ft_strtol(" \f\n\r\t\v42", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_42_signal_after_spaces_string_to_42_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 42;
	actual_result = ft_strtol(" \f\n\r\t\v+42", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_42_signal_surrounded_by_spaces_string_to_42_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 0;
	actual_result = ft_strtol(" \f\n+\r\t\v42", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_42_signal_before_spaces_string_to_42_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 0;
	actual_result = ft_strtol("+ \f\n\r\t\v42", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_minus_42_signal_after_spaces_string_to_minus_42_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = -42;
	actual_result = ft_strtol(" \f\n\r\t\v-42", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_minus_42_signal_surrounded_by_spaces_string_to_minus_42_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 0;
	actual_result = ft_strtol(" \f\n-\r\t\v42", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_minus_42_signal_before_spaces_string_to_minus_42_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 0;
	actual_result = ft_strtol("- \f\n\r\t\v42", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_42_more_than_one_signal_string_to_42_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 0;
	actual_result = ft_strtol("++42", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_minus_42_more_than_one_signal_string_to_minus_42_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 0;
	actual_result = ft_strtol("++42", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_0_string_to_0_integer_hex)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 0;
	actual_result = ft_strtol("0", &endptr, 16);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_1_string_to_1_integer_hex)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 1;
	actual_result = ft_strtol("1", &endptr, 16);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_A_string_to_10_integer_hex)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 10;
	actual_result = ft_strtol("A", &endptr, 16);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_10_string_to_16_integer_hex)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 16;
	actual_result = ft_strtol("10", &endptr, 16);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_100_string_to_256_integer_hex)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 256;
	actual_result = ft_strtol("100", &endptr, 16);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_minus_1_string_to_minus_1_integer_hex)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = -1;
	actual_result = ft_strtol("-1", &endptr, 16);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_0_string_to_0_integer_binary)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 0;
	actual_result = ft_strtol("0", &endptr, 2);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_1_string_to_1_integer_binary)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 1;
	actual_result = ft_strtol("1", &endptr, 2);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_10_string_to_2_integer_binary)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 2;
	actual_result = ft_strtol("10", &endptr, 2);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_100_string_to_4_integer_binary)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 4;
	actual_result = ft_strtol("100", &endptr, 2);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_minus_1_string_to_minus_1_integer_binary)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = -1;
	actual_result = ft_strtol("-1", &endptr, 2);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_0_string_to_0_integer_octal)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 0;
	actual_result = ft_strtol("0", &endptr, 8);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_1_string_to_1_integer_octal)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 1;
	actual_result = ft_strtol("1", &endptr, 8);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_10_string_to_8_integer_octal)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 8;
	actual_result = ft_strtol("10", &endptr, 8);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_100_string_to_64_integer_octal)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 64;
	actual_result = ft_strtol("100", &endptr, 8);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_minus_1_string_to_minus_1_integer_octal)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = -1;
	actual_result = ft_strtol("-1", &endptr, 8);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_null_nptr_pointer)
{
	int		expected_result;
	int		actual_result;

	// ACT & ASSERT
	expected_result = 1;
	actual_result = capture_segfault_ft_strtol((int (*)(const char *, char **, int))&ft_strtol, NULL, NULL, 10);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST(test_ft_strtol_null_endptr_pointer)
{
	// ARRANGE
	long expected_result;
	long actual_result;

	// ACT
	expected_result = 42;
	actual_result = ft_strtol("42", NULL, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_0x1A_string_to_26_integer_hex)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 26;
	actual_result = ft_strtol("0x1A", &endptr, 0);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_0X1A_string_to_26_integer_hex)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 26;
	actual_result = ft_strtol("0X1A", &endptr, 0);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_010_string_to_8_integer_octal)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 8;
	actual_result = ft_strtol("010", &endptr, 0);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_10_string_to_10_integer_decimal)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 10;
	actual_result = ft_strtol("10", &endptr, 0);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_123abc_string_to_123_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 123;
	actual_result = ft_strtol("123abc", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	mu_assert_string_eq("abc", endptr);
}

MU_TEST(test_ft_strtol_convert_abc123_string_to_0_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 0;
	actual_result = ft_strtol("abc123", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	mu_assert_string_eq("abc123", endptr);
}

MU_TEST(test_ft_strtol_convert_123_with_spaces_and_invalid_chars)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 123;
	actual_result = ft_strtol("  123xyz", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	mu_assert_string_eq("xyz", endptr);
}

MU_TEST(test_ft_strtol_convert_0x1G_string_to_1_integer_hex)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 1;
	actual_result = ft_strtol("0x1G", &endptr, 16);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	mu_assert_string_eq("G", endptr);
}

MU_TEST(test_ft_strtol_convert_1234567890_string_to_1234567890_integer)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = 1234567890;
	actual_result = ft_strtol("1234567890", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	mu_assert_string_eq("", endptr);
}

MU_TEST(test_ft_strtol_convert_overflow)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = LONG_MAX;
	actual_result = ft_strtol("9223372036854775808", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_underflow)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = LONG_MIN;
	actual_result = ft_strtol("-9223372036854775809", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_large_positive_number)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = LONG_MAX;
	actual_result = ft_strtol("9223372036854775807", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_large_negative_number)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = LONG_MIN;
	actual_result = ft_strtol("-9223372036854775808", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_large_hex_number)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = LONG_MAX;
	actual_result = ft_strtol("0x7FFFFFFFFFFFFFFF", &endptr, 16);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_large_negative_hex_number)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = LONG_MIN;
	actual_result = ft_strtol("-0x8000000000000000", &endptr, 16);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_large_octal_number)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = LONG_MAX;
	actual_result = ft_strtol("0777777777777777777777", &endptr, 8);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_large_negative_octal_number)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = LONG_MIN;
	actual_result = ft_strtol("-01000000000000000000000", &endptr, 8);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_large_binary_number)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = LONG_MAX;
	actual_result = ft_strtol("0111111111111111111111111111111111111111111111111111111111111111", &endptr, 2);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_large_negative_binary_number)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = LONG_MIN;
	actual_result = ft_strtol("-1000000000000000000000000000000000000000000000000000000000000000", &endptr, 2);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_large_number_with_spaces)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = LONG_MAX;
	actual_result = ft_strtol("  9223372036854775807", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_large_negative_number_with_spaces)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = LONG_MIN;
	actual_result = ft_strtol("  -9223372036854775808", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_large_number_with_invalid_chars)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = LONG_MAX;
	actual_result = ft_strtol("9223372036854775807xyz", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	mu_assert_string_eq("xyz", endptr);
}

MU_TEST(test_ft_strtol_convert_large_negative_number_with_invalid_chars)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = LONG_MIN;
	actual_result = ft_strtol("-9223372036854775808xyz", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	mu_assert_string_eq("xyz", endptr);
}

MU_TEST(test_ft_strtol_convert_large_hex_number_with_invalid_chars)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = LONG_MAX;
	actual_result = ft_strtol("0x7FFFFFFFFFFFFFFFxyz", &endptr, 16);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	mu_assert_string_eq("xyz", endptr);
}

MU_TEST(test_ft_strtol_convert_large_negative_hex_number_with_invalid_chars)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = LONG_MIN;
	actual_result = ft_strtol("-0x8000000000000000xyz", &endptr, 16);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	mu_assert_string_eq("xyz", endptr);
}

MU_TEST(test_ft_strtol_convert_large_octal_number_with_invalid_chars)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = LONG_MAX;
	actual_result = ft_strtol("0777777777777777777777xyz", &endptr, 8);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	mu_assert_string_eq("xyz", endptr);
}

MU_TEST(test_ft_strtol_convert_large_negative_octal_number_with_invalid_chars)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = LONG_MIN;
	actual_result = ft_strtol("-01000000000000000000000xyz", &endptr, 8);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	mu_assert_string_eq("xyz", endptr);
}

MU_TEST(test_ft_strtol_convert_large_binary_number_with_invalid_chars)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = LONG_MAX;
	actual_result = ft_strtol("0111111111111111111111111111111111111111111111111111111111111111xyz", &endptr, 2);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	mu_assert_string_eq("xyz", endptr);
}

MU_TEST(test_ft_strtol_convert_large_negative_binary_number_with_invalid_chars)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = LONG_MIN;
	actual_result = ft_strtol("-1000000000000000000000000000000000000000000000000000000000000000xyz", &endptr, 2);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	mu_assert_string_eq("xyz", endptr);
}

MU_TEST(test_ft_strtol_convert_large_number_with_leading_zeros)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = LONG_MAX;
	actual_result = ft_strtol("00000000000000000000000000000000000000000000000000000000000000009223372036854775807", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtol_convert_large_negative_number_with_leading_zeros)
{
	// ARRANGE
	long expected_result;
	long actual_result;
	char *endptr;

	// ACT
	expected_result = LONG_MIN;
	actual_result = ft_strtol("-00000000000000000000000000000000000000000000000000000000000000009223372036854775808", &endptr, 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_strtol_test_suite)
{
	MU_RUN_TEST(test_ft_strtol_convert_0_string_to_0_integer);
	MU_RUN_TEST(test_ft_strtol_convert_1_string_to_1_integer);
	MU_RUN_TEST(test_ft_strtol_convert_10_string_to_10_integer);
	MU_RUN_TEST(test_ft_strtol_convert_100_string_to_100_integer);
	MU_RUN_TEST(test_ft_strtol_convert_1000_string_to_1000_integer);
	MU_RUN_TEST(test_ft_strtol_convert_10000_string_to_10000_integer);
	MU_RUN_TEST(test_ft_strtol_convert_100000_string_to_100000_integer);
	MU_RUN_TEST(test_ft_strtol_convert_1000000_string_to_1000000_integer);
	MU_RUN_TEST(test_ft_strtol_convert_10000000_string_to_10000000_integer);
	MU_RUN_TEST(test_ft_strtol_convert_100000000_string_to_100000000_integer);
	MU_RUN_TEST(test_ft_strtol_convert_1000000000_string_to_1000000000_integer);
	MU_RUN_TEST(test_ft_strtol_convert_minus_1_string_to_minus_1_integer);
	MU_RUN_TEST(test_ft_strtol_convert_minus_10_string_to_minus_10_integer);
	MU_RUN_TEST(test_ft_strtol_convert_minus_100_string_to_minus_100_integer);
	MU_RUN_TEST(test_ft_strtol_convert_minus_1000_string_to_minus_1000_integer);
	MU_RUN_TEST(test_ft_strtol_convert_minus_10000_string_to_minus_10000_integer);
	MU_RUN_TEST(test_ft_strtol_convert_minus_100000_string_to_minus_100000_integer);
	MU_RUN_TEST(test_ft_strtol_convert_minus_1000000_string_to_minus_1000000_integer);
	MU_RUN_TEST(test_ft_strtol_convert_minus_10000000_string_to_minus_10000000_integer);
	MU_RUN_TEST(test_ft_strtol_convert_minus_100000000_string_to_minus_100000000_integer);
	MU_RUN_TEST(test_ft_strtol_convert_minus_1000000000_string_to_minus_1000000000_integer);
	MU_RUN_TEST(test_ft_strtol_convert_minint_string_to_minint_integer);
	MU_RUN_TEST(test_ft_strtol_convert_maxint_string_to_maxint_integer);
	MU_RUN_TEST(test_ft_strtol_convert_42_with_spaces_string_to_42_integer);
	MU_RUN_TEST(test_ft_strtol_convert_42_signal_after_spaces_string_to_42_integer);
	MU_RUN_TEST(test_ft_strtol_convert_42_signal_surrounded_by_spaces_string_to_42_integer);
	MU_RUN_TEST(test_ft_strtol_convert_42_signal_before_spaces_string_to_42_integer);
	MU_RUN_TEST(test_ft_strtol_convert_minus_42_signal_after_spaces_string_to_minus_42_integer);
	MU_RUN_TEST(test_ft_strtol_convert_minus_42_signal_surrounded_by_spaces_string_to_minus_42_integer);
	MU_RUN_TEST(test_ft_strtol_convert_minus_42_signal_before_spaces_string_to_minus_42_integer);
	MU_RUN_TEST(test_ft_strtol_convert_42_more_than_one_signal_string_to_42_integer);
	MU_RUN_TEST(test_ft_strtol_convert_minus_42_more_than_one_signal_string_to_minus_42_integer);
	MU_RUN_TEST(test_ft_strtol_convert_0_string_to_0_integer_hex);
	MU_RUN_TEST(test_ft_strtol_convert_1_string_to_1_integer_hex);
	MU_RUN_TEST(test_ft_strtol_convert_A_string_to_10_integer_hex);
	MU_RUN_TEST(test_ft_strtol_convert_10_string_to_16_integer_hex);
	MU_RUN_TEST(test_ft_strtol_convert_100_string_to_256_integer_hex);
	MU_RUN_TEST(test_ft_strtol_convert_minus_1_string_to_minus_1_integer_hex);
	MU_RUN_TEST(test_ft_strtol_convert_0_string_to_0_integer_binary);
	MU_RUN_TEST(test_ft_strtol_convert_1_string_to_1_integer_binary);
	MU_RUN_TEST(test_ft_strtol_convert_10_string_to_2_integer_binary);
	MU_RUN_TEST(test_ft_strtol_convert_100_string_to_4_integer_binary);
	MU_RUN_TEST(test_ft_strtol_convert_minus_1_string_to_minus_1_integer_binary);
	MU_RUN_TEST(test_ft_strtol_convert_0_string_to_0_integer_octal);
	MU_RUN_TEST(test_ft_strtol_convert_1_string_to_1_integer_octal);
	MU_RUN_TEST(test_ft_strtol_convert_10_string_to_8_integer_octal);
	MU_RUN_TEST(test_ft_strtol_convert_100_string_to_64_integer_octal);
	MU_RUN_TEST(test_ft_strtol_convert_minus_1_string_to_minus_1_integer_octal);
	MU_RUN_TEST(test_ft_strtol_null_nptr_pointer);
	MU_RUN_TEST(test_ft_strtol_null_endptr_pointer);
	MU_RUN_TEST(test_ft_strtol_convert_0x1A_string_to_26_integer_hex);
	MU_RUN_TEST(test_ft_strtol_convert_0X1A_string_to_26_integer_hex);
	MU_RUN_TEST(test_ft_strtol_convert_010_string_to_8_integer_octal);
	MU_RUN_TEST(test_ft_strtol_convert_10_string_to_10_integer_decimal);
	MU_RUN_TEST(test_ft_strtol_convert_123abc_string_to_123_integer);
	MU_RUN_TEST(test_ft_strtol_convert_abc123_string_to_0_integer);
	MU_RUN_TEST(test_ft_strtol_convert_123_with_spaces_and_invalid_chars);
	MU_RUN_TEST(test_ft_strtol_convert_0x1G_string_to_1_integer_hex);
	MU_RUN_TEST(test_ft_strtol_convert_1234567890_string_to_1234567890_integer);
	MU_RUN_TEST(test_ft_strtol_convert_overflow);
	MU_RUN_TEST(test_ft_strtol_convert_underflow);
	MU_RUN_TEST(test_ft_strtol_convert_large_positive_number);
	MU_RUN_TEST(test_ft_strtol_convert_large_negative_number);
	MU_RUN_TEST(test_ft_strtol_convert_large_hex_number);
	MU_RUN_TEST(test_ft_strtol_convert_large_negative_hex_number);
	MU_RUN_TEST(test_ft_strtol_convert_large_octal_number);
	MU_RUN_TEST(test_ft_strtol_convert_large_negative_octal_number);
	MU_RUN_TEST(test_ft_strtol_convert_large_binary_number);
	MU_RUN_TEST(test_ft_strtol_convert_large_negative_binary_number);
	MU_RUN_TEST(test_ft_strtol_convert_large_number_with_spaces);
	MU_RUN_TEST(test_ft_strtol_convert_large_negative_number_with_spaces);
	MU_RUN_TEST(test_ft_strtol_convert_large_number_with_invalid_chars);
	MU_RUN_TEST(test_ft_strtol_convert_large_negative_number_with_invalid_chars);
	MU_RUN_TEST(test_ft_strtol_convert_large_hex_number_with_invalid_chars);
	MU_RUN_TEST(test_ft_strtol_convert_large_negative_hex_number_with_invalid_chars);
	MU_RUN_TEST(test_ft_strtol_convert_large_octal_number_with_invalid_chars);
	MU_RUN_TEST(test_ft_strtol_convert_large_negative_octal_number_with_invalid_chars);
	MU_RUN_TEST(test_ft_strtol_convert_large_binary_number_with_invalid_chars);
	MU_RUN_TEST(test_ft_strtol_convert_large_negative_binary_number_with_invalid_chars);
	MU_RUN_TEST(test_ft_strtol_convert_large_number_with_leading_zeros);
	MU_RUN_TEST(test_ft_strtol_convert_large_negative_number_with_leading_zeros);
}

int	main(void) {
	MU_RUN_SUITE(ft_strtol_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
