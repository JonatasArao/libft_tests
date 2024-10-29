/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:04:18 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/29 17:30:23 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include "minunit.h"

void	*ft_memmove(void *dest, const void *src, size_t n);

int capture_segfault_ft_memmove(void *(*f)(void *, const void *, size_t), void *dst, const void *src, size_t n)
{
	pid_t pid = fork();
	if (pid == 0)
	{
		// Child process executes the test
		f(dst, src, n);
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

MU_TEST(test_ft_memmove_forty_two_string)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	void	*dest;

	// ACT
	expected_result = strdup("forty two");
	if (!expected_result) {
		mu_fail("Memory allocation failed");
		return;
	}
	dest = malloc(10);
	if (!dest) {
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_memmove(dest, "forty two", 10);

	// ASSERT
	if (actual_result == dest)
		mu_assert_mem_eq(expected_result, actual_result, 10);
	else
		mu_fail("function must return a pointer to dest.");

	// CLEANUP
	free(expected_result);
	free(dest);
}

MU_TEST(test_ft_memmove_forty_two_int)
{
	// ARRANGE
	int expected_result = 42;
	int actual_result = 0;
	int *dest;

	// ACT
	dest = malloc(sizeof(int));
	if (!dest) {
		mu_fail("Memory allocation failed");
		return;
	}
	ft_memmove(dest, &expected_result, sizeof(int));
	actual_result = *dest;

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);

	// CLEANUP
	free(dest);
}

MU_TEST(test_ft_memmove_forty_two_long)
{
	// ARRANGE
	long expected_result = 42L;
	long actual_result = 0L;
	long *dest;
	char	message[60];

	// ACT
	dest = malloc(sizeof(long));
	if (!dest) {
		mu_fail("Memory allocation failed");
		return;
	}
	ft_memmove(dest, &expected_result, sizeof(long));
	actual_result = *dest;
	snprintf(message, sizeof(message), "%ld expected but was %ld\n", expected_result, actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);

	// CLEANUP
	free(dest);
}

MU_TEST(test_ft_memmove_size_zero)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	void	*dest;
	char	*string;

	// ACT
	string = strdup("forty two");
	if (!string) {
		mu_fail("Memory allocation failed");
		return;
	}
	dest = strdup("forty two");
	if (!dest) {
		free(string);
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = string;
	actual_result = ft_memmove(dest, "42", 0);

	// ASSERT
	if (actual_result == dest)
		mu_assert_mem_eq(expected_result, actual_result, 10);
	else
		mu_fail("function must return a pointer to dest.");

	// CLEANUP
	free(expected_result);
	free(dest);
}

MU_TEST(test_ft_memmove_overlap)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	void	*dest;
	char	src[11];

	// ACT
	strcpy(src, "1234567890");
	expected_result = strdup("1234123456");
	if (!expected_result) {
		mu_fail("Memory allocation failed");
		return;
	}
	dest = src + 4;
	actual_result = ft_memmove(dest, src, 6);

	// ASSERT
	if (actual_result == dest)
		mu_assert_mem_eq(expected_result, src, 10);
	else
		mu_fail("function must return a pointer to dest.");

	// CLEANUP
	free(expected_result);
}

MU_TEST(test_ft_memmove_overlap_backward)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	void	*dest;
	char	src[11];

	// ACT
	strcpy(src, "1234567890");
	expected_result = strdup("5678907890");
	if (!expected_result) {
		mu_fail("Memory allocation failed");
		return;
	}
	dest = src;
	actual_result = ft_memmove(dest, src + 4, 6);

	// ASSERT
	if (actual_result == dest)
		mu_assert_mem_eq(expected_result, src, 10);
	else
		mu_fail("function must return a pointer to dest.");

	// CLEANUP
	free(expected_result);
}

