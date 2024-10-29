/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putendl_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:12:32 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/29 17:30:23 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "minunit.h"

void	ft_putendl_fd(char *s, int fd);

char* capture_ft_putendl_fd_output(void (*func)(char *, int), char *s, int fd)
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
	func(s, fd);

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

int	capture_segfault_ft_putendl_fd(void (*func)(char *, int), char *s, int fd)
{
	pid_t pid = fork();
	if (pid == 0)
	{
		// Child process executes the test
		func(s, fd);
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

MU_TEST(test_ft_putendl_fd_stdout)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("42\n");
	actual_result = capture_ft_putendl_fd_output(&ft_putendl_fd, "42", 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putendl_fd_stdout_undercase_alphabet)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("abcdefghijklmnopqrstuvwxyz\n");
	actual_result = capture_ft_putendl_fd_output(&ft_putendl_fd, "abcdefghijklmnopqrstuvwxyz", 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putendl_fd_stdout_uppercase_alphabet)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
	actual_result = capture_ft_putendl_fd_output(&ft_putendl_fd, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putendl_fd_stdout_numbers)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("0123456789\n");
	actual_result = capture_ft_putendl_fd_output(&ft_putendl_fd, "0123456789", 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putendl_fd_stdout_special)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup(" !@#$%^&*()-_=+[{]}\\|;:'\",<.>/?`~\n");
	actual_result = capture_ft_putendl_fd_output(&ft_putendl_fd, " !@#$%^&*()-_=+[{]}\\|;:'\",<.>/?`~", 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putendl_fd_stdout_unprintable)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("\a\b\f\n\r\t\v\n");
	actual_result = capture_ft_putendl_fd_output(&ft_putendl_fd, "\a\b\f\n\r\t\v", 1);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putendl_fd_stderr)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("42\n");
	actual_result = capture_ft_putendl_fd_output(&ft_putendl_fd, "42", 2);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putendl_fd_stderr_undercase_alphabet)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("abcdefghijklmnopqrstuvwxyz\n");
	actual_result = capture_ft_putendl_fd_output(&ft_putendl_fd, "abcdefghijklmnopqrstuvwxyz", 2);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putendl_fd_stderr_uppercase_alphabet)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
	actual_result = capture_ft_putendl_fd_output(&ft_putendl_fd, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 2);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putendl_fd_stderr_numbers)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("0123456789\n");
	actual_result = capture_ft_putendl_fd_output(&ft_putendl_fd, "0123456789", 2);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putendl_fd_stderr_special)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup(" !@#$%^&*()-_=+[{]}\\|;:'\",<.>/?`~\n");
	actual_result = capture_ft_putendl_fd_output(&ft_putendl_fd, " !@#$%^&*()-_=+[{]}\\|;:'\",<.>/?`~", 2);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putendl_fd_stderr_unprintable)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("\a\b\f\n\r\t\v\n");
	actual_result = capture_ft_putendl_fd_output(&ft_putendl_fd, "\a\b\f\n\r\t\v", 2);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_putendl_fd_file)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	int		file;

	// ACT
	expected_result = strdup("42\n");
	file = open("test_ft_file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	actual_result = capture_ft_putendl_fd_output(&ft_putendl_fd, "42", file);

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

MU_TEST(test_ft_putendl_fd_file_undercase_alphabet)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	int		file;

	// ACT
	expected_result = strdup("abcdefghijklmnopqrstuvwxyz\n");
	file = open("test_ft_file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	actual_result = capture_ft_putendl_fd_output(&ft_putendl_fd, "abcdefghijklmnopqrstuvwxyz", file);

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

MU_TEST(test_ft_putendl_fd_file_uppercase_alphabet)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	int		file;

	// ACT
	expected_result = strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
	file = open("test_ft_file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	actual_result = capture_ft_putendl_fd_output(&ft_putendl_fd, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", file);

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

MU_TEST(test_ft_putendl_fd_file_numbers)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	int		file;

	// ACT
	expected_result = strdup("0123456789\n");
	file = open("test_ft_file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	actual_result = capture_ft_putendl_fd_output(&ft_putendl_fd, "0123456789", file);

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

MU_TEST(test_ft_putendl_fd_file_special)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	int		file;

	// ACT
	expected_result = strdup(" !@#$%^&*()-_=+[{]}\\|;:'\",<.>/?`~\n");
	file = open("test_ft_file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	actual_result = capture_ft_putendl_fd_output(&ft_putendl_fd, " !@#$%^&*()-_=+[{]}\\|;:'\",<.>/?`~", file);

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

MU_TEST(test_ft_putendl_fd_file_unprintable)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	int		file;

	// ACT
	expected_result = strdup("\a\b\f\n\r\t\v\n");
	file = open("test_ft_file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	actual_result = capture_ft_putendl_fd_output(&ft_putendl_fd, "\a\b\f\n\r\t\v", file);

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

MU_TEST(test_ft_putendl_fd_null_pointer)
{
	int		expected_result;
	int		actual_result;

	// ACT & ASSERT
	expected_result = 1;
	actual_result = capture_segfault_ft_putendl_fd(&ft_putendl_fd, NULL, 1);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST_SUITE(ft_putendl_fd_test_suite)
{
	MU_RUN_TEST(test_ft_putendl_fd_stdout);
	MU_RUN_TEST(test_ft_putendl_fd_stdout_undercase_alphabet);
	MU_RUN_TEST(test_ft_putendl_fd_stdout_uppercase_alphabet);
	MU_RUN_TEST(test_ft_putendl_fd_stdout_numbers);
	MU_RUN_TEST(test_ft_putendl_fd_stdout_special);
	MU_RUN_TEST(test_ft_putendl_fd_stdout_unprintable);
	MU_RUN_TEST(test_ft_putendl_fd_stderr);
	MU_RUN_TEST(test_ft_putendl_fd_stderr_undercase_alphabet);
	MU_RUN_TEST(test_ft_putendl_fd_stderr_uppercase_alphabet);
	MU_RUN_TEST(test_ft_putendl_fd_stderr_numbers);
	MU_RUN_TEST(test_ft_putendl_fd_stderr_special);
	MU_RUN_TEST(test_ft_putendl_fd_stderr_unprintable);
	MU_RUN_TEST(test_ft_putendl_fd_file);
	MU_RUN_TEST(test_ft_putendl_fd_file_undercase_alphabet);
	MU_RUN_TEST(test_ft_putendl_fd_file_uppercase_alphabet);
	MU_RUN_TEST(test_ft_putendl_fd_file_numbers);
	MU_RUN_TEST(test_ft_putendl_fd_file_special);
	MU_RUN_TEST(test_ft_putendl_fd_file_unprintable);
	MU_RUN_TEST(test_ft_putendl_fd_null_pointer);
}

int	main(void) {
	MU_RUN_SUITE(ft_putendl_fd_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
