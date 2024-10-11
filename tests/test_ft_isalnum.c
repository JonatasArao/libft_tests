/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:35:45 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/11 15:51:29 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "libft.h"

int	ft_isalnum(int c);

MU_TEST(test_ft_isalnum_c_equal_one_before_zero)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isalnum('0' - 1);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isalnum_c_equal_zero)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('0');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_one)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('1');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_two)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('2');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_three)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('3');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_four)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('4');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_five)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('5');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_six)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('6');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_seven)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('7');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_eight)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('8');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_nine)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('9');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_one_after_nine)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isalnum('9' + 1);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isalnum_c_equal_a_minus_one)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isalnum('a' - 1);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isalnum_c_equal_a)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('a');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_b)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('b');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_c)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('c');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_d)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('d');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_e)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('e');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_f)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('f');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_g)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('g');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_h)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('h');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_i)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('i');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_j)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('j');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_k)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('k');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_l)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('l');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_m)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('m');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_n)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('n');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_o)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('o');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_p)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('p');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_q)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('q');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_r)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('r');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_s)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('s');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_t)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('t');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_u)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('u');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_v)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('v');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_w)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('w');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_x)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('x');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_y)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('y');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_z)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('z');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_z_plus_one)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isalnum('z' + 1);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isalnum_c_equal_A_minus_one)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isalnum('A' - 1);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isalnum_c_equal_A)
{
    // ARRANGE
    int	actual_result;

    // ACT
    actual_result = ft_isalnum('A');

    // ASSERT
    mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_B)
{
    // ARRANGE
    int	actual_result;

    // ACT
    actual_result = ft_isalnum('B');

    // ASSERT
    mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_C)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('C');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_D)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('D');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_E)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('E');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_F)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('F');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_G)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('G');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_H)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('H');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_I)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('I');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_J)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('J');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_K)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('K');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_L)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('L');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_M)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('M');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_N)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('N');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_O)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('O');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_P)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('P');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_Q)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('Q');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_R)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('R');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_S)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('S');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_T)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('T');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_U)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('U');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_V)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('V');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_W)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('W');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_X)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('X');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_Y)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('Y');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_Z)
{
	// ARRANGE
	int	actual_result;

	// ACT
	actual_result = ft_isalnum('Z');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isalnum_c_equal_Z_plus_one)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isalnum('Z' + 1);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isalnum_c_equal_space)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isalnum(' ');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isalnum_c_equal_special_char)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isalnum('@');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isalnum_c_equal_lower_bound)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isalnum(0);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isalnum_c_equal_upper_bound)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isalnum(127);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isalnum_c_equal_null)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isalnum('\0');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_isalnum_test_suite)
{
	MU_RUN_TEST(test_ft_isalnum_c_equal_one_before_zero);
	MU_RUN_TEST(test_ft_isalnum_c_equal_zero);
	MU_RUN_TEST(test_ft_isalnum_c_equal_one);
	MU_RUN_TEST(test_ft_isalnum_c_equal_two);
	MU_RUN_TEST(test_ft_isalnum_c_equal_three);
	MU_RUN_TEST(test_ft_isalnum_c_equal_four);
	MU_RUN_TEST(test_ft_isalnum_c_equal_five);
	MU_RUN_TEST(test_ft_isalnum_c_equal_six);
	MU_RUN_TEST(test_ft_isalnum_c_equal_seven);
	MU_RUN_TEST(test_ft_isalnum_c_equal_eight);
	MU_RUN_TEST(test_ft_isalnum_c_equal_nine);
	MU_RUN_TEST(test_ft_isalnum_c_equal_one_after_nine);
	MU_RUN_TEST(test_ft_isalnum_c_equal_a_minus_one);
	MU_RUN_TEST(test_ft_isalnum_c_equal_a);
	MU_RUN_TEST(test_ft_isalnum_c_equal_b);
	MU_RUN_TEST(test_ft_isalnum_c_equal_c);
	MU_RUN_TEST(test_ft_isalnum_c_equal_d);
	MU_RUN_TEST(test_ft_isalnum_c_equal_e);
	MU_RUN_TEST(test_ft_isalnum_c_equal_f);
	MU_RUN_TEST(test_ft_isalnum_c_equal_g);
	MU_RUN_TEST(test_ft_isalnum_c_equal_h);
	MU_RUN_TEST(test_ft_isalnum_c_equal_i);
	MU_RUN_TEST(test_ft_isalnum_c_equal_j);
	MU_RUN_TEST(test_ft_isalnum_c_equal_k);
	MU_RUN_TEST(test_ft_isalnum_c_equal_l);
	MU_RUN_TEST(test_ft_isalnum_c_equal_m);
	MU_RUN_TEST(test_ft_isalnum_c_equal_n);
	MU_RUN_TEST(test_ft_isalnum_c_equal_o);
	MU_RUN_TEST(test_ft_isalnum_c_equal_p);
	MU_RUN_TEST(test_ft_isalnum_c_equal_q);
	MU_RUN_TEST(test_ft_isalnum_c_equal_r);
	MU_RUN_TEST(test_ft_isalnum_c_equal_s);
	MU_RUN_TEST(test_ft_isalnum_c_equal_t);
	MU_RUN_TEST(test_ft_isalnum_c_equal_u);
	MU_RUN_TEST(test_ft_isalnum_c_equal_v);
	MU_RUN_TEST(test_ft_isalnum_c_equal_w);
	MU_RUN_TEST(test_ft_isalnum_c_equal_x);
	MU_RUN_TEST(test_ft_isalnum_c_equal_y);
	MU_RUN_TEST(test_ft_isalnum_c_equal_z);
	MU_RUN_TEST(test_ft_isalnum_c_equal_z_plus_one);
	MU_RUN_TEST(test_ft_isalnum_c_equal_A_minus_one);
	MU_RUN_TEST(test_ft_isalnum_c_equal_A);
	MU_RUN_TEST(test_ft_isalnum_c_equal_B);
	MU_RUN_TEST(test_ft_isalnum_c_equal_C);
	MU_RUN_TEST(test_ft_isalnum_c_equal_D);
	MU_RUN_TEST(test_ft_isalnum_c_equal_E);
	MU_RUN_TEST(test_ft_isalnum_c_equal_F);
	MU_RUN_TEST(test_ft_isalnum_c_equal_G);
	MU_RUN_TEST(test_ft_isalnum_c_equal_H);
	MU_RUN_TEST(test_ft_isalnum_c_equal_I);
	MU_RUN_TEST(test_ft_isalnum_c_equal_J);
	MU_RUN_TEST(test_ft_isalnum_c_equal_K);
	MU_RUN_TEST(test_ft_isalnum_c_equal_L);
	MU_RUN_TEST(test_ft_isalnum_c_equal_M);
	MU_RUN_TEST(test_ft_isalnum_c_equal_N);
	MU_RUN_TEST(test_ft_isalnum_c_equal_O);
	MU_RUN_TEST(test_ft_isalnum_c_equal_P);
	MU_RUN_TEST(test_ft_isalnum_c_equal_Q);
	MU_RUN_TEST(test_ft_isalnum_c_equal_R);
	MU_RUN_TEST(test_ft_isalnum_c_equal_S);
	MU_RUN_TEST(test_ft_isalnum_c_equal_T);
	MU_RUN_TEST(test_ft_isalnum_c_equal_U);
	MU_RUN_TEST(test_ft_isalnum_c_equal_V);
	MU_RUN_TEST(test_ft_isalnum_c_equal_W);
	MU_RUN_TEST(test_ft_isalnum_c_equal_X);
	MU_RUN_TEST(test_ft_isalnum_c_equal_Y);
	MU_RUN_TEST(test_ft_isalnum_c_equal_Z);
	MU_RUN_TEST(test_ft_isalnum_c_equal_Z_plus_one);
	MU_RUN_TEST(test_ft_isalnum_c_equal_space);
	MU_RUN_TEST(test_ft_isalnum_c_equal_special_char);
	MU_RUN_TEST(test_ft_isalnum_c_equal_lower_bound);
	MU_RUN_TEST(test_ft_isalnum_c_equal_upper_bound);
	MU_RUN_TEST(test_ft_isalnum_c_equal_null);
}

int	main(void) {
	MU_RUN_SUITE(ft_isalnum_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
