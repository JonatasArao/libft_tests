/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isxdigit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:07:56 by jarao-de          #+#    #+#             */
/*   Updated: 2024/11/27 10:01:23 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

int	ft_isxdigit(int c);

MU_TEST(test_ft_isxdigit_c_equal_one_before_zero)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isxdigit('0' - 1);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isxdigit_c_equal_zero)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isxdigit('0');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isxdigit_c_equal_one)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isxdigit('1');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isxdigit_c_equal_two)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isxdigit('2');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isxdigit_c_equal_three)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isxdigit('3');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isxdigit_c_equal_four)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isxdigit('4');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isxdigit_c_equal_five)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isxdigit('5');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isxdigit_c_equal_six)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isxdigit('6');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isxdigit_c_equal_seven)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isxdigit('7');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isxdigit_c_equal_eight)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isxdigit('8');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isxdigit_c_equal_nine)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isxdigit('9');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isxdigit_c_equal_one_after_nine)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isxdigit('9' + 1);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isxdigit_c_equal_one_before_A)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isxdigit('A' - 1);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isxdigit_c_equal_A)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isxdigit('A');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isxdigit_c_equal_B)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isxdigit('B');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isxdigit_c_equal_C)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isxdigit('C');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isxdigit_c_equal_D)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isxdigit('D');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isxdigit_c_equal_E)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isxdigit('E');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isxdigit_c_equal_F)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isxdigit('F');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isxdigit_c_equal_one_after_F)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isxdigit('F' + 1);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isxdigit_c_equal_one_before_a)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isxdigit('a' - 1);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isxdigit_c_equal_a)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isxdigit('a');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isxdigit_c_equal_b)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isxdigit('b');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isxdigit_c_equal_c)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isxdigit('c');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isxdigit_c_equal_d)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isxdigit('d');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isxdigit_c_equal_e)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isxdigit('e');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isxdigit_c_equal_f)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isxdigit('f');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isxdigit_c_equal_one_after_f)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isxdigit('f' + 1);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isxdigit_c_equal_space)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isxdigit(' ');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isxdigit_c_equal_special_char)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isxdigit('@');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isxdigit_c_equal_lower_bound)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isxdigit(0);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isxdigit_c_equal_upper_bound)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isxdigit(127);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isxdigit_c_equal_null)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isxdigit('\0');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_isxdigit_test_suite)
{
	MU_RUN_TEST(test_ft_isxdigit_c_equal_one_before_zero);
	MU_RUN_TEST(test_ft_isxdigit_c_equal_zero);
	MU_RUN_TEST(test_ft_isxdigit_c_equal_one);
	MU_RUN_TEST(test_ft_isxdigit_c_equal_two);
	MU_RUN_TEST(test_ft_isxdigit_c_equal_three);
	MU_RUN_TEST(test_ft_isxdigit_c_equal_four);
	MU_RUN_TEST(test_ft_isxdigit_c_equal_five);
	MU_RUN_TEST(test_ft_isxdigit_c_equal_six);
	MU_RUN_TEST(test_ft_isxdigit_c_equal_seven);
	MU_RUN_TEST(test_ft_isxdigit_c_equal_eight);
	MU_RUN_TEST(test_ft_isxdigit_c_equal_nine);
	MU_RUN_TEST(test_ft_isxdigit_c_equal_one_after_nine);
	MU_RUN_TEST(test_ft_isxdigit_c_equal_one_before_A);
	MU_RUN_TEST(test_ft_isxdigit_c_equal_A);
	MU_RUN_TEST(test_ft_isxdigit_c_equal_B);
	MU_RUN_TEST(test_ft_isxdigit_c_equal_C);
	MU_RUN_TEST(test_ft_isxdigit_c_equal_D);
	MU_RUN_TEST(test_ft_isxdigit_c_equal_E);
	MU_RUN_TEST(test_ft_isxdigit_c_equal_F);
	MU_RUN_TEST(test_ft_isxdigit_c_equal_one_after_F);
	MU_RUN_TEST(test_ft_isxdigit_c_equal_one_before_a);
	MU_RUN_TEST(test_ft_isxdigit_c_equal_a);
	MU_RUN_TEST(test_ft_isxdigit_c_equal_b);
	MU_RUN_TEST(test_ft_isxdigit_c_equal_c);
	MU_RUN_TEST(test_ft_isxdigit_c_equal_d);
	MU_RUN_TEST(test_ft_isxdigit_c_equal_e);
	MU_RUN_TEST(test_ft_isxdigit_c_equal_f);
	MU_RUN_TEST(test_ft_isxdigit_c_equal_one_after_f);
	MU_RUN_TEST(test_ft_isxdigit_c_equal_space);
	MU_RUN_TEST(test_ft_isxdigit_c_equal_special_char);
	MU_RUN_TEST(test_ft_isxdigit_c_equal_lower_bound);
	MU_RUN_TEST(test_ft_isxdigit_c_equal_upper_bound);
	MU_RUN_TEST(test_ft_isxdigit_c_equal_null);
}

int	main(void) {
	MU_RUN_SUITE(ft_isxdigit_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
