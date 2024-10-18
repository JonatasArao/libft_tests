/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:53:38 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/18 20:09:03 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include "minunit.h"

void	ft_bzero(void *s, size_t n);

int	capture_segfault_ft_bzero(void (*f)(void *, size_t), void *s, size_t n)
{
	pid_t pid = fork();
	if (pid == 0)
	{
		// Child process executes the test
		f(s, n);
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

MU_TEST(test_ft_bzero_zero_bytes)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;

	// ACT
	expected_result = strdup("forty two");
	if (!expected_result) {
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = strdup("forty two");
	if (!actual_result) {
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}
	ft_bzero(actual_result, 0);

	// ASSERT
	mu_assert_mem_eq(expected_result, actual_result, 9);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_bzero_one_byte)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;

	// ACT
	expected_result = strdup("\0");
	if (!expected_result) {
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = strdup("42");
	if (!actual_result) {
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}
	ft_bzero(actual_result, 1);

	// ASSERT
	mu_assert_mem_eq(expected_result, actual_result, 1);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_bzero_two_bytes)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;

	// ACT
	expected_result = malloc(42);
	if (!expected_result) {
		mu_fail("Memory allocation failed");
		return;
	}
	memset(expected_result, 0, 42);
	actual_result = strdup("forty two forty two forty two forty two fo");
	if (!actual_result) {
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}
	ft_bzero(actual_result, 42);

	// ASSERT
	mu_assert_mem_eq(expected_result, actual_result, 42);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_bzero_forty_two_bytes)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;

	// ACT
	expected_result = malloc(42);
	if (!expected_result) {
		mu_fail("Memory allocation failed");
		return;
	}
	memset(expected_result, 0, 42);
	actual_result = strdup("forty two forty two forty two forty two fo");
	if (!actual_result) {
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}
	ft_bzero(actual_result, 42);

	// ASSERT
	mu_assert_mem_eq(expected_result, actual_result, 42);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_bzero_entire_string)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;

	// ACT
	expected_result = malloc(9);
	if (!expected_result) {
		mu_fail("Memory allocation failed");
		return;
	}
	memset(expected_result, 0, 9);
	actual_result = strdup("forty two");
	if (!actual_result) {
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}
	ft_bzero(actual_result, 9);

	// ASSERT
	mu_assert_mem_eq(expected_result, actual_result, 9);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_bzero_partial_string)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;

	// ACT
	expected_result = strdup("forty two");
	if (!expected_result) {
		mu_fail("Memory allocation failed");
		return;
	}
	memset(expected_result + 5, 0, 3);
	actual_result = strdup("forty two");
	if (!actual_result) {
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}
	ft_bzero(actual_result + 5, 3);

	// ASSERT
	mu_assert_mem_eq(expected_result, actual_result, 9);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_bzero_null_pointer)
{
	int		expected_result;
	int		actual_result;

	// ACT & ASSERT
	actual_result = 1;
	expected_result = capture_segfault_ft_bzero(&ft_bzero, NULL, 1);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST_SUITE(ft_bzero_test_suite)
{
	MU_RUN_TEST(test_ft_bzero_zero_bytes);
	MU_RUN_TEST(test_ft_bzero_one_byte);
	MU_RUN_TEST(test_ft_bzero_two_bytes);
	MU_RUN_TEST(test_ft_bzero_forty_two_bytes);
	MU_RUN_TEST(test_ft_bzero_entire_string);
	MU_RUN_TEST(test_ft_bzero_partial_string);
	MU_RUN_TEST(test_ft_bzero_null_pointer);
}

int	main(void) {
	MU_RUN_SUITE(ft_bzero_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
