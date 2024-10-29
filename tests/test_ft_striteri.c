/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_striteri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:27:15 by jarao-de          #+#    #+#             */
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

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

int capture_segfault_ft_striteri(void (*f)(char *, void (*)(unsigned int, char*)), char *s, void (*func)(unsigned int, char*))
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

void toggle_case(unsigned int index, char* c)
{
	if (index % 2 == 0 && *c >= 'a' && *c <= 'z')
	{
		*c = *c - ('a' - 'A');
	}
	else if (index % 2 != 0 && *c >= 'A' && *c <= 'Z')
	{
		*c = *c + ('a' - 'A');
	}
}

MU_TEST(test_ft_striteri_one_char_string)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("F");
	actual_result = strdup("f");
	ft_striteri(actual_result, &toggle_case);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_striteri_string)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("FoRtY TwO");
	actual_result = strdup("forty two");
	ft_striteri(actual_result, &toggle_case);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_striteri_empty_string)
{
	// ARRANGE
	char	*expected_result;
	char	*actual_result;

	// ACT
	expected_result = strdup("");
	actual_result = strdup("");
	ft_striteri(actual_result, &toggle_case);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(expected_result);
	free(actual_result);
}

MU_TEST(test_ft_striteri_s1_null)
{
	int		expected_result;
	int		actual_result;

	// ACT & ASSERT
	expected_result = 1;
	actual_result = capture_segfault_ft_striteri(&ft_striteri, NULL, &toggle_case);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST(test_ft_striteri_s2_null)
{
	int		expected_result;
	int		actual_result;

	// ACT & ASSERT
	expected_result = 1;
	actual_result = capture_segfault_ft_striteri(&ft_striteri, "42", NULL);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST(test_ft_striteri_s1_null_s2_null)
{
	int		expected_result;
	int		actual_result;

	// ACT & ASSERT
	expected_result = 1;
	actual_result = capture_segfault_ft_striteri(&ft_striteri, NULL, NULL);
	mu_assert(expected_result == actual_result, "Expected segmentation fault, but it did not occur.");
}

MU_TEST_SUITE(ft_striteri_test_suite)
{
	MU_RUN_TEST(test_ft_striteri_one_char_string);
	MU_RUN_TEST(test_ft_striteri_string);
	MU_RUN_TEST(test_ft_striteri_empty_string);
	MU_RUN_TEST(test_ft_striteri_s1_null);
	MU_RUN_TEST(test_ft_striteri_s2_null);
	MU_RUN_TEST(test_ft_striteri_s1_null_s2_null);
}

int	main(void) {
	MU_RUN_SUITE(ft_striteri_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
