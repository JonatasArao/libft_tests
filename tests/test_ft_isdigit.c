/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:07:56 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/10 14:20:36 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

int	ft_isdigit(int c);

MU_TEST(test_ft_isdigit_c_equal_one_before_zero)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isdigit('0' - 1);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isdigit_c_equal_zero)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isdigit('0');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isdigit_c_equal_one)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isdigit('1');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isdigit_c_equal_two)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isdigit('2');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isdigit_c_equal_three)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isdigit('3');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isdigit_c_equal_four)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isdigit('4');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isdigit_c_equal_five)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isdigit('5');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isdigit_c_equal_six)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isdigit('6');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isdigit_c_equal_seven)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isdigit('7');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isdigit_c_equal_eight)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isdigit('8');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isdigit_c_equal_nine)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isdigit('9');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isdigit_c_equal_one_after_nine)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isdigit('9' + 1);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isdigit_c_equal_space)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isdigit(' ');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isdigit_c_equal_special_char)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isdigit('@');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isdigit_c_equal_lower_bound)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isdigit(0);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isdigit_c_equal_upper_bound)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isdigit(127);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isdigit_c_equal_null)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isdigit('\0');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_isdigit_test_suite)
{
	MU_RUN_TEST(test_ft_isdigit_c_equal_one_before_zero);
	MU_RUN_TEST(test_ft_isdigit_c_equal_zero);
	MU_RUN_TEST(test_ft_isdigit_c_equal_one);
	MU_RUN_TEST(test_ft_isdigit_c_equal_two);
	MU_RUN_TEST(test_ft_isdigit_c_equal_three);
	MU_RUN_TEST(test_ft_isdigit_c_equal_four);
	MU_RUN_TEST(test_ft_isdigit_c_equal_five);
	MU_RUN_TEST(test_ft_isdigit_c_equal_six);
	MU_RUN_TEST(test_ft_isdigit_c_equal_seven);
	MU_RUN_TEST(test_ft_isdigit_c_equal_eight);
	MU_RUN_TEST(test_ft_isdigit_c_equal_nine);
	MU_RUN_TEST(test_ft_isdigit_c_equal_one_after_nine);
	MU_RUN_TEST(test_ft_isdigit_c_equal_space);
	MU_RUN_TEST(test_ft_isdigit_c_equal_special_char);
	MU_RUN_TEST(test_ft_isdigit_c_equal_lower_bound);
	MU_RUN_TEST(test_ft_isdigit_c_equal_upper_bound);
	MU_RUN_TEST(test_ft_isdigit_c_equal_null);
}

int	main(void) {
	MU_RUN_SUITE(ft_isdigit_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
