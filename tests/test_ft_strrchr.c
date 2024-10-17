/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:54:18 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/17 14:22:25 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include "minunit.h"

char	*ft_strrchr(const char *s, int c);

int	capture_segfault_ft_strrchr(char *(*f)(const char *, int), const char *s, int c)
{
	pid_t pid = fork();
	if (pid == 0)
	{
		// Child process executes the test
		f(s, c);
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

MU_TEST(test_ft_strrchr_f_in_forty_two)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*string;
	char	message[50];

	// ACT
	string = strdup("forty two");
	if (!string) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = string;
	actual_result = ft_strrchr(string, 'f');
	snprintf(message, sizeof(message), "Expected memory address %p but was %p\n", (void *)expected_result, (void *)actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);

	// CLEANUP
	free(string);
}

MU_TEST(test_ft_strrchr_t_in_forty_two)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*string;
	char	message[50];

	// ACT
	string = strdup("forty two");
	if (!string) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = &string[6];
	actual_result = ft_strrchr(string, 't');
	snprintf(message, sizeof(message), "Expected memory address %p but was %p\n", (void *)expected_result, (void *)actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);

	// CLEANUP
	free(string);
}

MU_TEST(test_ft_strrchr_o_in_forty_two)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*string;
	char	message[50];

	// ACT
	string = strdup("forty two");
	if (!string) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = &string[8];
	actual_result = ft_strrchr(string, 'o');
	snprintf(message, sizeof(message), "Expected memory address %p but was %p\n", (void *)expected_result, (void *)actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);

	// CLEANUP
	free(string);
}

MU_TEST(test_ft_strrchr_null_char_in_forty_two)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*string;
	char	message[50];

	// ACT
	string = strdup("forty two");
	if (!string) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = &string[9];
	actual_result = ft_strrchr(string, '\0');
	snprintf(message, sizeof(message), "Expected memory address %p but was %p\n", (void *)expected_result, (void *)actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);

	// CLEANUP
	free(string);
}

MU_TEST(test_ft_strrchr_char_y_above_255_in_forty_two)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*string;
	char	message[50];

	// ACT
	string = strdup("forty two");
	if (!string) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = &string[4];
	actual_result = ft_strrchr(string, 377);
	snprintf(message, sizeof(message), "Expected memory address %p but was %p\n", (void *)expected_result, (void *)actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);

	// CLEANUP
	free(string);
}

MU_TEST(test_ft_strrchr_four_in_forty_two)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*string;

	// ACT
	string = strdup("forty two");
	if (!string) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = NULL;
	actual_result = ft_strrchr(string, '4');

	// ASSERT
	mu_assert(actual_result == expected_result, "Expected NULL pointer");

	// CLEANUP
	free(string);
}

MU_TEST(test_ft_strrchr_non_ascii_in_forty_two)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*string;
	char	message[50];

	// ACT
	string = strdup("forty two");
	string[1] = (char) 155;
	string[9] = (char) 155;
	if (!string) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = &string[9];
	actual_result = ft_strrchr(string, 155);
	snprintf(message, sizeof(message), "Expected memory address %p but was %p\n", (void *)expected_result, (void *)actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);

	// CLEANUP
	free(string);
}

MU_TEST(test_ft_strrchr_empty_string)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*string;
	char	message[50];

	// ACT
	string = strdup("");
	if (!string) {
		mu_fail("Memory allocation failed");
		return;
	}
	expected_result = NULL;
	actual_result = ft_strrchr(string, '4');
	snprintf(message, sizeof(message), "Expected memory address %p but was %p\n", (void *)expected_result, (void *)actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);

	// CLEANUP
	free(string);
}

MU_TEST(test_ft_strrchr_null_pointer)
{
	int		expected_result;
	int		actual_result;

	// ACT & ASSERT
	actual_result = 1;
	expected_result = capture_segfault_ft_strrchr(&ft_strrchr, NULL, '\0');
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST_SUITE(ft_strrchr_test_suite)
{
	MU_RUN_TEST(test_ft_strrchr_f_in_forty_two);
	MU_RUN_TEST(test_ft_strrchr_t_in_forty_two);
	MU_RUN_TEST(test_ft_strrchr_o_in_forty_two);
	MU_RUN_TEST(test_ft_strrchr_null_char_in_forty_two);
	MU_RUN_TEST(test_ft_strrchr_char_y_above_255_in_forty_two);
	MU_RUN_TEST(test_ft_strrchr_four_in_forty_two);
	MU_RUN_TEST(test_ft_strrchr_non_ascii_in_forty_two);
	MU_RUN_TEST(test_ft_strrchr_empty_string);
	MU_RUN_TEST(test_ft_strrchr_null_pointer);
}

int	main(void) {
	MU_RUN_SUITE(ft_strrchr_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
