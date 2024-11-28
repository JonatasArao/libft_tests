/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:21:00 by jarao-de          #+#    #+#             */
/*   Updated: 2024/11/28 12:10:48 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "minunit.h"

int	ft_strall(char *str, int (*f)(char));

int	ft_is_alpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

MU_TEST(test_ft_strall_all_alpha)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	char	*word;

	// ACT
	word = "cadete";
	expected_result = 1;
	actual_result = ft_strall(word, ft_is_alpha);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strall_not_all_alpha)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	char	*word;

	// ACT
	word = "c4d3t3";
	expected_result = 0;
	actual_result = ft_strall(word, ft_is_alpha);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strall_empty_string)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	char	*word;

	// ACT
	word = "";
	expected_result = 1;
	actual_result = ft_strall(word, ft_is_alpha);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_strall_test_suite)
{
	MU_RUN_TEST(test_ft_strall_all_alpha);
	MU_RUN_TEST(test_ft_strall_not_all_alpha);
	MU_RUN_TEST(test_ft_strall_empty_string);
}

int	main(void) {
	MU_RUN_SUITE(ft_strall_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
