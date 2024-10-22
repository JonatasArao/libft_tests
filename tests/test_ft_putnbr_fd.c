/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putnbr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:43:39 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/22 10:11:24 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "minunit.h"

void	ft_putnbr_fd(int n, int fd);

char* capture_ft_putnbr_fd_output(void (*func)(int, int), int n, int fd)
{
	int pipefd[2];
	ssize_t count;
	char *buffer;
	size_t size = 1024; // Initial buffer size

	// Create a pipe
	if (pipe(pipefd) == -1) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	// Save the original file descriptor of fd
	int fd_backup = dup(fd);

	// Save the original file descriptors of stdout and stderr
	int stdout_backup = dup(1);
	int stderr_backup = dup(2);

	// Redirect fd to the pipe
	dup2(pipefd[1], fd);
	close(pipefd[1]);

	// Close the opposite file descriptor to avoid mixed output
	if (fd == 1)
	{
		close(2); // Close stderr if fd is stdout
	}
	else if (fd == 2)
	{
		close(1); // Close stdout if fd is stderr
	}
	else
	{
		close(1);
		close(2);
	}

	// Call the function whose output we want to capture
	func(n, fd);

	// Restore fd
	fflush(stdout);
	dup2(fd_backup, fd);
	close(fd_backup);

	// Restore stdout and stderr
	dup2(stdout_backup, 1);
	dup2(stderr_backup, 2);
	close(stdout_backup);
	close(stderr_backup);

	// Dynamically allocate the buffer
	buffer = (char*)malloc(size);
	if (buffer == NULL) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	// Read the content from the pipe
	count = read(pipefd[0], buffer, size - 1);
	if (count == -1) {
		perror("read");
		exit(EXIT_FAILURE);
	}
	buffer[count] = '\0';

	// Close the read end of the pipe
	close(pipefd[0]);

	return buffer;
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_0)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("0");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, 0, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_1)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("1");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, 1, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_2)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("2");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, 2, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_3)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("3");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, 3, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_4)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("4");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, 4, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_5)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("5");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, 5, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_6)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("6");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, 6, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_7)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("7");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, 7, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_8)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("8");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, 8, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_9)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("9");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, 9, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_10)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("10");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, 10, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_100)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("100");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, 100, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_1000)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("1000");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, 1000, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_10000)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("10000");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, 10000, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_100000)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("100000");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, 100000, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_1000000)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("1000000");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, 1000000, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_10000000)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("10000000");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, 10000000, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_100000000)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("100000000");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, 100000000, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_1000000000)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("1000000000");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, 1000000000, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_1)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("-1");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, -1, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_2)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("-2");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, -2, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_3)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("-3");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, -3, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_4)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("-4");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, -4, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_5)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("-5");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, -5, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_6)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("-6");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, -6, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_7)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("-7");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, -7, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_8)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("-8");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, -8, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_9)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("-9");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, -9, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_10)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("-10");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, -10, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_100)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("-100");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, -100, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_1000)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("-1000");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, -1000, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_10000)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("-10000");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, -10000, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_100000)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("-100000");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, -100000, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_1000000)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("-1000000");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, -1000000, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_10000000)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("-10000000");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, -10000000, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_100000000)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("-100000000");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, -100000000, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_1000000000)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("-1000000000");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, -1000000000, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_maxint)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("2147483647");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, 2147483647, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stdout_n_equal_minint)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("-2147483648");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, -2147483648, 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stderr_positive)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("42");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, 42, 2);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stderr_negative)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("-42");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, -42, 2);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stderr_n_equal_maxint)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("2147483647");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, 2147483647, 2);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_stderr_n_equal_minint)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("-2147483648");
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, -2147483648, 2);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_file_positive)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	int		file;

	// ACT
	expected_result = strdup("42");
	file = open("test_ft_file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, 42, file);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	if (close(file) == -1)
	{
		perror("close");
		exit(EXIT_FAILURE);
	}
	if (remove("test_ft_file.txt") != 0)
	{
		perror("remove");
		exit(EXIT_FAILURE);
	}
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_file_negative)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	int		file;

	// ACT
	expected_result = strdup("-42");
	file = open("test_ft_file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, -42, file);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	if (close(file) == -1)
	{
		perror("close");
		exit(EXIT_FAILURE);
	}
	if (remove("test_ft_file.txt") != 0)
	{
		perror("remove");
		exit(EXIT_FAILURE);
	}
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_file_maxint)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	int		file;

	// ACT
	expected_result = strdup("2147483647");
	file = open("test_ft_file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, 2147483647, file);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	if (close(file) == -1)
	{
		perror("close");
		exit(EXIT_FAILURE);
	}
	if (remove("test_ft_file.txt") != 0)
	{
		perror("remove");
		exit(EXIT_FAILURE);
	}
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putnbr_fd_file_minint)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	int		file;

	// ACT
	expected_result = strdup("-2147483648");
	file = open("test_ft_file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	actual_result = capture_ft_putnbr_fd_output(&ft_putnbr_fd, -2147483648, file);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	if (close(file) == -1)
	{
		perror("close");
		exit(EXIT_FAILURE);
	}
	if (remove("test_ft_file.txt") != 0)
	{
		perror("remove");
		exit(EXIT_FAILURE);
	}
	free(actual_result);
	free(expected_result);
}

MU_TEST_SUITE(ft_putnbr_fd_test_suite)
{
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_0);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_1);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_2);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_3);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_4);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_5);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_6);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_7);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_8);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_9);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_10);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_100);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_1000);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_10000);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_100000);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_1000000);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_10000000);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_100000000);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_1000000000);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_1);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_2);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_3);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_4);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_5);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_6);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_7);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_8);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_9);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_10);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_100);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_1000);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_10000);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_100000);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_1000000);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_10000000);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_100000000);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_minus_1000000000);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_maxint);
	MU_RUN_TEST(test_ft_putnbr_fd_stdout_n_equal_minint);
	MU_RUN_TEST(test_ft_putnbr_fd_stderr_positive);
	MU_RUN_TEST(test_ft_putnbr_fd_stderr_negative);
	MU_RUN_TEST(test_ft_putnbr_fd_stderr_n_equal_maxint);
	MU_RUN_TEST(test_ft_putnbr_fd_stderr_n_equal_minint);
	MU_RUN_TEST(test_ft_putnbr_fd_file_positive);
	MU_RUN_TEST(test_ft_putnbr_fd_file_negative);
	MU_RUN_TEST(test_ft_putnbr_fd_file_maxint);
	MU_RUN_TEST(test_ft_putnbr_fd_file_minint);
}

int	main(void) {
	MU_RUN_SUITE(ft_putnbr_fd_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
