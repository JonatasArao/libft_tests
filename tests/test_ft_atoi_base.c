/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi_base.c                                :+:      :+:    :+:   */
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
#include "minunit.h"

int	ft_atoi_base(const char *nptr, char *base);

int	capture_segfault_ft_atoi_base(int (*f)(const char *, char *), const char *nptr, char *base)
{
	pid_t pid = fork();
	if (pid == 0)
	{
		// Child process executes the test
		f(nptr, base);
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

MU_TEST(test_ft_atoi_base_convert_0_string_to_0_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_atoi_base("0", "0123456789");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_1_string_to_1_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 1;
	actual_result = ft_atoi_base("1", "0123456789");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_10_string_to_10_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 10;
	actual_result = ft_atoi_base("10", "0123456789");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_100_string_to_100_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 100;
	actual_result = ft_atoi_base("100", "0123456789");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_1000_string_to_1000_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 1000;
	actual_result = ft_atoi_base("1000", "0123456789");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_10000_string_to_10000_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 10000;
	actual_result = ft_atoi_base("10000", "0123456789");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_100000_string_to_100000_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 100000;
	actual_result = ft_atoi_base("100000", "0123456789");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_1000000_string_to_1000000_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 1000000;
	actual_result = ft_atoi_base("1000000", "0123456789");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_10000000_string_to_10000000_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 10000000;
	actual_result = ft_atoi_base("10000000", "0123456789");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_100000000_string_to_100000000_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 100000000;
	actual_result = ft_atoi_base("100000000", "0123456789");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_1000000000_string_to_1000000000_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 1000000000;
	actual_result = ft_atoi_base("1000000000", "0123456789");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_minus_1_string_to_minus_1_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = -1;
	actual_result = ft_atoi_base("-1", "0123456789");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_minus_10_string_to_minus_10_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = -10;
	actual_result = ft_atoi_base("-10", "0123456789");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_minus_100_string_to_minus_100_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = -100;
	actual_result = ft_atoi_base("-100", "0123456789");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_minus_1000_string_to_minus_1000_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = -1000;
	actual_result = ft_atoi_base("-1000", "0123456789");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_minus_10000_string_to_minus_10000_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = -10000;
	actual_result = ft_atoi_base("-10000", "0123456789");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_minus_100000_string_to_minus_100000_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = -100000;
	actual_result = ft_atoi_base("-100000", "0123456789");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_minus_1000000_string_to_minus_1000000_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = -1000000;
	actual_result = ft_atoi_base("-1000000", "0123456789");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_minus_10000000_string_to_minus_10000000_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = -10000000;
	actual_result = ft_atoi_base("-10000000", "0123456789");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_minus_100000000_string_to_minus_100000000_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = -100000000;
	actual_result = ft_atoi_base("-100000000", "0123456789");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_minus_1000000000_string_to_minus_1000000000_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = -1000000000;
	actual_result = ft_atoi_base("-1000000000", "0123456789");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_minint_string_to_minint_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = -2147483648;
	actual_result = ft_atoi_base("-2147483648", "0123456789");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_maxint_string_to_maxint_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 2147483647;
	actual_result = ft_atoi_base("2147483647", "0123456789");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_42_with_spaces_string_to_42_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 42;
	actual_result = ft_atoi_base(" \f\n\r\t\v42", "0123456789");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_42_signal_after_spaces_string_to_42_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 42;
	actual_result = ft_atoi_base(" \f\n\r\t\v+42", "0123456789");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_42_signal_surrounded_by_spaces_string_to_42_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_atoi_base(" \f\n+\r\t\v42", "0123456789");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_42_signal_before_spaces_string_to_42_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_atoi_base("+ \f\n\r\t\v42", "0123456789");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_minus_42_signal_after_spaces_string_to_minus_42_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = -42;
	actual_result = ft_atoi_base(" \f\n\r\t\v-42", "0123456789");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_minus_42_signal_surrounded_by_spaces_string_to_minus_42_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_atoi_base(" \f\n-\r\t\v42", "0123456789");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_minus_42_signal_before_spaces_string_to_minus_42_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_atoi_base("- \f\n\r\t\v42", "0123456789");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_42_more_than_one_signal_string_to_42_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_atoi_base("++42", "0123456789");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_minus_42_more_than_one_signal_string_to_minus_42_integer)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_atoi_base("++42", "0123456789");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_0_string_to_0_integer_hex)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_atoi_base("0", "0123456789ABCDEF");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_1_string_to_1_integer_hex)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 1;
	actual_result = ft_atoi_base("1", "0123456789ABCDEF");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_A_string_to_10_integer_hex)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 10;
	actual_result = ft_atoi_base("A", "0123456789ABCDEF");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_10_string_to_16_integer_hex)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 16;
	actual_result = ft_atoi_base("10", "0123456789ABCDEF");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_100_string_to_256_integer_hex)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 256;
	actual_result = ft_atoi_base("100", "0123456789ABCDEF");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_minus_1_string_to_minus_1_integer_hex)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = -1;
	actual_result = ft_atoi_base("-1", "0123456789ABCDEF");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_0_string_to_0_integer_binary)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_atoi_base("0", "01");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_1_string_to_1_integer_binary)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 1;
	actual_result = ft_atoi_base("1", "01");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_10_string_to_2_integer_binary)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 2;
	actual_result = ft_atoi_base("10", "01");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_100_string_to_4_integer_binary)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 4;
	actual_result = ft_atoi_base("100", "01");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_minus_1_string_to_minus_1_integer_binary)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = -1;
	actual_result = ft_atoi_base("-1", "01");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_0_string_to_0_integer_octal)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_atoi_base("0", "01234567");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_1_string_to_1_integer_octal)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 1;
	actual_result = ft_atoi_base("1", "01234567");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_10_string_to_8_integer_octal)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 8;
	actual_result = ft_atoi_base("10", "01234567");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_100_string_to_64_integer_octal)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 64;
	actual_result = ft_atoi_base("100", "01234567");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_convert_minus_1_string_to_minus_1_integer_octal)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = -1;
	actual_result = ft_atoi_base("-1", "01234567");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_atoi_base_null_nptr_pointer)
{
	int		expected_result;
	int		actual_result;

	// ACT & ASSERT
	expected_result = 1;
	actual_result = capture_segfault_ft_atoi_base(&ft_atoi_base, NULL, "0123456789");
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST(test_ft_atoi_base_null_base_pointer)
{
	int		expected_result;
	int		actual_result;

	// ACT & ASSERT
	expected_result = 1;
	actual_result = capture_segfault_ft_atoi_base(&ft_atoi_base, "42", NULL);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST_SUITE(ft_atoi_base_test_suite)
{
	MU_RUN_TEST(test_ft_atoi_base_convert_0_string_to_0_integer);
	MU_RUN_TEST(test_ft_atoi_base_convert_1_string_to_1_integer);
	MU_RUN_TEST(test_ft_atoi_base_convert_10_string_to_10_integer);
	MU_RUN_TEST(test_ft_atoi_base_convert_100_string_to_100_integer);
	MU_RUN_TEST(test_ft_atoi_base_convert_1000_string_to_1000_integer);
	MU_RUN_TEST(test_ft_atoi_base_convert_10000_string_to_10000_integer);
	MU_RUN_TEST(test_ft_atoi_base_convert_100000_string_to_100000_integer);
	MU_RUN_TEST(test_ft_atoi_base_convert_1000000_string_to_1000000_integer);
	MU_RUN_TEST(test_ft_atoi_base_convert_10000000_string_to_10000000_integer);
	MU_RUN_TEST(test_ft_atoi_base_convert_100000000_string_to_100000000_integer);
	MU_RUN_TEST(test_ft_atoi_base_convert_1000000000_string_to_1000000000_integer);
	MU_RUN_TEST(test_ft_atoi_base_convert_minus_1_string_to_minus_1_integer);
	MU_RUN_TEST(test_ft_atoi_base_convert_minus_10_string_to_minus_10_integer);
	MU_RUN_TEST(test_ft_atoi_base_convert_minus_100_string_to_minus_100_integer);
	MU_RUN_TEST(test_ft_atoi_base_convert_minus_1000_string_to_minus_1000_integer);
	MU_RUN_TEST(test_ft_atoi_base_convert_minus_10000_string_to_minus_10000_integer);
	MU_RUN_TEST(test_ft_atoi_base_convert_minus_100000_string_to_minus_100000_integer);
	MU_RUN_TEST(test_ft_atoi_base_convert_minus_1000000_string_to_minus_1000000_integer);
	MU_RUN_TEST(test_ft_atoi_base_convert_minus_10000000_string_to_minus_10000000_integer);
	MU_RUN_TEST(test_ft_atoi_base_convert_minus_100000000_string_to_minus_100000000_integer);
	MU_RUN_TEST(test_ft_atoi_base_convert_minus_1000000000_string_to_minus_1000000000_integer);
	MU_RUN_TEST(test_ft_atoi_base_convert_minint_string_to_minint_integer);
	MU_RUN_TEST(test_ft_atoi_base_convert_maxint_string_to_maxint_integer);
	MU_RUN_TEST(test_ft_atoi_base_convert_42_with_spaces_string_to_42_integer);
	MU_RUN_TEST(test_ft_atoi_base_convert_42_signal_after_spaces_string_to_42_integer);
	MU_RUN_TEST(test_ft_atoi_base_convert_42_signal_surrounded_by_spaces_string_to_42_integer);
	MU_RUN_TEST(test_ft_atoi_base_convert_42_signal_before_spaces_string_to_42_integer);
	MU_RUN_TEST(test_ft_atoi_base_convert_minus_42_signal_after_spaces_string_to_minus_42_integer);
	MU_RUN_TEST(test_ft_atoi_base_convert_minus_42_signal_surrounded_by_spaces_string_to_minus_42_integer);
	MU_RUN_TEST(test_ft_atoi_base_convert_minus_42_signal_before_spaces_string_to_minus_42_integer);
	MU_RUN_TEST(test_ft_atoi_base_convert_42_more_than_one_signal_string_to_42_integer);
	MU_RUN_TEST(test_ft_atoi_base_convert_minus_42_more_than_one_signal_string_to_minus_42_integer);
	MU_RUN_TEST(test_ft_atoi_base_convert_0_string_to_0_integer_hex);
	MU_RUN_TEST(test_ft_atoi_base_convert_1_string_to_1_integer_hex);
	MU_RUN_TEST(test_ft_atoi_base_convert_A_string_to_10_integer_hex);
	MU_RUN_TEST(test_ft_atoi_base_convert_10_string_to_16_integer_hex);
	MU_RUN_TEST(test_ft_atoi_base_convert_100_string_to_256_integer_hex);
	MU_RUN_TEST(test_ft_atoi_base_convert_minus_1_string_to_minus_1_integer_hex);
	MU_RUN_TEST(test_ft_atoi_base_convert_0_string_to_0_integer_binary);
	MU_RUN_TEST(test_ft_atoi_base_convert_1_string_to_1_integer_binary);
	MU_RUN_TEST(test_ft_atoi_base_convert_10_string_to_2_integer_binary);
	MU_RUN_TEST(test_ft_atoi_base_convert_100_string_to_4_integer_binary);
	MU_RUN_TEST(test_ft_atoi_base_convert_minus_1_string_to_minus_1_integer_binary);
	MU_RUN_TEST(test_ft_atoi_base_convert_0_string_to_0_integer_octal);
	MU_RUN_TEST(test_ft_atoi_base_convert_1_string_to_1_integer_octal);
	MU_RUN_TEST(test_ft_atoi_base_convert_10_string_to_8_integer_octal);
	MU_RUN_TEST(test_ft_atoi_base_convert_100_string_to_64_integer_octal);
	MU_RUN_TEST(test_ft_atoi_base_convert_minus_1_string_to_minus_1_integer_octal);
	MU_RUN_TEST(test_ft_atoi_base_null_nptr_pointer);
	MU_RUN_TEST(test_ft_atoi_base_null_base_pointer);
}

int	main(void) {
	MU_RUN_SUITE(ft_atoi_base_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
