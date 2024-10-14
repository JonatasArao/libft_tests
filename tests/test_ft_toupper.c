/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_toupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:21:37 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/14 10:36:04 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

int	ft_toupper(int c);

MU_TEST(test_ft_toupper_c_equal_one)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = '1';
	actual_result = ft_toupper('1');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_a_minus_one)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'a' - 1;
	actual_result = ft_toupper('a' - 1);

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_a)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'A';
	actual_result = ft_toupper('a');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_b)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'B';
	actual_result = ft_toupper('b');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_c)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'C';
	actual_result = ft_toupper('c');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_d)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'D';
	actual_result = ft_toupper('d');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_e)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'E';
	actual_result = ft_toupper('e');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_f)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'F';
	actual_result = ft_toupper('f');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_g)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'G';
	actual_result = ft_toupper('g');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_h)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'H';
	actual_result = ft_toupper('h');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_i)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'I';
	actual_result = ft_toupper('i');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_j)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'J';
	actual_result = ft_toupper('j');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_k)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'K';
	actual_result = ft_toupper('k');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_l)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'L';
	actual_result = ft_toupper('l');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_m)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'M';
	actual_result = ft_toupper('m');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_n)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'N';
	actual_result = ft_toupper('n');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_o)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'O';
	actual_result = ft_toupper('o');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_p)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'P';
	actual_result = ft_toupper('p');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_q)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'Q';
	actual_result = ft_toupper('q');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_r)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'R';
	actual_result = ft_toupper('r');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_s)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'S';
	actual_result = ft_toupper('s');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_t)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'T';
	actual_result = ft_toupper('t');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_u)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'U';
	actual_result = ft_toupper('u');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_v)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'V';
	actual_result = ft_toupper('v');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_w)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'W';
	actual_result = ft_toupper('w');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_x)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'X';
	actual_result = ft_toupper('x');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_y)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'Y';
	actual_result = ft_toupper('y');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_z)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'Z';
	actual_result = ft_toupper('z');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_z_plus_one)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'z' + 1;
	actual_result = ft_toupper('z' + 1);

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_A_minus_one)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'A' - 1;
	actual_result = ft_toupper('A' - 1);

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_A)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'A';
	actual_result = ft_toupper('A');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_B)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'B';
	actual_result = ft_toupper('B');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_C)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'C';
	actual_result = ft_toupper('C');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_D)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'D';
	actual_result = ft_toupper('D');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_E)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'E';
	actual_result = ft_toupper('E');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_F)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'F';
	actual_result = ft_toupper('F');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_G)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'G';
	actual_result = ft_toupper('G');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_H)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'H';
	actual_result = ft_toupper('H');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_I)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'I';
	actual_result = ft_toupper('I');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_J)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'J';
	actual_result = ft_toupper('J');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_K)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'K';
	actual_result = ft_toupper('K');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_L)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'L';
	actual_result = ft_toupper('L');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_M)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'M';
	actual_result = ft_toupper('M');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_N)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'N';
	actual_result = ft_toupper('N');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_O)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'O';
	actual_result = ft_toupper('O');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_P)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'P';
	actual_result = ft_toupper('P');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_Q)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'Q';
	actual_result = ft_toupper('Q');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_R)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'R';
	actual_result = ft_toupper('R');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_S)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'S';
	actual_result = ft_toupper('S');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_T)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'T';
	actual_result = ft_toupper('T');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_U)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'U';
	actual_result = ft_toupper('U');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_V)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'V';
	actual_result = ft_toupper('V');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_W)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'W';
	actual_result = ft_toupper('W');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_X)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'X';
	actual_result = ft_toupper('X');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_Y)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'Y';
	actual_result = ft_toupper('Y');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_Z)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'Z';
	actual_result = ft_toupper('Z');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_Z_plus_one)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'Z' - 1;
	actual_result = ft_toupper('Z' - 1);

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_space)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = ' ';
	actual_result = ft_toupper(' ');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_special_char)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = '@';
	actual_result = ft_toupper('@');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_lower_bound)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_toupper(0);

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_upper_bound)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 127;
	actual_result = ft_toupper(127);

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_toupper_c_equal_null)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = '\0';
	actual_result = ft_toupper('\0');

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_toupper_test_suite)
{
	MU_RUN_TEST(test_ft_toupper_c_equal_one);
	MU_RUN_TEST(test_ft_toupper_c_equal_a_minus_one);
	MU_RUN_TEST(test_ft_toupper_c_equal_a);
	MU_RUN_TEST(test_ft_toupper_c_equal_b);
	MU_RUN_TEST(test_ft_toupper_c_equal_c);
	MU_RUN_TEST(test_ft_toupper_c_equal_d);
	MU_RUN_TEST(test_ft_toupper_c_equal_e);
	MU_RUN_TEST(test_ft_toupper_c_equal_f);
	MU_RUN_TEST(test_ft_toupper_c_equal_g);
	MU_RUN_TEST(test_ft_toupper_c_equal_h);
	MU_RUN_TEST(test_ft_toupper_c_equal_i);
	MU_RUN_TEST(test_ft_toupper_c_equal_j);
	MU_RUN_TEST(test_ft_toupper_c_equal_k);
	MU_RUN_TEST(test_ft_toupper_c_equal_l);
	MU_RUN_TEST(test_ft_toupper_c_equal_m);
	MU_RUN_TEST(test_ft_toupper_c_equal_n);
	MU_RUN_TEST(test_ft_toupper_c_equal_o);
	MU_RUN_TEST(test_ft_toupper_c_equal_p);
	MU_RUN_TEST(test_ft_toupper_c_equal_q);
	MU_RUN_TEST(test_ft_toupper_c_equal_r);
	MU_RUN_TEST(test_ft_toupper_c_equal_s);
	MU_RUN_TEST(test_ft_toupper_c_equal_t);
	MU_RUN_TEST(test_ft_toupper_c_equal_u);
	MU_RUN_TEST(test_ft_toupper_c_equal_v);
	MU_RUN_TEST(test_ft_toupper_c_equal_w);
	MU_RUN_TEST(test_ft_toupper_c_equal_x);
	MU_RUN_TEST(test_ft_toupper_c_equal_y);
	MU_RUN_TEST(test_ft_toupper_c_equal_z);
	MU_RUN_TEST(test_ft_toupper_c_equal_z_plus_one);
	MU_RUN_TEST(test_ft_toupper_c_equal_A_minus_one);
	MU_RUN_TEST(test_ft_toupper_c_equal_A);
	MU_RUN_TEST(test_ft_toupper_c_equal_B);
	MU_RUN_TEST(test_ft_toupper_c_equal_C);
	MU_RUN_TEST(test_ft_toupper_c_equal_D);
	MU_RUN_TEST(test_ft_toupper_c_equal_E);
	MU_RUN_TEST(test_ft_toupper_c_equal_F);
	MU_RUN_TEST(test_ft_toupper_c_equal_G);
	MU_RUN_TEST(test_ft_toupper_c_equal_H);
	MU_RUN_TEST(test_ft_toupper_c_equal_I);
	MU_RUN_TEST(test_ft_toupper_c_equal_J);
	MU_RUN_TEST(test_ft_toupper_c_equal_K);
	MU_RUN_TEST(test_ft_toupper_c_equal_L);
	MU_RUN_TEST(test_ft_toupper_c_equal_M);
	MU_RUN_TEST(test_ft_toupper_c_equal_N);
	MU_RUN_TEST(test_ft_toupper_c_equal_O);
	MU_RUN_TEST(test_ft_toupper_c_equal_P);
	MU_RUN_TEST(test_ft_toupper_c_equal_Q);
	MU_RUN_TEST(test_ft_toupper_c_equal_R);
	MU_RUN_TEST(test_ft_toupper_c_equal_S);
	MU_RUN_TEST(test_ft_toupper_c_equal_T);
	MU_RUN_TEST(test_ft_toupper_c_equal_U);
	MU_RUN_TEST(test_ft_toupper_c_equal_V);
	MU_RUN_TEST(test_ft_toupper_c_equal_W);
	MU_RUN_TEST(test_ft_toupper_c_equal_X);
	MU_RUN_TEST(test_ft_toupper_c_equal_Y);
	MU_RUN_TEST(test_ft_toupper_c_equal_Z);
	MU_RUN_TEST(test_ft_toupper_c_equal_Z_plus_one);
	MU_RUN_TEST(test_ft_toupper_c_equal_space);
	MU_RUN_TEST(test_ft_toupper_c_equal_special_char);
	MU_RUN_TEST(test_ft_toupper_c_equal_lower_bound);
	MU_RUN_TEST(test_ft_toupper_c_equal_upper_bound);
	MU_RUN_TEST(test_ft_toupper_c_equal_null);
}

int	main(void) {
	MU_RUN_SUITE(ft_toupper_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
