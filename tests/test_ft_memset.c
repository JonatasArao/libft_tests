/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:09:39 by jarao-de          #+#    #+#             */
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

void	*ft_memset(void *s, int c, size_t n);

int	capture_segfault_ft_memset(void *(*f)(void *, int, size_t), void *s, int c, size_t n)
{
	pid_t pid = fork();
	if (pid == 0)
	{
		// Child process executes the test
		f(s, c, n);
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

MU_TEST(test_ft_memset_return_s_pointer)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	char	*string;
	char	message[50];

	// ACT
	string = malloc(1);
	if (!string) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = string;
	actual_result = ft_memset(string, 'F', 1);
	snprintf(message, sizeof(message), "%sExpected memory address %p but was %p\n", string, (void *)expected_result, (void *)actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);

	// CLEANUP
	free(string);
}

MU_TEST(test_ft_memset_character_F_zero_times)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	char	*string;

	// ACT
	string = strdup("42");
	if (!string) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = string;
	actual_result = ft_memset(string, 'F', 0);

	// ASSERT
	mu_assert_mem_eq(expected_result, actual_result, 2);

	// CLEANUP
	free(string);
}

MU_TEST(test_ft_memset_character_F_once)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	char	*string;

	// ACT
	string = strdup("42");
	if (!string) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = strdup("F2");
	if (!expected_result) {
		free(string);
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_memset(string, 'F', 1);

	// ASSERT
	mu_assert_mem_eq(expected_result, actual_result, 2);

	// CLEANUP
	free(string);
	free(expected_result);
}

MU_TEST(test_ft_memset_character_F_two_times)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	char	*string;

	// ACT
	string = strdup("42");
	if (!string) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = strdup("FF");
	if (!expected_result) {
		free(string);
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_memset(string, 'F', 2);

	// ASSERT
	mu_assert_mem_eq(expected_result, actual_result, 2);

	// CLEANUP
	free(string);
	free(expected_result);
}

MU_TEST(test_ft_memset_character_F_forty_two_times)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	char	*string;

	// ACT
	string = strdup("forty two forty two forty two forty two fo");
	if (!string) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = strdup("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF");
	if (!expected_result) {
		free(string);
		mu_fail("Memory allocation failed");
		return;
	}
	actual_result = ft_memset(string, 'F', 42);

	// ASSERT
	mu_assert_mem_eq(expected_result, actual_result, 42);

	// CLEANUP
	free(string);
	free(expected_result);
}

MU_TEST(test_ft_memset_null_pointer)
{
	int		expected_result;
	int		actual_result;

	// ACT & ASSERT
	expected_result = 1;
	actual_result = capture_segfault_ft_memset(&ft_memset, NULL, 'F', 1);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST_SUITE(ft_memset_test_suite)
{
	MU_RUN_TEST(test_ft_memset_character_F_zero_times);
	MU_RUN_TEST(test_ft_memset_return_s_pointer);
	MU_RUN_TEST(test_ft_memset_character_F_once);
	MU_RUN_TEST(test_ft_memset_character_F_two_times);
	MU_RUN_TEST(test_ft_memset_character_F_forty_two_times);
	MU_RUN_TEST(test_ft_memset_null_pointer);
}

int	main(void) {
	MU_RUN_SUITE(ft_memset_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
