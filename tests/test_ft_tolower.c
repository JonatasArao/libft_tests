/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_tolower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:52:48 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/14 11:05:15 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

int	ft_tolower(int c);

MU_TEST(test_ft_tolower_c_equal_one)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = '1';
	actual_result = ft_tolower('1');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_a_minus_one)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'a' - 1;
	actual_result = ft_tolower('a' - 1);

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_a)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'a';
	actual_result = ft_tolower('a');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_b)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'b';
	actual_result = ft_tolower('b');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_c)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'c';
	actual_result = ft_tolower('c');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_d)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'd';
	actual_result = ft_tolower('d');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_e)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'e';
	actual_result = ft_tolower('e');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_f)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'f';
	actual_result = ft_tolower('f');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_g)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'g';
	actual_result = ft_tolower('g');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_h)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'h';
	actual_result = ft_tolower('h');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_i)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'i';
	actual_result = ft_tolower('i');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_j)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'j';
	actual_result = ft_tolower('j');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_k)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'k';
	actual_result = ft_tolower('k');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_l)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'l';
	actual_result = ft_tolower('l');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_m)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'm';
	actual_result = ft_tolower('m');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_n)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'n';
	actual_result = ft_tolower('n');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_o)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'o';
	actual_result = ft_tolower('o');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_p)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'p';
	actual_result = ft_tolower('p');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_q)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'q';
	actual_result = ft_tolower('q');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_r)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'r';
	actual_result = ft_tolower('r');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_s)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 's';
	actual_result = ft_tolower('s');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_t)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 't';
	actual_result = ft_tolower('t');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_u)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'u';
	actual_result = ft_tolower('u');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_v)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'v';
	actual_result = ft_tolower('v');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_w)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'w';
	actual_result = ft_tolower('w');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_x)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'x';
	actual_result = ft_tolower('x');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_y)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'y';
	actual_result = ft_tolower('y');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_z)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'z';
	actual_result = ft_tolower('z');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_z_plus_one)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'z' + 1;
	actual_result = ft_tolower('z' + 1);

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_A_minus_one)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'A' - 1;
	actual_result = ft_tolower('A' - 1);

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_A)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'a';
	actual_result = ft_tolower('A');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_B)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'b';
	actual_result = ft_tolower('B');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_C)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'c';
	actual_result = ft_tolower('C');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_D)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'd';
	actual_result = ft_tolower('D');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_E)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'e';
	actual_result = ft_tolower('E');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_F)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'f';
	actual_result = ft_tolower('F');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_G)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'g';
	actual_result = ft_tolower('G');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_H)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'h';
	actual_result = ft_tolower('H');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_I)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'i';
	actual_result = ft_tolower('I');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_J)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'j';
	actual_result = ft_tolower('J');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_K)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'k';
	actual_result = ft_tolower('K');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_L)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'l';
	actual_result = ft_tolower('L');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_M)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'm';
	actual_result = ft_tolower('M');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_N)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'n';
	actual_result = ft_tolower('N');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_O)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'o';
	actual_result = ft_tolower('O');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_P)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'p';
	actual_result = ft_tolower('P');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_Q)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'q';
	actual_result = ft_tolower('Q');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_R)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'r';
	actual_result = ft_tolower('R');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_S)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 's';
	actual_result = ft_tolower('S');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_T)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 't';
	actual_result = ft_tolower('T');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_U)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'u';
	actual_result = ft_tolower('U');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_V)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'v';
	actual_result = ft_tolower('V');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_W)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'w';
	actual_result = ft_tolower('W');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_X)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'x';
	actual_result = ft_tolower('X');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_Y)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'y';
	actual_result = ft_tolower('Y');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_Z)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'z';
	actual_result = ft_tolower('Z');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_Z_plus_one)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'Z' + 1;
	actual_result = ft_tolower('Z' + 1);

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_space)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = ' ';
	actual_result = ft_tolower(' ');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_special_char)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = '@';
	actual_result = ft_tolower('@');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_lower_bound)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_tolower(0);

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_upper_bound)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 127;
	actual_result = ft_tolower(127);

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_tolower_c_equal_null)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = '\0';
	actual_result = ft_tolower('\0');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_tolower_test_suite)
{
	MU_RUN_TEST(test_ft_tolower_c_equal_one);
	MU_RUN_TEST(test_ft_tolower_c_equal_a_minus_one);
	MU_RUN_TEST(test_ft_tolower_c_equal_a);
	MU_RUN_TEST(test_ft_tolower_c_equal_b);
	MU_RUN_TEST(test_ft_tolower_c_equal_c);
	MU_RUN_TEST(test_ft_tolower_c_equal_d);
	MU_RUN_TEST(test_ft_tolower_c_equal_e);
	MU_RUN_TEST(test_ft_tolower_c_equal_f);
	MU_RUN_TEST(test_ft_tolower_c_equal_g);
	MU_RUN_TEST(test_ft_tolower_c_equal_h);
	MU_RUN_TEST(test_ft_tolower_c_equal_i);
	MU_RUN_TEST(test_ft_tolower_c_equal_j);
	MU_RUN_TEST(test_ft_tolower_c_equal_k);
	MU_RUN_TEST(test_ft_tolower_c_equal_l);
	MU_RUN_TEST(test_ft_tolower_c_equal_m);
	MU_RUN_TEST(test_ft_tolower_c_equal_n);
	MU_RUN_TEST(test_ft_tolower_c_equal_o);
	MU_RUN_TEST(test_ft_tolower_c_equal_p);
	MU_RUN_TEST(test_ft_tolower_c_equal_q);
	MU_RUN_TEST(test_ft_tolower_c_equal_r);
	MU_RUN_TEST(test_ft_tolower_c_equal_s);
	MU_RUN_TEST(test_ft_tolower_c_equal_t);
	MU_RUN_TEST(test_ft_tolower_c_equal_u);
	MU_RUN_TEST(test_ft_tolower_c_equal_v);
	MU_RUN_TEST(test_ft_tolower_c_equal_w);
	MU_RUN_TEST(test_ft_tolower_c_equal_x);
	MU_RUN_TEST(test_ft_tolower_c_equal_y);
	MU_RUN_TEST(test_ft_tolower_c_equal_z);
	MU_RUN_TEST(test_ft_tolower_c_equal_z_plus_one);
	MU_RUN_TEST(test_ft_tolower_c_equal_A_minus_one);
	MU_RUN_TEST(test_ft_tolower_c_equal_A);
	MU_RUN_TEST(test_ft_tolower_c_equal_B);
	MU_RUN_TEST(test_ft_tolower_c_equal_C);
	MU_RUN_TEST(test_ft_tolower_c_equal_D);
	MU_RUN_TEST(test_ft_tolower_c_equal_E);
	MU_RUN_TEST(test_ft_tolower_c_equal_F);
	MU_RUN_TEST(test_ft_tolower_c_equal_G);
	MU_RUN_TEST(test_ft_tolower_c_equal_H);
	MU_RUN_TEST(test_ft_tolower_c_equal_I);
	MU_RUN_TEST(test_ft_tolower_c_equal_J);
	MU_RUN_TEST(test_ft_tolower_c_equal_K);
	MU_RUN_TEST(test_ft_tolower_c_equal_L);
	MU_RUN_TEST(test_ft_tolower_c_equal_M);
	MU_RUN_TEST(test_ft_tolower_c_equal_N);
	MU_RUN_TEST(test_ft_tolower_c_equal_O);
	MU_RUN_TEST(test_ft_tolower_c_equal_P);
	MU_RUN_TEST(test_ft_tolower_c_equal_Q);
	MU_RUN_TEST(test_ft_tolower_c_equal_R);
	MU_RUN_TEST(test_ft_tolower_c_equal_S);
	MU_RUN_TEST(test_ft_tolower_c_equal_T);
	MU_RUN_TEST(test_ft_tolower_c_equal_U);
	MU_RUN_TEST(test_ft_tolower_c_equal_V);
	MU_RUN_TEST(test_ft_tolower_c_equal_W);
	MU_RUN_TEST(test_ft_tolower_c_equal_X);
	MU_RUN_TEST(test_ft_tolower_c_equal_Y);
	MU_RUN_TEST(test_ft_tolower_c_equal_Z);
	MU_RUN_TEST(test_ft_tolower_c_equal_Z_plus_one);
	MU_RUN_TEST(test_ft_tolower_c_equal_space);
	MU_RUN_TEST(test_ft_tolower_c_equal_special_char);
	MU_RUN_TEST(test_ft_tolower_c_equal_lower_bound);
	MU_RUN_TEST(test_ft_tolower_c_equal_upper_bound);
	MU_RUN_TEST(test_ft_tolower_c_equal_null);
}

int	main(void) {
	MU_RUN_SUITE(ft_tolower_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
