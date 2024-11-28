/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtoupperi.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:21:37 by jarao-de          #+#    #+#             */
/*   Updated: 2024/11/28 11:33:42 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

void	ft_strtoupperi(unsigned int i, char *s);

MU_TEST(test_ft_strtoupperi_one)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "1";

	// ACT
	expected_result = '1';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_a_minus_one)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "`";

	// ACT
	expected_result = 'a' - 1;
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_a)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "a";

	// ACT
	expected_result = 'A';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_b)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "b";

	// ACT
	expected_result = 'B';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_c)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "c";

	// ACT
	expected_result = 'C';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_d)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "d";

	// ACT
	expected_result = 'D';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_e)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "e";

	// ACT
	expected_result = 'E';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_f)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "f";

	// ACT
	expected_result = 'F';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_g)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "g";

	// ACT
	expected_result = 'G';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_h)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "h";

	// ACT
	expected_result = 'H';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_i)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "i";

	// ACT
	expected_result = 'I';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_j)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "j";

	// ACT
	expected_result = 'J';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_k)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "k";

	// ACT
	expected_result = 'K';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_l)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "l";

	// ACT
	expected_result = 'L';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_m)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "m";

	// ACT
	expected_result = 'M';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_n)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "n";

	// ACT
	expected_result = 'N';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_o)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "o";

	// ACT
	expected_result = 'O';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_p)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "p";

	// ACT
	expected_result = 'P';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_q)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "q";

	// ACT
	expected_result = 'Q';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_r)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "r";

	// ACT
	expected_result = 'R';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_s)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "s";

	// ACT
	expected_result = 'S';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_t)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "t";

	// ACT
	expected_result = 'T';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_u)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "u";

	// ACT
	expected_result = 'U';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_v)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "v";

	// ACT
	expected_result = 'V';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_w)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "w";

	// ACT
	expected_result = 'W';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_x)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "x";

	// ACT
	expected_result = 'X';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_y)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "y";

	// ACT
	expected_result = 'Y';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_z)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "z";

	// ACT
	expected_result = 'Z';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_z_plus_one)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "{";

	// ACT
	expected_result = 'z' + 1;
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_A_minus_one)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "A";

	// ACT
	expected_result = 'A' - 1;
	ft_strtoupperi(0, str);
	actual_result = str[0] - 1;

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_A)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "A";

	// ACT
	expected_result = 'A';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_B)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "B";

	// ACT
	expected_result = 'B';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_C)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "C";

	// ACT
	expected_result = 'C';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_D)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "D";

	// ACT
	expected_result = 'D';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_E)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "E";

	// ACT
	expected_result = 'E';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_F)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "F";

	// ACT
	expected_result = 'F';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_G)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "G";

	// ACT
	expected_result = 'G';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_H)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "H";

	// ACT
	expected_result = 'H';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_I)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "I";

	// ACT
	expected_result = 'I';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_J)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "J";

	// ACT
	expected_result = 'J';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_K)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "K";

	// ACT
	expected_result = 'K';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_L)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "L";

	// ACT
	expected_result = 'L';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_M)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "M";

	// ACT
	expected_result = 'M';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_N)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "N";

	// ACT
	expected_result = 'N';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_O)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "O";

	// ACT
	expected_result = 'O';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_P)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "P";

	// ACT
	expected_result = 'P';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_Q)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "Q";

	// ACT
	expected_result = 'Q';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_R)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "R";

	// ACT
	expected_result = 'R';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_S)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "S";

	// ACT
	expected_result = 'S';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_T)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "T";

	// ACT
	expected_result = 'T';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_U)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "U";

	// ACT
	expected_result = 'U';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_V)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "V";

	// ACT
	expected_result = 'V';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_W)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "W";

	// ACT
	expected_result = 'W';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_X)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "X";

	// ACT
	expected_result = 'X';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_Y)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "Y";

	// ACT
	expected_result = 'Y';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_Z)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "Z";

	// ACT
	expected_result = 'Z';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_Z_plus_one)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "Z";

	// ACT
	expected_result = 'Z' + 1;
	ft_strtoupperi(0, str);
	actual_result = str[0] + 1;

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_space)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = " ";

	// ACT
	expected_result = ' ';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_special_char)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "@";

	// ACT
	expected_result = '@';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_lower_bound)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "\0";

	// ACT
	expected_result = 0;
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_upper_bound)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "\x7F";

	// ACT
	expected_result = 127;
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_null)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "\0";

	// ACT
	expected_result = '\0';
	ft_strtoupperi(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoupperi_word)
{
	// ARRANGE
	char str[] = "forty-two 42";
	char expected_result[] = "FORTY-TWO 42";
	unsigned int i;
	unsigned int len;

	// ACT
	i = 0;
	len = sizeof(str) - 1;
	while (i < len) {
		ft_strtoupperi(i, str);
		i++;
	}

	// ASSERT
	mu_assert_string_eq(expected_result, str);
}

MU_TEST_SUITE(ft_strtoupperi_test_suite)
{
	MU_RUN_TEST(test_ft_strtoupperi_one);
	MU_RUN_TEST(test_ft_strtoupperi_a_minus_one);
	MU_RUN_TEST(test_ft_strtoupperi_a);
	MU_RUN_TEST(test_ft_strtoupperi_b);
	MU_RUN_TEST(test_ft_strtoupperi_c);
	MU_RUN_TEST(test_ft_strtoupperi_d);
	MU_RUN_TEST(test_ft_strtoupperi_e);
	MU_RUN_TEST(test_ft_strtoupperi_f);
	MU_RUN_TEST(test_ft_strtoupperi_g);
	MU_RUN_TEST(test_ft_strtoupperi_h);
	MU_RUN_TEST(test_ft_strtoupperi_i);
	MU_RUN_TEST(test_ft_strtoupperi_j);
	MU_RUN_TEST(test_ft_strtoupperi_k);
	MU_RUN_TEST(test_ft_strtoupperi_l);
	MU_RUN_TEST(test_ft_strtoupperi_m);
	MU_RUN_TEST(test_ft_strtoupperi_n);
	MU_RUN_TEST(test_ft_strtoupperi_o);
	MU_RUN_TEST(test_ft_strtoupperi_p);
	MU_RUN_TEST(test_ft_strtoupperi_q);
	MU_RUN_TEST(test_ft_strtoupperi_r);
	MU_RUN_TEST(test_ft_strtoupperi_s);
	MU_RUN_TEST(test_ft_strtoupperi_t);
	MU_RUN_TEST(test_ft_strtoupperi_u);
	MU_RUN_TEST(test_ft_strtoupperi_v);
	MU_RUN_TEST(test_ft_strtoupperi_w);
	MU_RUN_TEST(test_ft_strtoupperi_x);
	MU_RUN_TEST(test_ft_strtoupperi_y);
	MU_RUN_TEST(test_ft_strtoupperi_z);
	MU_RUN_TEST(test_ft_strtoupperi_z_plus_one);
	MU_RUN_TEST(test_ft_strtoupperi_A_minus_one);
	MU_RUN_TEST(test_ft_strtoupperi_A);
	MU_RUN_TEST(test_ft_strtoupperi_B);
	MU_RUN_TEST(test_ft_strtoupperi_C);
	MU_RUN_TEST(test_ft_strtoupperi_D);
	MU_RUN_TEST(test_ft_strtoupperi_E);
	MU_RUN_TEST(test_ft_strtoupperi_F);
	MU_RUN_TEST(test_ft_strtoupperi_G);
	MU_RUN_TEST(test_ft_strtoupperi_H);
	MU_RUN_TEST(test_ft_strtoupperi_I);
	MU_RUN_TEST(test_ft_strtoupperi_J);
	MU_RUN_TEST(test_ft_strtoupperi_K);
	MU_RUN_TEST(test_ft_strtoupperi_L);
	MU_RUN_TEST(test_ft_strtoupperi_M);
	MU_RUN_TEST(test_ft_strtoupperi_N);
	MU_RUN_TEST(test_ft_strtoupperi_O);
	MU_RUN_TEST(test_ft_strtoupperi_P);
	MU_RUN_TEST(test_ft_strtoupperi_Q);
	MU_RUN_TEST(test_ft_strtoupperi_R);
	MU_RUN_TEST(test_ft_strtoupperi_S);
	MU_RUN_TEST(test_ft_strtoupperi_T);
	MU_RUN_TEST(test_ft_strtoupperi_U);
	MU_RUN_TEST(test_ft_strtoupperi_V);
	MU_RUN_TEST(test_ft_strtoupperi_W);
	MU_RUN_TEST(test_ft_strtoupperi_X);
	MU_RUN_TEST(test_ft_strtoupperi_Y);
	MU_RUN_TEST(test_ft_strtoupperi_Z);
	MU_RUN_TEST(test_ft_strtoupperi_Z_plus_one);
	MU_RUN_TEST(test_ft_strtoupperi_space);
	MU_RUN_TEST(test_ft_strtoupperi_special_char);
	MU_RUN_TEST(test_ft_strtoupperi_lower_bound);
	MU_RUN_TEST(test_ft_strtoupperi_upper_bound);
	MU_RUN_TEST(test_ft_strtoupperi_null);
	MU_RUN_TEST(test_ft_strtoupperi_word);
}

int	main(void) {
	MU_RUN_SUITE(ft_strtoupperi_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
