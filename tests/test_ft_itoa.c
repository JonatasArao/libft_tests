/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:44:42 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/23 17:05:42 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include "minunit.h"

char	*ft_itoa(int n);

extern int mock_malloc_memset_active;

extern int mock_malloc_failure_active;

int capture_segfault_ft_itoa(char *(*f)(int), int n)
{
	pid_t pid = fork();
	if (pid == 0)
	{
		// Child process executes the test
		f(n);
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

MU_TEST(test_ft_itoa_is_null_terminated)
{
	// ARRANGE
	char	*actual_result;

	// ACT
	actual_result = ft_itoa(42);
	if (!actual_result) {
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	mu_assert(actual_result[2] == '\0', "Expected the duplicated string to be null-terminated");

	// CLEANUP
	free(actual_result);
}

MU_TEST(test_ft_itoa_convert_0_integer_to_0_string)
{
	// ARRANGE
	char *expected_result;
	char *actual_result;

	// ACT
	expected_result = strdup("0");
	if (!expected_result)
	{
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_itoa(0);
	if (!actual_result)
	{
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	if (expected_result[2] == actual_result[2])
		mu_assert_string_eq(expected_result, actual_result);
	else
		mu_fail("Incorrect allocation size. Expected was 2 bytes");

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_itoa_convert_1_integer_to_1_string)
{
	// ARRANGE
	char *expected_result;
	char *actual_result;

	// ACT
	expected_result = strdup("1");
	if (!expected_result)
	{
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_itoa(1);
	if (!actual_result)
	{
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	if (expected_result[2] == actual_result[2])
		mu_assert_string_eq(expected_result, actual_result);
	else
		mu_fail("Incorrect allocation size. Expected was 2 bytes");

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_itoa_convert_10_integer_to_10_string)
{
	// ARRANGE
	char *expected_result;
	char *actual_result;

	// ACT
	expected_result = strdup("10");
	if (!expected_result)
	{
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_itoa(10);
	if (!actual_result)
	{
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	if (expected_result[3] == actual_result[3])
		mu_assert_string_eq(expected_result, actual_result);
	else
		mu_fail("Incorrect allocation size. Expected was 3 bytes");

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_itoa_convert_100_integer_to_100_string)
{
	// ARRANGE
	char *expected_result;
	char *actual_result;

	// ACT
	expected_result = strdup("100");
	if (!expected_result)
	{
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_itoa(100);
	if (!actual_result)
	{
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	if (expected_result[4] == actual_result[4])
		mu_assert_string_eq(expected_result, actual_result);
	else
		mu_fail("Incorrect allocation size. Expected was 4 bytes");

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_itoa_convert_1000_integer_to_1000_string)
{
	// ARRANGE
	char *expected_result;
	char *actual_result;

	// ACT
	expected_result = strdup("1000");
	if (!expected_result)
	{
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_itoa(1000);
	if (!actual_result)
	{
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	if (expected_result[5] == actual_result[5])
		mu_assert_string_eq(expected_result, actual_result);
	else
		mu_fail("Incorrect allocation size. Expected was 5 bytes");

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_itoa_convert_10000_integer_to_10000_string)
{
	// ARRANGE
	char *expected_result;
	char *actual_result;

	// ACT
	expected_result = strdup("10000");
	if (!expected_result)
	{
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_itoa(10000);
	if (!actual_result)
	{
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	if (expected_result[6] == actual_result[6])
		mu_assert_string_eq(expected_result, actual_result);
	else
		mu_fail("Incorrect allocation size. Expected was 6 bytes");

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_itoa_convert_100000_integer_to_100000_string)
{
	// ARRANGE
	char *expected_result;
	char *actual_result;

	// ACT
	expected_result = strdup("100000");
	if (!expected_result)
	{
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_itoa(100000);
	if (!actual_result)
	{
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	if (expected_result[7] == actual_result[7])
		mu_assert_string_eq(expected_result, actual_result);
	else
		mu_fail("Incorrect allocation size. Expected was 7 bytes");

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_itoa_convert_1000000_integer_to_1000000_string)
{
	// ARRANGE
	char *expected_result;
	char *actual_result;

	// ACT
	expected_result = strdup("1000000");
	if (!expected_result)
	{
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_itoa(1000000);
	if (!actual_result)
	{
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	if (expected_result[8] == actual_result[8])
		mu_assert_string_eq(expected_result, actual_result);
	else
		mu_fail("Incorrect allocation size. Expected was 8 bytes");

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_itoa_convert_10000000_integer_to_10000000_string)
{
	// ARRANGE
	char *expected_result;
	char *actual_result;

	// ACT
	expected_result = strdup("10000000");
	if (!expected_result)
	{
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_itoa(10000000);
	if (!actual_result)
	{
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	if (expected_result[9] == actual_result[9])
		mu_assert_string_eq(expected_result, actual_result);
	else
		mu_fail("Incorrect allocation size. Expected was 9 bytes");

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_itoa_convert_100000000_integer_to_100000000_string)
{
	// ARRANGE
	char *expected_result;
	char *actual_result;

	// ACT
	expected_result = strdup("100000000");
	if (!expected_result)
	{
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_itoa(100000000);
	if (!actual_result)
	{
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	if (expected_result[10] == actual_result[10])
		mu_assert_string_eq(expected_result, actual_result);
	else
		mu_fail("Incorrect allocation size. Expected was 10 bytes");

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_itoa_convert_1000000000_integer_to_1000000000_string)
{
	// ARRANGE
	char *expected_result;
	char *actual_result;

	// ACT
	expected_result = strdup("1000000000");
	if (!expected_result)
	{
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_itoa(1000000000);
	if (!actual_result)
	{
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	if (expected_result[11] == actual_result[11])
		mu_assert_string_eq(expected_result, actual_result);
	else
		mu_fail("Incorrect allocation size. Expected was 11 bytes");

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_itoa_convert_minus_1_integer_to_minus_1_string)
{
	// ARRANGE
	char *expected_result;
	char *actual_result;

	// ACT
	expected_result = strdup("-1");
	if (!expected_result)
	{
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_itoa(-1);
	if (!actual_result)
	{
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	if (expected_result[3] == actual_result[3])
		mu_assert_string_eq(expected_result, actual_result);
	else
		mu_fail("Incorrect allocation size. Expected was 3 bytes");

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_itoa_convert_minus_10_integer_to_minus_10_string)
{
	// ARRANGE
	char *expected_result;
	char *actual_result;

	// ACT
	expected_result = strdup("-10");
	if (!expected_result)
	{
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_itoa(-10);
	if (!actual_result)
	{
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	if (expected_result[4] == actual_result[4])
		mu_assert_string_eq(expected_result, actual_result);
	else
		mu_fail("Incorrect allocation size. Expected was 4 bytes");

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_itoa_convert_minus_100_integer_to_minus_100_string)
{
	// ARRANGE
	char *expected_result;
	char *actual_result;

	// ACT
	expected_result = strdup("-100");
	if (!expected_result)
	{
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_itoa(-100);
	if (!actual_result)
	{
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	if (expected_result[5] == actual_result[5])
		mu_assert_string_eq(expected_result, actual_result);
	else
		mu_fail("Incorrect allocation size. Expected was 5 bytes");

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_itoa_convert_minus_1000_integer_to_minus_1000_string)
{
	// ARRANGE
	char *expected_result;
	char *actual_result;

	// ACT
	expected_result = strdup("-1000");
	if (!expected_result)
	{
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_itoa(-1000);
	if (!actual_result)
	{
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	if (expected_result[6] == actual_result[6])
		mu_assert_string_eq(expected_result, actual_result);
	else
		mu_fail("Incorrect allocation size. Expected was 6 bytes");

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_itoa_convert_minus_10000_integer_to_minus_10000_string)
{
	// ARRANGE
	char *expected_result;
	char *actual_result;

	// ACT
	expected_result = strdup("-10000");
	if (!expected_result)
	{
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_itoa(-10000);
	if (!actual_result)
	{
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	if (expected_result[7] == actual_result[7])
		mu_assert_string_eq(expected_result, actual_result);
	else
		mu_fail("Incorrect allocation size. Expected was 7 bytes");

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_itoa_convert_minus_100000_integer_to_minus_100000_string)
{
	// ARRANGE
	char *expected_result;
	char *actual_result;

	// ACT
	expected_result = strdup("-100000");
	if (!expected_result)
	{
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_itoa(-100000);
	if (!actual_result)
	{
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	if (expected_result[8] == actual_result[8])
		mu_assert_string_eq(expected_result, actual_result);
	else
		mu_fail("Incorrect allocation size. Expected was 8 bytes");

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_itoa_convert_minus_1000000_integer_to_minus_1000000_string)
{
	// ARRANGE
	char *expected_result;
	char *actual_result;

	// ACT
	expected_result = strdup("-1000000");
	if (!expected_result)
	{
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_itoa(-1000000);
	if (!actual_result)
	{
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	if (expected_result[9] == actual_result[9])
		mu_assert_string_eq(expected_result, actual_result);
	else
		mu_fail("Incorrect allocation size. Expected was 9 bytes");

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_itoa_convert_minus_10000000_integer_to_minus_10000000_string)
{
	// ARRANGE
	char *expected_result;
	char *actual_result;

	// ACT
	expected_result = strdup("-10000000");
	if (!expected_result)
	{
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_itoa(-10000000);
	if (!actual_result)
	{
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	if (expected_result[10] == actual_result[10])
		mu_assert_string_eq(expected_result, actual_result);
	else
		mu_fail("Incorrect allocation size. Expected was 10 bytes");

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_itoa_convert_minus_100000000_integer_to_minus_100000000_string)
{
	// ARRANGE
	char *expected_result;
	char *actual_result;

	// ACT
	expected_result = strdup("-100000000");
	if (!expected_result)
	{
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_itoa(-100000000);
	if (!actual_result)
	{
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	if (expected_result[11] == actual_result[11])
		mu_assert_string_eq(expected_result, actual_result);
	else
		mu_fail("Incorrect allocation size. Expected was 11 bytes");

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_itoa_convert_minus_1000000000_integer_to_minus_1000000000_string)
{
	// ARRANGE
	char *expected_result;
	char *actual_result;

	// ACT
	expected_result = strdup("-1000000000");
	if (!expected_result)
	{
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_itoa(-1000000000);
	if (!actual_result)
	{
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	if (expected_result[12] == actual_result[12])
		mu_assert_string_eq(expected_result, actual_result);
	else
		mu_fail("Incorrect allocation size. Expected was 12 bytes");

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_itoa_convert_minint_integer_to_minint_string)
{
	// ARRANGE
	char *expected_result;
	char *actual_result;

	// ACT
	expected_result = strdup("-2147483648");
	if (!expected_result)
	{
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_itoa(-2147483648);
	if (!actual_result)
	{
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	if (expected_result[12] == actual_result[12])
		mu_assert_string_eq(expected_result, actual_result);
	else
		mu_fail("Incorrect allocation size. Expected was 12 bytes");

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_itoa_convert_maxint_integer_to_maxint_string)
{
	// ARRANGE
	char *expected_result;
	char *actual_result;

	// ACT
	expected_result = strdup("2147483647");
	if (!expected_result)
	{
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_itoa(2147483647);
	if (!actual_result)
	{
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	if (expected_result[11] == actual_result[11])
		mu_assert_string_eq(expected_result, actual_result);
	else
		mu_fail("Incorrect allocation size. Expected was 11 bytes");

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_itoa_malloc_fail)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	int		segfaulted;

	// ACT
	expected_result = NULL;
	mock_malloc_failure_active = 1;
	segfaulted = capture_segfault_ft_itoa(&ft_itoa, 42);
	if (!segfaulted)
		actual_result = ft_itoa(42);
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

MU_TEST_SUITE(ft_itoa_test_suite)
{
	MU_RUN_TEST(test_ft_itoa_is_null_terminated);
	MU_RUN_TEST(test_ft_itoa_convert_0_integer_to_0_string);
	MU_RUN_TEST(test_ft_itoa_convert_1_integer_to_1_string);
	MU_RUN_TEST(test_ft_itoa_convert_10_integer_to_10_string);
	MU_RUN_TEST(test_ft_itoa_convert_100_integer_to_100_string);
	MU_RUN_TEST(test_ft_itoa_convert_1000_integer_to_1000_string);
	MU_RUN_TEST(test_ft_itoa_convert_10000_integer_to_10000_string);
	MU_RUN_TEST(test_ft_itoa_convert_100000_integer_to_100000_string);
	MU_RUN_TEST(test_ft_itoa_convert_1000000_integer_to_1000000_string);
	MU_RUN_TEST(test_ft_itoa_convert_10000000_integer_to_10000000_string);
	MU_RUN_TEST(test_ft_itoa_convert_100000000_integer_to_100000000_string);
	MU_RUN_TEST(test_ft_itoa_convert_1000000000_integer_to_1000000000_string);
	MU_RUN_TEST(test_ft_itoa_convert_minus_1_integer_to_minus_1_string);
	MU_RUN_TEST(test_ft_itoa_convert_minus_10_integer_to_minus_10_string);
	MU_RUN_TEST(test_ft_itoa_convert_minus_100_integer_to_minus_100_string);
	MU_RUN_TEST(test_ft_itoa_convert_minus_1000_integer_to_minus_1000_string);
	MU_RUN_TEST(test_ft_itoa_convert_minus_10000_integer_to_minus_10000_string);
	MU_RUN_TEST(test_ft_itoa_convert_minus_100000_integer_to_minus_100000_string);
	MU_RUN_TEST(test_ft_itoa_convert_minus_1000000_integer_to_minus_1000000_string);
	MU_RUN_TEST(test_ft_itoa_convert_minus_10000000_integer_to_minus_10000000_string);
	MU_RUN_TEST(test_ft_itoa_convert_minus_100000000_integer_to_minus_100000000_string);
	MU_RUN_TEST(test_ft_itoa_convert_minus_1000000000_integer_to_minus_1000000000_string);
	MU_RUN_TEST(test_ft_itoa_convert_minint_integer_to_minint_string);
	MU_RUN_TEST(test_ft_itoa_convert_maxint_integer_to_maxint_string);
	MU_RUN_TEST(test_ft_itoa_malloc_fail);
}

int	main(void) {
	mock_malloc_memset_active = 1;
	MU_RUN_SUITE(ft_itoa_test_suite);
	mock_malloc_memset_active = 0;
	MU_REPORT();
	return MU_EXIT_CODE;
}
