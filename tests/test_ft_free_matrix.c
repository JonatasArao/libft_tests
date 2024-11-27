/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_free_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:26:20 by jarao-de          #+#    #+#             */
/*   Updated: 2024/11/27 10:23:10 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include "minunit.h"

void	*ft_free_matrix(void **matrix, size_t size);

extern int mock_free_counter_active;

extern int mock_free_counter;

int capture_segfault_ft_free_matrix(void *(*f)(void **, size_t), void **matrix, size_t size)
{
	pid_t pid = fork();
	if (pid == 0)
	{
		// Child process executes the test
		f(matrix, size);
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

MU_TEST(test_ft_free_matrix)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	void	**matrix;
	char	message[80];

	// Allocate memory for the matrix
	matrix = malloc(3 * sizeof(void *));
	matrix[0] = malloc(10);
	matrix[1] = malloc(20);
	matrix[2] = NULL;

	// ACT
	mock_free_counter_active = 1;
	mock_free_counter = 0;
	ft_free_matrix(matrix, 3);
	mock_free_counter_active = 0;
	expected_result = 4; // We expect 4 allocations to be freed
	actual_result = mock_free_counter;
	snprintf(message, sizeof(message), "Expected %d memory allocations to be freed, but %d were not freed.\n", expected_result, expected_result - actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);
}

MU_TEST(test_ft_free_matrix_null_matrix)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	void	**matrix = NULL;
	char	message[80];

	// ACT
	mock_free_counter_active = 1;
	mock_free_counter = 0;
	ft_free_matrix(matrix, 0);
	mock_free_counter_active = 0;
	expected_result = 0; // No allocations to be freed
	actual_result = mock_free_counter;
	snprintf(message, sizeof(message), "Expected %d memory allocations to be freed, but %d were not freed.\n", expected_result, expected_result - actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);
}

MU_TEST(test_ft_free_matrix_partial_null)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	void	**matrix;
	char	message[80];

	// Allocate memory for the matrix
	matrix = malloc(3 * sizeof(void *));
	matrix[0] = malloc(10);
	matrix[1] = NULL;
	matrix[2] = malloc(20);

	// ACT
	mock_free_counter_active = 1;
	mock_free_counter = 0;
	ft_free_matrix(matrix, 3);
	mock_free_counter_active = 0;
	expected_result = 4; // We expect 4 allocations to be freed
	actual_result = mock_free_counter;
	snprintf(message, sizeof(message), "Expected %d memory allocations to be freed, but %d were not freed.\n", expected_result, expected_result - actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);
}

MU_TEST(test_ft_free_matrix_segfault)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	void	**matrix;

	// Allocate memory for the matrix
	matrix = malloc(3 * sizeof(void *));
	matrix[0] = malloc(10);
	matrix[1] = malloc(20);
	matrix[2] = NULL;

	// ACT & ASSERT
	expected_result = 1;
	actual_result = capture_segfault_ft_free_matrix(ft_free_matrix, matrix, 4);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST(test_ft_free_matrix_return_null)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	void	**matrix;

	// Allocate memory for the matrix
	matrix = malloc(3 * sizeof(void *));
	matrix[0] = malloc(10);
	matrix[1] = malloc(20);
	matrix[2] = NULL;

	// ACT
	actual_result = ft_free_matrix(matrix, 3);
	expected_result = NULL;

	// ASSERT
	mu_assert(expected_result == actual_result, "Expected return value to be NULL, but it was not.");
}

MU_TEST_SUITE(ft_free_matrix_test_suite)
{
	MU_RUN_TEST(test_ft_free_matrix);
	MU_RUN_TEST(test_ft_free_matrix_null_matrix);
	MU_RUN_TEST(test_ft_free_matrix_partial_null);
	MU_RUN_TEST(test_ft_free_matrix_segfault);
	MU_RUN_TEST(test_ft_free_matrix_return_null);
}

int	main(void) {
	MU_RUN_SUITE(ft_free_matrix_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
