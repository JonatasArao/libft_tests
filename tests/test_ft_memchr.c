/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:13:48 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/21 11:12:59 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include "minunit.h"

void	*ft_memchr(const void *s, int c, size_t n);

int	capture_segfault_ft_memchr(void *(*f)(const void *, int, size_t), const void *s, int c, size_t n)
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

MU_TEST(test_ft_memchr_f_in_forty_two_string_n_10)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	char	*string;
	char	message[50];

	// ACT
	string = strdup("forty two");
	if (!string) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = string;
	actual_result = ft_memchr(string, 'f', 10);
	snprintf(message, sizeof(message), "Expected memory address %p but was %p\n", (void *)expected_result, (void *)actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);

	// CLEANUP
	free(string);
}

MU_TEST(test_ft_memchr_t_in_forty_two_string_n_10)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	char	*string;
	char	message[50];

	// ACT
	string = strdup("forty two");
	if (!string) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = &string[3];
	actual_result = ft_memchr(string, 't', 10);
	snprintf(message, sizeof(message), "Expected memory address %p but was %p\n", (void *)expected_result, (void *)actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);

	// CLEANUP
	free(string);
}

MU_TEST(test_ft_memchr_t_in_forty_two_string_n_3)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	char	*string;

	// ACT
	string = strdup("forty two");
	if (!string) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = NULL;
	actual_result = ft_memchr(string, 't', 3);

	// ASSERT
	mu_assert(actual_result == expected_result, "Expected NULL pointer");

	// CLEANUP
	free(string);
}

MU_TEST(test_ft_memchr_o_in_forty_two_string_n_10)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	char	*string;
	char	message[50];

	// ACT
	string = strdup("forty two");
	if (!string) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = &string[1];
	actual_result = ft_memchr(string, 'o', 10);
	snprintf(message, sizeof(message), "Expected memory address %p but was %p\n", (void *)expected_result, (void *)actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);

	// CLEANUP
	free(string);
}

MU_TEST(test_ft_memchr_null_char_in_forty_two_string_n_10)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	char	*string;
	char	message[50];

	// ACT
	string = strdup("forty two");
	if (!string) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = &string[9];
	actual_result = ft_memchr(string, '\0', 10);
	snprintf(message, sizeof(message), "Expected memory address %p but was %p\n", (void *)expected_result, (void *)actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);

	// CLEANUP
	free(string);
}

MU_TEST(test_ft_memchr_char_y_above_255_in_forty_two_string_n_10)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	char	*string;
	char	message[50];

	// ACT
	string = strdup("forty two");
	if (!string) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = &string[4];
	actual_result = ft_memchr(string, 377, 10);
	snprintf(message, sizeof(message), "Expected memory address %p but was %p\n", (void *)expected_result, (void *)actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);

	// CLEANUP
	free(string);
}

MU_TEST(test_ft_memchr_four_in_forty_two_string_n_10)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	char	*string;

	// ACT
	string = strdup("forty two");
	if (!string) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = NULL;
	actual_result = ft_memchr(string, '4', 10);

	// ASSERT
	mu_assert(actual_result == expected_result, "Expected NULL pointer");

	// CLEANUP
	free(string);
}

MU_TEST(test_ft_memchr_non_ascii_in_forty_two_string_n_10)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	char	*string;
	char	message[50];

	// ACT
	string = strdup("forty two");
	string[1] = (char) 155;
	if (!string) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = &string[1];
	actual_result = ft_memchr(string, 155, 10);
	snprintf(message, sizeof(message), "Expected memory address %p but was %p\n", (void *)expected_result, (void *)actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);

	// CLEANUP
	free(string);
}

MU_TEST(test_ft_memchr_f_in_forty_two_buffer_n_10)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	char	buffer[10];
	char	message[50];

	// ACT
	buffer[0] = 'f';
	buffer[1] = 'o';
	buffer[2] = 'r';
	buffer[3] = 't';
	buffer[4] = 'y';
	buffer[5] = ' ';
	buffer[6] = 't';
	buffer[7] = 'w';
	buffer[8] = 'o';
	buffer[9] = (char) 255;
	expected_result = buffer;
	actual_result = ft_memchr(buffer, 'f', 10);
	snprintf(message, sizeof(message), "Expected memory address %p but was %p\n", (void *)expected_result, (void *)actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);
}

