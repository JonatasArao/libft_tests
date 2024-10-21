/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putchar_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:58:47 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/21 16:57:16 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "minunit.h"

void	ft_putchar_fd(char c, int fd);

char* capture_ft_putchar_fd_output(void (*func)(char, int), char c, int fd)
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
	func(c, fd);

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

MU_TEST(test_ft_putchar_fd_stdout)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("F");
	actual_result = capture_ft_putchar_fd_output(&ft_putchar_fd, 'F', 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putchar_fd_stdout_numeric)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("1");
	actual_result = capture_ft_putchar_fd_output(&ft_putchar_fd, '1', 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putchar_fd_stdout_non_printable)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("\a"); // Bell character
	actual_result = capture_ft_putchar_fd_output(&ft_putchar_fd, '\a', 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putchar_fd_stdout_special)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("@");
	actual_result = capture_ft_putchar_fd_output(&ft_putchar_fd, '@', 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putchar_fd_stderr)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("T");
	actual_result = capture_ft_putchar_fd_output(&ft_putchar_fd, 'T', 2);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putchar_fd_stderr_numeric)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("2");
	actual_result = capture_ft_putchar_fd_output(&ft_putchar_fd, '2', 2);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putchar_fd_stderr_non_printable)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("\b"); // Backspace character
	actual_result = capture_ft_putchar_fd_output(&ft_putchar_fd, '\b', 2);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putchar_fd_stderr_special)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("#");
	actual_result = capture_ft_putchar_fd_output(&ft_putchar_fd, '#', 2);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putchar_fd_file)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	int		file;

	// ACT
	expected_result = strdup("A");
	file = open("test_ft_file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	actual_result = capture_ft_putchar_fd_output(&ft_putchar_fd, 'A', file);

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

MU_TEST(test_ft_putchar_fd_file_numeric)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	int		file;

	// ACT
	expected_result = strdup("3");
	file = open("test_ft_file_numeric.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	actual_result = capture_ft_putchar_fd_output(&ft_putchar_fd, '3', file);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	if (close(file) == -1) {
		perror("close");
		exit(EXIT_FAILURE);
	}
	if (remove("test_ft_file_numeric.txt") != 0) {
		perror("remove");
		exit(EXIT_FAILURE);
	}
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putchar_fd_file_non_printable)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	int		file;

	// ACT
	expected_result = strdup("\n"); // Newline character
	file = open("test_ft_file_non_printable.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	actual_result = capture_ft_putchar_fd_output(&ft_putchar_fd, '\n', file);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	if (close(file) == -1) {
		perror("close");
		exit(EXIT_FAILURE);
	}
	if (remove("test_ft_file_non_printable.txt") != 0) {
		perror("remove");
		exit(EXIT_FAILURE);
	}
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putchar_fd_file_special)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	int		file;

	// ACT
	expected_result = strdup("$");
	file = open("test_ft_file_special.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	actual_result = capture_ft_putchar_fd_output(&ft_putchar_fd, '$', file);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	if (close(file) == -1) {
		perror("close");
		exit(EXIT_FAILURE);
	}
	if (remove("test_ft_file_special.txt") != 0) {
		perror("remove");
		exit(EXIT_FAILURE);
	}
	free(actual_result);
	free(expected_result);
}

MU_TEST_SUITE(ft_putchar_fd_test_suite)
{
	MU_RUN_TEST(test_ft_putchar_fd_stdout);
	MU_RUN_TEST(test_ft_putchar_fd_stdout_numeric);
	MU_RUN_TEST(test_ft_putchar_fd_stdout_non_printable);
	MU_RUN_TEST(test_ft_putchar_fd_stdout_special);
	MU_RUN_TEST(test_ft_putchar_fd_stderr);
	MU_RUN_TEST(test_ft_putchar_fd_stderr_numeric);
	MU_RUN_TEST(test_ft_putchar_fd_stderr_non_printable);
	MU_RUN_TEST(test_ft_putchar_fd_stderr_special);
	MU_RUN_TEST(test_ft_putchar_fd_file);
	MU_RUN_TEST(test_ft_putchar_fd_file_numeric);
	MU_RUN_TEST(test_ft_putchar_fd_file_non_printable);
	MU_RUN_TEST(test_ft_putchar_fd_file_special);
}

int	main(void) {
	MU_RUN_SUITE(ft_putchar_fd_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