MU_TEST(test_ft_memmove_empty_src)
{
	// ARRANGE
	void *expected_result;
	void *actual_result;
	void *dest;

	// ACT
	expected_result = strdup("");
	if (!expected_result) {
		mu_fail("Memory allocation failed");
		return;
	}
	dest = malloc(1);
	if (!dest) {
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_memmove(dest, "", 1);

	// ASSERT
	if (actual_result == dest)
		mu_assert_mem_eq(expected_result, actual_result, 1);
	else
		mu_fail("function must return a pointer to dest.");

	// CLEANUP
	free(expected_result);
	free(dest);
}

MU_TEST(test_ft_memmove_partial_copy)
{
	// ARRANGE
	void *expected_result;
	void *actual_result;
	void *dest;

	// ACT
	expected_result = strdup("forty two");
	if (!expected_result) {
		mu_fail("Memory allocation failed");
		return;
	}
	dest = malloc(5);
	if (!dest) {
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_memmove(dest, "forty two", 5);

	// ASSERT
	if (actual_result == dest)
		mu_assert_mem_eq(expected_result, actual_result, 5);
	else
		mu_fail("function must return a pointer to dest.");

	// CLEANUP
	free(expected_result);
	free(dest);
}

MU_TEST(test_ft_memmove_large_copy)
{
	// ARRANGE
	void *expected_result;
	void *actual_result;
	void *large;
	void *dest;

	// ACT
	large = malloc(1000);
	if (!large) {
		mu_fail("Memory allocation failed");
		return;
	}
	memset(large, 'A', 999);
	((char *)large)[999] = '\0';
	dest = malloc(1000);
	if (!dest) {
		free(large);
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = large;
	actual_result = ft_memmove(dest, large, 1000);

	// ASSERT
	if (actual_result == dest)
		mu_assert_mem_eq(expected_result, actual_result, 1000);
	else
		mu_fail("function must return a pointer to dest.");

	// CLEANUP
	free(expected_result);
	free(dest);
}

MU_TEST(test_ft_memmove_null_src)
{
	int		expected_result;
	int		actual_result;
	char	dst[2];

	// ACT & ASSERT
	expected_result = 1;
	actual_result = capture_segfault_ft_memmove(&ft_memmove, dst, NULL, 3);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST(test_ft_memmove_null_dst)
{
	int		expected_result;
	int		actual_result;

	// ACT & ASSERT
	expected_result = 1;
	actual_result = capture_segfault_ft_memmove(&ft_memmove, NULL, "", 3);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST(test_ft_memmove_null_dst_null_src)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	void	*dest;
	int		segfaulted;

	// ACT
	expected_result = NULL;
	dest = NULL;
	segfaulted = capture_segfault_ft_memmove(&ft_memmove, dest, expected_result, 10);
	if (!segfaulted)
		actual_result = ft_memmove(dest, expected_result, 10);

	// ASSERT
	if (segfaulted)
		mu_fail("Function should not cause a segmentation fault.");
	else
		mu_assert(actual_result == expected_result, "Expected NULL pointer");

	// CLEANUP
	free(expected_result);
	free(dest);
}

MU_TEST_SUITE(ft_memmove_test_suite)
{
	MU_RUN_TEST(test_ft_memmove_forty_two_string);
	MU_RUN_TEST(test_ft_memmove_forty_two_int);
	MU_RUN_TEST(test_ft_memmove_forty_two_long);
	MU_RUN_TEST(test_ft_memmove_size_zero);
	MU_RUN_TEST(test_ft_memmove_overlap);
	MU_RUN_TEST(test_ft_memmove_overlap_backward);
	MU_RUN_TEST(test_ft_memmove_empty_src);
	MU_RUN_TEST(test_ft_memmove_partial_copy);
	MU_RUN_TEST(test_ft_memmove_large_copy);
	MU_RUN_TEST(test_ft_memmove_null_src);
	MU_RUN_TEST(test_ft_memmove_null_dst);
	MU_RUN_TEST(test_ft_memmove_null_dst_null_src);
}

int	main(void) {
	MU_RUN_SUITE(ft_memmove_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