MU_TEST(test_ft_memchr_t_in_forty_two_buffer_n_10)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	char	buffer[10];
	char	message[50];

	// ACT
	buffer[0] = 'f';
	buffer[1] = 'o';
	buffer[2] = 'r';
	buffer[3] = 't';
	buffer[4] = 'y';
	buffer[5] = ' ';
	buffer[6] = 't';
	buffer[7] = 'w';
	buffer[8] = 'o';
	buffer[9] = (char) 255;
	expected_result = &buffer[3];
	actual_result = ft_memchr(buffer, 't', 10);
	snprintf(message, sizeof(message), "Expected memory address %p but was %p\n", (void *)expected_result, (void *)actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);
}

MU_TEST(test_ft_memchr_t_in_forty_two_buffer_n_3)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	char	buffer[10];

	// ACT
	buffer[0] = 'f';
	buffer[1] = 'o';
	buffer[2] = 'r';
	buffer[3] = 't';
	buffer[4] = 'y';
	buffer[5] = ' ';
	buffer[6] = 't';
	buffer[7] = 'w';
	buffer[8] = 'o';
	buffer[9] = (char) 255;
	expected_result = NULL;
	actual_result = ft_memchr(buffer, 't', 3);

	// ASSERT
	mu_assert(actual_result == expected_result, "Expected NULL pointer");
}

MU_TEST(test_ft_memchr_o_in_forty_two_buffer_n_10)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	char	buffer[10];
	char	message[50];

	// ACT
	buffer[0] = 'f';
	buffer[1] = 'o';
	buffer[2] = 'r';
	buffer[3] = 't';
	buffer[4] = 'y';
	buffer[5] = ' ';
	buffer[6] = 't';
	buffer[7] = 'w';
	buffer[8] = 'o';
	buffer[9] = (char) 255;
	expected_result = &buffer[1];
	actual_result = ft_memchr(buffer, 'o', 10);
	snprintf(message, sizeof(message), "Expected memory address %p but was %p\n", (void *)expected_result, (void *)actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);
}

MU_TEST(test_ft_memchr_null_char_in_forty_two_buffer_n_10)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	char	buffer[10];

	// ACT
	buffer[0] = 'f';
	buffer[1] = 'o';
	buffer[2] = 'r';
	buffer[3] = 't';
	buffer[4] = 'y';
	buffer[5] = ' ';
	buffer[6] = 't';
	buffer[7] = 'w';
	buffer[8] = 'o';
	buffer[9] = (char) 255;
	expected_result = NULL;
	actual_result = ft_memchr(buffer, '\0', 10);

	// ASSERT
	mu_assert(actual_result == expected_result, "Expected NULL pointer");
}

MU_TEST(test_ft_memchr_char_y_above_255_in_forty_two_buffer_n_10)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	char	buffer[10];
	char	message[50];

	// ACT
	buffer[0] = 'f';
	buffer[1] = 'o';
	buffer[2] = 'r';
	buffer[3] = 't';
	buffer[4] = 'y';
	buffer[5] = ' ';
	buffer[6] = 't';
	buffer[7] = 'w';
	buffer[8] = 'o';
	buffer[9] = (char) 255;
	expected_result = &buffer[4];
	actual_result = ft_memchr(buffer, 377, 10);
	snprintf(message, sizeof(message), "Expected memory address %p but was %p\n", (void *)expected_result, (void *)actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);
}

MU_TEST(test_ft_memchr_four_in_forty_two_buffer_n_10)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	char	buffer[10];

	// ACT
	buffer[0] = 'f';
	buffer[1] = 'o';
	buffer[2] = 'r';
	buffer[3] = 't';
	buffer[4] = 'y';
	buffer[5] = ' ';
	buffer[6] = 't';
	buffer[7] = 'w';
	buffer[8] = 'o';
	buffer[9] = (char) 255;
	expected_result = NULL;
	actual_result = ft_memchr(buffer, '4', 10);

	// ASSERT
	mu_assert(actual_result == expected_result, "Expected NULL pointer");
}

