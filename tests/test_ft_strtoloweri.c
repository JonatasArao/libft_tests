/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtoloweri.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:21:37 by jarao-de          #+#    #+#             */
/*   Updated: 2024/11/28 11:41:04 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

void	ft_strtoloweri(unsigned int i, char *s);

MU_TEST(test_ft_strtoloweri_one)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "1";

	// ACT
	expected_result = '1';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_a_minus_one)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "`";

	// ACT
	expected_result = 'a' - 1;
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_a)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "a";

	// ACT
	expected_result = 'a';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_b)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "b";

	// ACT
	expected_result = 'b';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_c)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "c";

	// ACT
	expected_result = 'c';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_d)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "d";

	// ACT
	expected_result = 'd';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_e)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "e";

	// ACT
	expected_result = 'e';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_f)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "f";

	// ACT
	expected_result = 'f';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_g)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "g";

	// ACT
	expected_result = 'g';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_h)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "h";

	// ACT
	expected_result = 'h';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_i)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "i";

	// ACT
	expected_result = 'i';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_j)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "j";

	// ACT
	expected_result = 'j';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_k)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "k";

	// ACT
	expected_result = 'k';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_l)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "l";

	// ACT
	expected_result = 'l';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_m)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "m";

	// ACT
	expected_result = 'm';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_n)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "n";

	// ACT
	expected_result = 'n';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_o)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "o";

	// ACT
	expected_result = 'o';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_p)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "p";

	// ACT
	expected_result = 'p';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_q)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "q";

	// ACT
	expected_result = 'q';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_r)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "r";

	// ACT
	expected_result = 'r';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_s)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "s";

	// ACT
	expected_result = 's';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_t)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "t";

	// ACT
	expected_result = 't';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_u)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "u";

	// ACT
	expected_result = 'u';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_v)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "v";

	// ACT
	expected_result = 'v';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_w)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "w";

	// ACT
	expected_result = 'w';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_x)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "x";

	// ACT
	expected_result = 'x';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_y)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "y";

	// ACT
	expected_result = 'y';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_z)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "z";

	// ACT
	expected_result = 'z';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_z_plus_one)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "{";

	// ACT
	expected_result = 'z' + 1;
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_A_minus_one)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "@";

	// ACT
	expected_result = 'A' - 1;
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_A)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "A";

	// ACT
	expected_result = 'a';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_B)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "B";

	// ACT
	expected_result = 'b';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_C)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "C";

	// ACT
	expected_result = 'c';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_D)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "D";

	// ACT
	expected_result = 'd';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_E)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "E";

	// ACT
	expected_result = 'e';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_F)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "F";

	// ACT
	expected_result = 'f';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_G)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "G";

	// ACT
	expected_result = 'g';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_H)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "H";

	// ACT
	expected_result = 'h';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_I)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "I";

	// ACT
	expected_result = 'i';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_J)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "J";

	// ACT
	expected_result = 'j';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_K)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "K";

	// ACT
	expected_result = 'k';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_L)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "L";

	// ACT
	expected_result = 'l';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_M)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "M";

	// ACT
	expected_result = 'm';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_N)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "N";

	// ACT
	expected_result = 'n';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_O)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "O";

	// ACT
	expected_result = 'o';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_P)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "P";

	// ACT
	expected_result = 'p';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_Q)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "Q";

	// ACT
	expected_result = 'q';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_R)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "R";

	// ACT
	expected_result = 'r';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_S)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "S";

	// ACT
	expected_result = 's';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_T)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "T";

	// ACT
	expected_result = 't';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_U)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "U";

	// ACT
	expected_result = 'u';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_V)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "V";

	// ACT
	expected_result = 'v';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_W)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "W";

	// ACT
	expected_result = 'w';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_X)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "X";

	// ACT
	expected_result = 'x';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_Y)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "Y";

	// ACT
	expected_result = 'y';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_Z)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "Z";

	// ACT
	expected_result = 'z';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_Z_plus_one)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "[";

	// ACT
	expected_result = 'Z' + 1;
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_space)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = " ";

	// ACT
	expected_result = ' ';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_special_char)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "@";

	// ACT
	expected_result = '@';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_lower_bound)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "\0";

	// ACT
	expected_result = 0;
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_upper_bound)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "\x7F";

	// ACT
	expected_result = 127;
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_null)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	char str[] = "\0";

	// ACT
	expected_result = '\0';
	ft_strtoloweri(0, str);
	actual_result = str[0];

	// ASSERT
	mu_assert_char_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strtoloweri_word)
{
	// ARRANGE
	char str[] = "FORTY-TWO 42";
	char expected_result[] = "forty-two 42";
	unsigned int i;
	unsigned int len;

	// ACT
	i = 0;
	len = sizeof(str) - 1;
	while (i < len) {
		ft_strtoloweri(i, str);
		i++;
	}

	// ASSERT
	mu_assert_string_eq(expected_result, str);
}

MU_TEST_SUITE(ft_strtoloweri_test_suite)
{
	MU_RUN_TEST(test_ft_strtoloweri_one);
	MU_RUN_TEST(test_ft_strtoloweri_a_minus_one);
	MU_RUN_TEST(test_ft_strtoloweri_a);
	MU_RUN_TEST(test_ft_strtoloweri_b);
	MU_RUN_TEST(test_ft_strtoloweri_c);
	MU_RUN_TEST(test_ft_strtoloweri_d);
	MU_RUN_TEST(test_ft_strtoloweri_e);
	MU_RUN_TEST(test_ft_strtoloweri_f);
	MU_RUN_TEST(test_ft_strtoloweri_g);
	MU_RUN_TEST(test_ft_strtoloweri_h);
	MU_RUN_TEST(test_ft_strtoloweri_i);
	MU_RUN_TEST(test_ft_strtoloweri_j);
	MU_RUN_TEST(test_ft_strtoloweri_k);
	MU_RUN_TEST(test_ft_strtoloweri_l);
	MU_RUN_TEST(test_ft_strtoloweri_m);
	MU_RUN_TEST(test_ft_strtoloweri_n);
	MU_RUN_TEST(test_ft_strtoloweri_o);
	MU_RUN_TEST(test_ft_strtoloweri_p);
	MU_RUN_TEST(test_ft_strtoloweri_q);
	MU_RUN_TEST(test_ft_strtoloweri_r);
	MU_RUN_TEST(test_ft_strtoloweri_s);
	MU_RUN_TEST(test_ft_strtoloweri_t);
	MU_RUN_TEST(test_ft_strtoloweri_u);
	MU_RUN_TEST(test_ft_strtoloweri_v);
	MU_RUN_TEST(test_ft_strtoloweri_w);
	MU_RUN_TEST(test_ft_strtoloweri_x);
	MU_RUN_TEST(test_ft_strtoloweri_y);
	MU_RUN_TEST(test_ft_strtoloweri_z);
	MU_RUN_TEST(test_ft_strtoloweri_z_plus_one);
	MU_RUN_TEST(test_ft_strtoloweri_A_minus_one);
	MU_RUN_TEST(test_ft_strtoloweri_A);
	MU_RUN_TEST(test_ft_strtoloweri_B);
	MU_RUN_TEST(test_ft_strtoloweri_C);
	MU_RUN_TEST(test_ft_strtoloweri_D);
	MU_RUN_TEST(test_ft_strtoloweri_E);
	MU_RUN_TEST(test_ft_strtoloweri_F);
	MU_RUN_TEST(test_ft_strtoloweri_G);
	MU_RUN_TEST(test_ft_strtoloweri_H);
	MU_RUN_TEST(test_ft_strtoloweri_I);
	MU_RUN_TEST(test_ft_strtoloweri_J);
	MU_RUN_TEST(test_ft_strtoloweri_K);
	MU_RUN_TEST(test_ft_strtoloweri_L);
	MU_RUN_TEST(test_ft_strtoloweri_M);
	MU_RUN_TEST(test_ft_strtoloweri_N);
	MU_RUN_TEST(test_ft_strtoloweri_O);
	MU_RUN_TEST(test_ft_strtoloweri_P);
	MU_RUN_TEST(test_ft_strtoloweri_Q);
	MU_RUN_TEST(test_ft_strtoloweri_R);
	MU_RUN_TEST(test_ft_strtoloweri_S);
	MU_RUN_TEST(test_ft_strtoloweri_T);
	MU_RUN_TEST(test_ft_strtoloweri_U);
	MU_RUN_TEST(test_ft_strtoloweri_V);
	MU_RUN_TEST(test_ft_strtoloweri_W);
	MU_RUN_TEST(test_ft_strtoloweri_X);
	MU_RUN_TEST(test_ft_strtoloweri_Y);
	MU_RUN_TEST(test_ft_strtoloweri_Z);
	MU_RUN_TEST(test_ft_strtoloweri_Z_plus_one);
	MU_RUN_TEST(test_ft_strtoloweri_space);
	MU_RUN_TEST(test_ft_strtoloweri_special_char);
	MU_RUN_TEST(test_ft_strtoloweri_lower_bound);
	MU_RUN_TEST(test_ft_strtoloweri_upper_bound);
	MU_RUN_TEST(test_ft_strtoloweri_null);
	MU_RUN_TEST(test_ft_strtoloweri_word);
}

int	main(void) {
	MU_RUN_SUITE(ft_strtoloweri_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
