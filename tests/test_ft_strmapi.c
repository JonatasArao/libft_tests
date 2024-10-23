/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strmapi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:52:15 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/23 15:12:41 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include "minunit.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int		capture_segfault_ft_strmapi(char *(*f)(char const *, char (*)(unsigned int, char)), char const *s, char (*func)(unsigned int, char))
{
	pid_t pid = fork();
	if (pid == 0)
	{
		// Child process executes the test
		f(s, func);
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

char	toggle_case(unsigned int index, char c)
{
	if (index % 2 == 0 && c >= 'a' && c <= 'z')
	{
		return c - ('a' - 'A');
	}
	else if (index % 2 != 0 && c >= 'A' && c <= 'Z')
	{
		return c + ('a' - 'A');
	}
	return c;
}

MU_TEST(test_ft_strmapi_one_char_string)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*string;

	// ACT
	expected_result = strdup("F");
	string = strdup("f");
	actual_result = ft_strmapi(string, &toggle_case);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(expected_result);
	free(actual_result);
	free(string);
}

MU_TEST(test_ft_strmapi_string)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*string;

	// ACT
	expected_result = strdup("FoRtY TwO");
	string = strdup("forty two");
	actual_result = ft_strmapi(string, &toggle_case);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(expected_result);
	free(actual_result);
	free(string);
}

MU_TEST(test_ft_strmapi_empty_string)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;
	char	*string;

	// ACT
	expected_result = strdup("");
	string = strdup("");
	actual_result = ft_strmapi(string, &toggle_case);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(expected_result);
	free(actual_result);
	free(string);
}

MU_TEST(test_ft_strmapi_s1_null)
{
	int		expected_result;
	int		actual_result;

	// ACT & ASSERT
	actual_result = 1;
	expected_result = capture_segfault_ft_strmapi(&ft_strmapi, NULL, &toggle_case);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST(test_ft_strmapi_s2_null)
{
	int		expected_result;
	int		actual_result;

	// ACT & ASSERT
	actual_result = 1;
	expected_result = capture_segfault_ft_strmapi(&ft_strmapi, "42", NULL);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST(test_ft_strmapi_s1_null_s2_null)
{
	int		expected_result;
	int		actual_result;

	// ACT & ASSERT
	actual_result = 1;
	expected_result = capture_segfault_ft_strmapi(&ft_strmapi, NULL, NULL);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST_SUITE(ft_strmapi_test_suite)
{
	MU_RUN_TEST(test_ft_strmapi_one_char_string);
	MU_RUN_TEST(test_ft_strmapi_string);
	MU_RUN_TEST(test_ft_strmapi_empty_string);
	MU_RUN_TEST(test_ft_strmapi_s1_null);
	MU_RUN_TEST(test_ft_strmapi_s2_null);
	MU_RUN_TEST(test_ft_strmapi_s1_null_s2_null);
}

int	main(void) {
	MU_RUN_SUITE(ft_strmapi_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