MU_TEST(test_ft_memchr_non_ascii_in_forty_two_buffer_n_10)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	char	buffer[10];
	char	message[50];

	// ACT
	buffer[0] = 'f';
	buffer[1] = (char) 155;
	buffer[2] = 'r';
	buffer[3] = 't';
	buffer[4] = 'y';
	buffer[5] = ' ';
	buffer[6] = 't';
	buffer[7] = 'w';
	buffer[8] = 'o';
	buffer[9] = (char) 255;
	expected_result = &buffer[1];
	actual_result = ft_memchr(buffer, 155, 10);
	snprintf(message, sizeof(message), "Expected memory address %p but was %p\n", (void *)expected_result, (void *)actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);
}

MU_TEST(test_ft_memchr_empty_string_n_1)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	char	*string;
	char	message[50];

	// ACT
	string = strdup("");
	if (!string) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = NULL;
	actual_result = ft_memchr(string, ' ', 1);
	snprintf(message, sizeof(message), "Expected memory address %p but was %p\n", (void *)expected_result, (void *)actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);

	// CLEANUP
	free(string);
}

MU_TEST(test_ft_memchr_null_char_in_empty_string_n_0)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	char	*string;

	// ACT
	string = strdup("");
	if (!string) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = NULL;
	actual_result = ft_memchr(string, 0, 0);

	// ASSERT
	mu_assert(actual_result == expected_result, "Expected NULL pointer");

	// CLEANUP
	free(string);
}

MU_TEST(test_ft_memchr_null_pointer)
{
	int		expected_result;
	int		actual_result;

	// ACT & ASSERT
	actual_result = 1;
	expected_result = capture_segfault_ft_memchr(&ft_memchr, NULL, '\0', 1);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST_SUITE(ft_memchr_test_suite)
{
	MU_RUN_TEST(test_ft_memchr_f_in_forty_two_string_n_10);
	MU_RUN_TEST(test_ft_memchr_t_in_forty_two_string_n_10);
	MU_RUN_TEST(test_ft_memchr_t_in_forty_two_string_n_3);
	MU_RUN_TEST(test_ft_memchr_o_in_forty_two_string_n_10);
	MU_RUN_TEST(test_ft_memchr_null_char_in_forty_two_string_n_10);
	MU_RUN_TEST(test_ft_memchr_char_y_above_255_in_forty_two_string_n_10);
	MU_RUN_TEST(test_ft_memchr_four_in_forty_two_string_n_10);
	MU_RUN_TEST(test_ft_memchr_non_ascii_in_forty_two_string_n_10);
	MU_RUN_TEST(test_ft_memchr_f_in_forty_two_buffer_n_10);
	MU_RUN_TEST(test_ft_memchr_t_in_forty_two_buffer_n_10);
	MU_RUN_TEST(test_ft_memchr_t_in_forty_two_buffer_n_3);
	MU_RUN_TEST(test_ft_memchr_o_in_forty_two_buffer_n_10);
	MU_RUN_TEST(test_ft_memchr_null_char_in_forty_two_buffer_n_10);
	MU_RUN_TEST(test_ft_memchr_char_y_above_255_in_forty_two_buffer_n_10);
	MU_RUN_TEST(test_ft_memchr_four_in_forty_two_buffer_n_10);
	MU_RUN_TEST(test_ft_memchr_non_ascii_in_forty_two_buffer_n_10);
	MU_RUN_TEST(test_ft_memchr_empty_string_n_1);
	MU_RUN_TEST(test_ft_memchr_null_char_in_empty_string_n_0);
	MU_RUN_TEST(test_ft_memchr_null_pointer);
}

int	main(void) {
	MU_RUN_SUITE(ft_memchr_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
