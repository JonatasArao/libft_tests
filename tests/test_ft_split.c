/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:26:20 by jarao-de          #+#    #+#             */
/*   Updated: 2024/11/01 14:36:45 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include "minunit.h"

char	**ft_split(char const *s, char c);

extern int mock_malloc_memset_active;

extern int mock_malloc_failure_active;

extern int mock_malloc_failure_threshold;

extern int mock_malloc_counter_active;

extern int mock_malloc_counter;

extern int mock_free_counter_active;

extern int mock_free_counter;

int capture_segfault_ft_split(char **(*f)(const char *, char), char const *s, char c)
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

MU_TEST(test_ft_split_null_terminated)
{
	// ARRANGE
	char	**actual_result;

	// ACT
	actual_result = ft_split("forty two", ' ');

	// ASSERT
	mu_assert(actual_result[2] == NULL, "Expected the result to be a null-terminated array of strings");
}

MU_TEST(test_ft_split_strings_null_terminated)
{
	// ARRANGE
	char	**expected_result;
	char	**actual_result;
	char	*str;

	// ACT
	str = strdup("forty two");
	expected_result = (char **)malloc(3 * sizeof(char *));
	expected_result[0] = strdup("forty");
	expected_result[1] = strdup("two");
	expected_result[2] = NULL;
	actual_result = ft_split(str, ' ');

	// ASSERT
	for (int i = 0; expected_result[i] != NULL; i++)
	{
		mu_assert(actual_result[i][strlen(expected_result[i])] == '\0',
			"Expected the duplicated string to be null-terminated");
	}

	// CLEANUP
	free(str);
	for (int i = 0; expected_result[i] != NULL; i++)
	{
		free(expected_result[i]);
	}
	free(expected_result);
}

MU_TEST(test_ft_split_basic)
{
	// ARRANGE
	char	**expected_result;
	char	**actual_result;
	char	*str;

	// ACT
	str = strdup("forty two");
	expected_result = (char **)malloc(3 * sizeof(char *));
	expected_result[0] = strdup("forty");
	expected_result[1] = strdup("two");
	expected_result[2] = NULL;
	actual_result = ft_split(str, ' ');

	// ASSERT
	for (int i = 0; expected_result[i] != NULL; i++)
	{
		mu_assert_string_eq(expected_result[i], actual_result[i]);
	}
	mu_assert(actual_result[2] == NULL, "Expected NULL after splitting 'forty two'");

	// CLEANUP
	free(str);
	for (int i = 0; expected_result[i] != NULL; i++)
	{
		free(expected_result[i]);
	}
	free(expected_result);
}

MU_TEST(test_ft_split_empty_string)
{
	// ARRANGE
	char	**expected_result;
	char	**actual_result;
	char	*str;

	// ACT
	str = strdup("");
	expected_result = (char **)malloc(1 * sizeof(char *));
	expected_result[0] = NULL;
	actual_result = ft_split(str, ' ');

	// ASSERT
	mu_assert(actual_result[0] == NULL, "Expected NULL for empty string");

	// CLEANUP
	free(str);
	free(expected_result);
}

MU_TEST(test_ft_split_no_delimiter)
{
	// ARRANGE
	char	**expected_result;
	char	**actual_result;
	char	*str;

	// ACT
	str = strdup("forty");
	expected_result = (char **)malloc(2 * sizeof(char *));
	expected_result[0] = strdup("forty");
	expected_result[1] = NULL;
	actual_result = ft_split(str, ' ');

	// ASSERT
	mu_assert_string_eq(expected_result[0], actual_result[0]);
	mu_assert(actual_result[1] == NULL, "Expected NULL after single word");

	// CLEANUP
	free(str);
	for (int i = 0; expected_result[i] != NULL; i++)
	{
		free(expected_result[i]);
	}
	free(expected_result);
}

MU_TEST(test_ft_split_multiple_delimiters)
{
	// ARRANGE
	char	**expected_result;
	char	**actual_result;
	char	*str;


	// ACT
	str = strdup("forty  two");
	expected_result = (char **)malloc(3 * sizeof(char *));
	expected_result[0] = strdup("forty");
	expected_result[1] = strdup("two");
	expected_result[2] = NULL;
	actual_result = ft_split(str, ' ');

	// ASSERT
	for (int i = 0; expected_result[i] != NULL; i++)
	{
		mu_assert_string_eq(expected_result[i], actual_result[i]);
	}

	// CLEANUP
	free(str);
	for (int i = 0; expected_result[i] != NULL; i++)
	{
		free(expected_result[i]);
	}
	free(expected_result);
}

MU_TEST(test_ft_split_leading_delimiters)
{
	// ARRANGE
	char	**expected_result;
	char	**actual_result;
	char	*str;


	// ACT
	str = strdup("  forty two");
	expected_result = (char **)malloc(3 * sizeof(char *));
	expected_result[0] = strdup("forty");
	expected_result[1] = strdup("two");
	expected_result[2] = NULL;
	actual_result = ft_split(str, ' ');

	// ASSERT
	for (int i = 0; expected_result[i] != NULL; i++)
	{
		mu_assert_string_eq(expected_result[i], actual_result[i]);
	}

	// CLEANUP
	free(str);
	for (int i = 0; expected_result[i] != NULL; i++)
	{
		free(expected_result[i]);
	}
	free(expected_result);
}

MU_TEST(test_ft_split_trailing_delimiters)
{
	// ARRANGE
	char	**expected_result;
	char	**actual_result;
	char	*str;


	// ACT
	str = strdup("forty two  ");
	expected_result = (char **)malloc(3 * sizeof(char *));
	expected_result[0] = strdup("forty");
	expected_result[1] = strdup("two");
	expected_result[2] = NULL;
	actual_result = ft_split(str, ' ');

	// ASSERT
	for (int i = 0; expected_result[i] != NULL; i++)
	{
		mu_assert_string_eq(expected_result[i], actual_result[i]);
	}

	// CLEANUP
	free(str);
	for (int i = 0; expected_result[i] != NULL; i++)
	{
		free(expected_result[i]);
	}
	free(expected_result);
}

MU_TEST(test_ft_split_only_delimiters)
{
	// ARRANGE
	char	**expected_result;
	char	**actual_result;
	char	*str;

	// ACT
	str = strdup("     ");
	expected_result = (char **)malloc(1 * sizeof(char *));
	expected_result[0] = NULL;
	actual_result = ft_split(str, ' ');

	// ASSERT
	mu_assert(actual_result[0] == NULL, "Expected NULL for string with only delimiters");

	// CLEANUP
	free(str);
	free(expected_result);
}

MU_TEST(test_ft_split_first_malloc_fail)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	int		segfaulted;

	// ACT
	expected_result = NULL;
	mock_malloc_failure_active = 1;
	mock_malloc_failure_threshold = 1;
	segfaulted = capture_segfault_ft_split(&ft_split, "42 School", ' ');
	if (!segfaulted)
		actual_result = ft_split("42 School", ' ');
	mock_malloc_failure_active = 0;

	// ASSERT
	if (!segfaulted)
	{
		mu_assert(actual_result == expected_result, "Expected NULL pointer");
		free(actual_result);
	}
	else
		mu_fail("Function should not cause a segmentation fault.");
}

MU_TEST(test_ft_split_second_malloc_fail)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	int		segfaulted;

	// ACT
	expected_result = NULL;
	mock_malloc_failure_active = 1;
	mock_malloc_failure_threshold = 2;
	segfaulted = capture_segfault_ft_split(&ft_split, "42 School", ' ');
	if (!segfaulted)
		actual_result = ft_split("42 School", ' ');
	mock_malloc_failure_threshold = 1;
	mock_malloc_failure_active = 0;

	// ASSERT
	if (!segfaulted)
	{
		mu_assert(actual_result == expected_result, "Expected NULL pointer");
		free(actual_result);
	}
	else
		mu_fail("Function should not cause a segmentation fault.");
}

MU_TEST(test_ft_split_third_malloc_fail)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;
	int		segfaulted;

	// ACT
	expected_result = NULL;
	mock_malloc_failure_active = 1;
	mock_malloc_failure_threshold = 3;
	segfaulted = capture_segfault_ft_split(&ft_split, "42 School", ' ');
	if (!segfaulted)
		actual_result = ft_split("42 School", ' ');
	mock_malloc_failure_threshold = 1;
	mock_malloc_failure_active = 0;

	// ASSERT
	if (!segfaulted)
	{
		mu_assert(actual_result == expected_result, "Expected NULL pointer");
		free(actual_result);
	}
	else
		mu_fail("Function should not cause a segmentation fault.");
}

MU_TEST(test_ft_split_free_matrix)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	char	**splited;
	char	message[80];

	// ACT
	mock_malloc_failure_active = 1;
	mock_malloc_failure_threshold = 4;
	mock_malloc_counter_active = 1;
	mock_malloc_counter = 0;
	mock_free_counter_active = 1;
	mock_free_counter = 0;
	splited = ft_split("42 (forty-two) School", ' ');
	mock_malloc_counter_active = 0;
	mock_free_counter_active = 0;
	mock_malloc_failure_active = 0;
	expected_result = mock_malloc_counter;
	actual_result = mock_free_counter;
	snprintf(message, sizeof(message), "Expected %d memory allocations to be freed, but %d were not freed.\n", expected_result, expected_result - actual_result);

	// ASSERT
	mu_assert(expected_result == actual_result, message);

	// CLEANUP
	free(splited);
}
MU_TEST_SUITE(ft_split_test_suite)
{
	MU_RUN_TEST(test_ft_split_null_terminated);
	MU_RUN_TEST(test_ft_split_strings_null_terminated);
	MU_RUN_TEST(test_ft_split_basic);
	MU_RUN_TEST(test_ft_split_empty_string);
	MU_RUN_TEST(test_ft_split_no_delimiter);
	MU_RUN_TEST(test_ft_split_multiple_delimiters);
	MU_RUN_TEST(test_ft_split_leading_delimiters);
	MU_RUN_TEST(test_ft_split_trailing_delimiters);
	MU_RUN_TEST(test_ft_split_only_delimiters);
	MU_RUN_TEST(test_ft_split_first_malloc_fail);
	MU_RUN_TEST(test_ft_split_second_malloc_fail);
	MU_RUN_TEST(test_ft_split_third_malloc_fail);
	MU_RUN_TEST(test_ft_split_free_matrix);
}

int	main(void) {
	mock_malloc_memset_active = 1;
	MU_RUN_SUITE(ft_split_test_suite);
	mock_malloc_memset_active = 0;
	MU_REPORT();
	return MU_EXIT_CODE;
}
