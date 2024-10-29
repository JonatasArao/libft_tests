/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:43:35 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/29 17:30:23 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include "minunit.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size);

int capture_segfault_ft_strlcat(size_t (*f)(char *, const char *, size_t), char *dst, const char *src, size_t size)
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

MU_TEST(test_ft_strlcat_forty_two_assignment)
{
	// ARRANGE
	char	expected_result[10];
	char	actual_result[10];

	// ACT
	strcpy(expected_result, "forty two");
	strcpy(actual_result, "forty ");
	ft_strlcat(actual_result, "two", 10);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlcat_forty_two_return)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	char	dst[10];

	// ACT
	expected_result = 9;
	strcpy(dst, "forty ");
	actual_result = ft_strlcat(dst, "two", 10);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlcat_size_equal_zero_assignment)
{
	// ARRANGE
	char	expected_result[7];
	char	actual_result[7];

	// ACT
	strcpy(expected_result, "Ecole ");
	strcpy(actual_result, "Ecole ");
	ft_strlcat(actual_result, "42", 0);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlcat_size_equal_zero_return)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	char	dst[7];

	// ACT
	expected_result = 2;
	strcpy(dst, "Ecole ");
	actual_result = ft_strlcat(dst, "42", 0);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlcat_size_larger_than_src_size_plus_dst_size_assignment)
{
	// ARRANGE
	char	expected_result[20];
	char	actual_result[20];

	// ACT
	strcpy(expected_result, "Ecole 42");
	strcpy(actual_result, "Ecole ");
	ft_strlcat(actual_result, "42", 20);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlcat_size_larger_than_src_size_plus_dst_size_return)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	char	dst[20];

	// ACT
	expected_result = 8;
	strcpy(dst, "Ecole ");
	actual_result = ft_strlcat(dst, "42", 20);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlcat_size_smaller_than_src_size_plus_dst_size_assignment)
{
	// ARRANGE
	char	expected_result[10];
	char	actual_result[10];

	// ACT
	strcpy(expected_result, "Ecole 42");
	strcpy(actual_result, "Ecole ");
	ft_strlcat(actual_result, "42 forty two", 9);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlcat_size_smaller_than_src_size_plus_dst_size_return)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	char	dst[10];

	// ACT
	expected_result = 18;
	strcpy(dst, "Ecole ");
	actual_result = ft_strlcat(dst, "42 forty two", 9);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlcat_size_equal_src_size_plus_dst_size_assignment)
{
	// ARRANGE
	char	expected_result[10];
	char	actual_result[10];

	// ACT
	strcpy(expected_result, "Ecole 4");
	strcpy(actual_result, "Ecole ");
	ft_strlcat(actual_result, "42", 8);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlcat_size_equal_src_size_plus_dst_size_return)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	char	dst[10];

	// ACT
	expected_result = 8;
	strcpy(dst, "Ecole ");
	actual_result = ft_strlcat(dst, "42", 8);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlcat_size_smaller_than_dst_size_assignment)
{
	// ARRANGE
	char	expected_result[7];
	char	actual_result[7];

	// ACT
	strcpy(expected_result, "Ecole ");
	strcpy(actual_result, "Ecole ");
	ft_strlcat(actual_result, "42", 2);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlcat_size_smaller_than_dst_size_return)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	char	dst[7];

	// ACT
	expected_result = 4;
	strcpy(dst, "Ecole ");
	actual_result = ft_strlcat(dst, "42", 2);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlcat_size_equal_dst_size_assignment)
{
	// ARRANGE
	char	expected_result[9];
	char	actual_result[9];

	// ACT
	strcpy(expected_result, "Ecole ");
	strcpy(actual_result, "Ecole ");
	ft_strlcat(actual_result, "42", 6);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlcat_size_equal_dst_size_return)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	char	dst[9];

	// ACT
	expected_result = 8;
	strcpy(dst, "Ecole ");
	actual_result = ft_strlcat(dst, "42", 6);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlcat_empty_src_assignment)
{
	// ARRANGE
	char	expected_result[9];
	char	actual_result[9];

	// ACT
	strcpy(expected_result, "Ecole 42");
	strcpy(actual_result, "Ecole 42");
	ft_strlcat(actual_result, "", 9);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlcat_empty_src_return)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	char	dst[9];

	// ACT
	expected_result = 8;
	strcpy(dst, "Ecole 42");
	actual_result = ft_strlcat(dst, "", 9);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlcat_empty_dst_assignment)
{
	// ARRANGE
	char	expected_result[9];
	char	actual_result[9];

	// ACT
	strcpy(expected_result, "Ecole 42");
	ft_strlcat(actual_result, "Ecole 42", 9);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlcat_empty_dst_return)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	char	dst[9];

	// ACT
	expected_result = 8;
	actual_result = ft_strlcat(dst, "Ecole 42", 9);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlcat_empty_src_and_dst_assignment)
{
	// ARRANGE
	char	expected_result[1];
	char	actual_result[1];

	// ACT
	strcpy(expected_result, "");
	strcpy(actual_result, "");
	ft_strlcat(actual_result, "", 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlcat_empty_src_and_dst_return)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	char	dst[1];

	// ACT
	expected_result = 0;
	strcpy(dst, "");
	actual_result = ft_strlcat(dst, "", 1);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlcat_null_src)
{
	int		expected_result;
	int		actual_result;
	char	dst[2];

	// ACT & ASSERT
	expected_result = 1;
	actual_result = capture_segfault_ft_strlcat(&ft_strlcat, dst, NULL, 3);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST(test_ft_strlcat_null_dst)
{
	int		expected_result;
	int		actual_result;

	// ACT & ASSERT
	expected_result = 1;
	actual_result = capture_segfault_ft_strlcat(&ft_strlcat, NULL, "", 3);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST_SUITE(ft_strlcat_test_suite)
{
	MU_RUN_TEST(test_ft_strlcat_forty_two_assignment);
	MU_RUN_TEST(test_ft_strlcat_forty_two_return);
	MU_RUN_TEST(test_ft_strlcat_size_equal_zero_assignment);
	MU_RUN_TEST(test_ft_strlcat_size_equal_zero_return);
	MU_RUN_TEST(test_ft_strlcat_size_larger_than_src_size_plus_dst_size_assignment);
	MU_RUN_TEST(test_ft_strlcat_size_larger_than_src_size_plus_dst_size_return);
	MU_RUN_TEST(test_ft_strlcat_size_smaller_than_src_size_plus_dst_size_assignment);
	MU_RUN_TEST(test_ft_strlcat_size_smaller_than_src_size_plus_dst_size_return);
	MU_RUN_TEST(test_ft_strlcat_size_equal_src_size_plus_dst_size_assignment);
	MU_RUN_TEST(test_ft_strlcat_size_equal_src_size_plus_dst_size_return);
	MU_RUN_TEST(test_ft_strlcat_size_smaller_than_dst_size_assignment);
	MU_RUN_TEST(test_ft_strlcat_size_smaller_than_dst_size_return);
	MU_RUN_TEST(test_ft_strlcat_size_equal_dst_size_assignment);
	MU_RUN_TEST(test_ft_strlcat_size_equal_dst_size_return);
	MU_RUN_TEST(test_ft_strlcat_empty_src_assignment);
	MU_RUN_TEST(test_ft_strlcat_empty_src_return);
	MU_RUN_TEST(test_ft_strlcat_empty_dst_assignment);
	MU_RUN_TEST(test_ft_strlcat_empty_dst_return);
	MU_RUN_TEST(test_ft_strlcat_empty_src_and_dst_assignment);
	MU_RUN_TEST(test_ft_strlcat_empty_src_and_dst_return);
	MU_RUN_TEST(test_ft_strlcat_null_src);
	MU_RUN_TEST(test_ft_strlcat_null_dst);
}

int	main(void) {
	MU_RUN_SUITE(ft_strlcat_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
