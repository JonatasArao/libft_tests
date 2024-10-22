/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 08:54:33 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/22 16:48:28 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include "minunit.h"

void	*ft_memcpy(void *dest, const void *src, size_t n);

int capture_segfault_ft_memcpy(void *(*f)(void *, const void *, size_t), void *dst, const void *src, size_t n)
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

MU_TEST(test_ft_memcpy_forty_two)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	void	*dest;

	// ACT
	expected_result = strdup("forty two");
	dest = malloc(10);
	actual_result = ft_memcpy(dest, expected_result, 10);

	// ASSERT
	if (actual_result == dest)
		mu_assert_mem_eq(expected_result, actual_result, 10);
	else
		mu_fail("function must return a pointer to dest.");

	// CLEANUP
	free(expected_result);
	free(dest);
}

MU_TEST(test_ft_memcpy_zero_bytes)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	void	*src;
	void	*dest;

	// ACT
	expected_result = strdup("forty two");
	src = strdup("FORTY TWO");
	dest = strdup("forty two");
	actual_result = ft_memcpy(dest, src, 0);

	// ASSERT
	if (actual_result == dest)
		mu_assert_mem_eq(expected_result, actual_result, 0);
	else
		mu_fail("function must return a pointer to dest.");

	// CLEANUP
	free(expected_result);
	free(dest);
}

MU_TEST(test_ft_memcpy_dst_larger_than_src)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	void	*dest;

	// ACT
	expected_result = strdup("42 School");
	dest = malloc(20);
	actual_result = ft_memcpy(dest, expected_result, 20);

	// ASSERT
	if (actual_result == dest)
		mu_assert_mem_eq(expected_result, actual_result, 20);
	else
		mu_fail("function must return a pointer to dest.");

	// CLEANUP
	free(expected_result);
	free(dest);
}

MU_TEST(test_ft_memcpy_dst_smaller_than_src)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	void	*dest;

	// ACT
	expected_result = strdup("42");
	dest = malloc(3);
	actual_result = ft_memcpy(dest, expected_result, 3);

	// ASSERT
	if (actual_result == dest)
		mu_assert_mem_eq(expected_result, actual_result, 3);
	else
		mu_fail("function must return a pointer to dest.");

	// CLEANUP
	free(expected_result);
	free(dest);
}

MU_TEST(test_ft_memcpy_empty_src)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	void	*dest;

	// ACT
	expected_result = strdup("");
	dest = malloc(10);
	actual_result = ft_memcpy(dest, expected_result, 10);

	// ASSERT
	if (actual_result == dest)
		mu_assert_mem_eq(expected_result, actual_result, 10);
	else
		mu_fail("function must return a pointer to dest.");

	// CLEANUP
	free(expected_result);
	free(dest);
}

MU_TEST(test_ft_memcpy_one_byte)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	void	*dest;

	// ACT
	expected_result = strdup("4");
	dest = malloc(1);
	actual_result = ft_memcpy(dest, expected_result, 1);

	// ASSERT
	if (actual_result == dest)
		mu_assert_mem_eq(expected_result, actual_result, 1);
	else
		mu_fail("function must return a pointer to dest.");

	// CLEANUP
	free(expected_result);
	free(dest);
}

MU_TEST(test_ft_memcpy_large_block)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	void	*dest;
	size_t	size = 1024 * 1024; // 1 MB

	// ACT
	expected_result = malloc(size);
	memset(expected_result, 'A', size);
	dest = malloc(size);
	actual_result = ft_memcpy(dest, expected_result, size);

	// ASSERT
	if (actual_result == dest)
		mu_assert_mem_eq(expected_result, actual_result, size);
	else
		mu_fail("function must return a pointer to dest.");

	// CLEANUP
	free(expected_result);
	free(dest);
}

MU_TEST(test_ft_memcpy_null_src)
{
	int		expected_result;
	int		actual_result;
	char	dst[2];

	// ACT & ASSERT
	actual_result = 1;
	expected_result = capture_segfault_ft_memcpy(&ft_memcpy, dst, NULL, 3);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST(test_ft_memcpy_null_dst)
{
	int		expected_result;
	int		actual_result;

	// ACT & ASSERT
	actual_result = 1;
	expected_result = capture_segfault_ft_memcpy(&ft_memcpy, NULL, "", 3);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST(test_ft_memcpy_null_dst_null_src)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	void	*dest;
	int		segfaulted;

	// ACT
	expected_result = NULL;
	dest = NULL;
	segfaulted = capture_segfault_ft_memcpy(&ft_memcpy, dest, expected_result, 10);
	if (!segfaulted)
		actual_result = ft_memcpy(dest, expected_result, 10);

	// ASSERT
	if (segfaulted)
		mu_fail("Function should not cause a segmentation fault.");
	else
		mu_assert(actual_result == expected_result, "Expected NULL pointer");
}

MU_TEST_SUITE(ft_memcpy_test_suite)
{
	MU_RUN_TEST(test_ft_memcpy_forty_two);
	MU_RUN_TEST(test_ft_memcpy_zero_bytes);
	MU_RUN_TEST(test_ft_memcpy_dst_larger_than_src);
	MU_RUN_TEST(test_ft_memcpy_dst_smaller_than_src);
	MU_RUN_TEST(test_ft_memcpy_empty_src);
	MU_RUN_TEST(test_ft_memcpy_one_byte);
	MU_RUN_TEST(test_ft_memcpy_large_block);
	MU_RUN_TEST(test_ft_memcpy_null_src);
	MU_RUN_TEST(test_ft_memcpy_null_dst);
	MU_RUN_TEST(test_ft_memcpy_null_dst_null_src);
}

int	main(void) {
	MU_RUN_SUITE(ft_memcpy_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
