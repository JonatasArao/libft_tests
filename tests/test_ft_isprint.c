/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:47:32 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/14 10:06:45 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

int	ft_isprint(int c);

MU_TEST(test_ft_isprint_space_minus_one) {
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isprint(' ' - 1);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isprint_space) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint(' ');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_exclamation) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('!');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_double_quote) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('"');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_hash) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('#');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_dollar) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('$');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_percent) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('%');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_ampersand) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('&');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_single_quote) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('\'');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_left_parenthesis) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('(');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_right_parenthesis) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint(')');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_asterisk) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('*');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_plus) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('+');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_comma) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint(',');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_minus) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('-');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_period) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('.');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_slash) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('/');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_zero) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('0');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_one) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('1');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_two) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('2');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_three) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('3');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_four) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('4');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_five) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('5');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_six) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('6');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_seven) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('7');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_eight) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('8');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_nine) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('9');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_colon) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint(':');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_semicolon) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint(';');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_less_than) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('<');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_equal) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('=');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_greater_than) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('>');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_question) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('?');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_at) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('@');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_A) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('A');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_B) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('B');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_C) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('C');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_D) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('D');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_E) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('E');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_F) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('F');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_G) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('G');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_H) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('H');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_I) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('I');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_J) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('J');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_K) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('K');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_L) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('L');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_M) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('M');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_N) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('N');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_O) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('O');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_P) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('P');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_Q) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('Q');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_R) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('R');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_S) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('S');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_T) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('T');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_U) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('U');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_V) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('V');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_W) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('W');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_X) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('X');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_Y) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('Y');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_Z) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('Z');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_left_bracket) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('[');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_backslash) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('\\');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_right_bracket) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint(']');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_caret) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('^');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_underscore) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('_');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_grave) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('`');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_a) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('a');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_b) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('b');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_c) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('c');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_d) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('d');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_e) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('e');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_f) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('f');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_g) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('g');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_h) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('h');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_i) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('i');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_j) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('j');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_k) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('k');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_l) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('l');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_m) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('m');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_n) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('n');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_o) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('o');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_p) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('p');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_q) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('q');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_r) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('r');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_s) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('s');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_t) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('t');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_u) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('u');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_v) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('v');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_w) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('w');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_x) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('x');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_y) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('y');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_z) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('z');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_left_brace) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('{');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_vertical_bar) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('|');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_right_brace) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('}');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_tilde) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isprint('~');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isprint_tilde_plus_one) {
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isprint('~' + 1);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isprint_newline) {
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isprint('\n');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isprint_tab) {
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isprint('\t');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isprint_null) {
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isprint('\0');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_isprint_test_suite) {
	MU_RUN_TEST(test_ft_isprint_space_minus_one);
	MU_RUN_TEST(test_ft_isprint_space);
	MU_RUN_TEST(test_ft_isprint_exclamation);
	MU_RUN_TEST(test_ft_isprint_double_quote);
	MU_RUN_TEST(test_ft_isprint_hash);
	MU_RUN_TEST(test_ft_isprint_dollar);
	MU_RUN_TEST(test_ft_isprint_percent);
	MU_RUN_TEST(test_ft_isprint_ampersand);
	MU_RUN_TEST(test_ft_isprint_single_quote);
	MU_RUN_TEST(test_ft_isprint_left_parenthesis);
	MU_RUN_TEST(test_ft_isprint_right_parenthesis);
	MU_RUN_TEST(test_ft_isprint_asterisk);
	MU_RUN_TEST(test_ft_isprint_plus);
	MU_RUN_TEST(test_ft_isprint_comma);
	MU_RUN_TEST(test_ft_isprint_minus);
	MU_RUN_TEST(test_ft_isprint_period);
	MU_RUN_TEST(test_ft_isprint_slash);
	MU_RUN_TEST(test_ft_isprint_zero);
	MU_RUN_TEST(test_ft_isprint_one);
	MU_RUN_TEST(test_ft_isprint_two);
	MU_RUN_TEST(test_ft_isprint_three);
	MU_RUN_TEST(test_ft_isprint_four);
	MU_RUN_TEST(test_ft_isprint_five);
	MU_RUN_TEST(test_ft_isprint_six);
	MU_RUN_TEST(test_ft_isprint_seven);
	MU_RUN_TEST(test_ft_isprint_eight);
	MU_RUN_TEST(test_ft_isprint_nine);
	MU_RUN_TEST(test_ft_isprint_colon);
	MU_RUN_TEST(test_ft_isprint_semicolon);
	MU_RUN_TEST(test_ft_isprint_less_than);
	MU_RUN_TEST(test_ft_isprint_equal);
	MU_RUN_TEST(test_ft_isprint_greater_than);
	MU_RUN_TEST(test_ft_isprint_question);
	MU_RUN_TEST(test_ft_isprint_at);
	MU_RUN_TEST(test_ft_isprint_A);
	MU_RUN_TEST(test_ft_isprint_B);
	MU_RUN_TEST(test_ft_isprint_C);
	MU_RUN_TEST(test_ft_isprint_D);
	MU_RUN_TEST(test_ft_isprint_E);
	MU_RUN_TEST(test_ft_isprint_F);
	MU_RUN_TEST(test_ft_isprint_G);
	MU_RUN_TEST(test_ft_isprint_H);
	MU_RUN_TEST(test_ft_isprint_I);
	MU_RUN_TEST(test_ft_isprint_J);
	MU_RUN_TEST(test_ft_isprint_K);
	MU_RUN_TEST(test_ft_isprint_L);
	MU_RUN_TEST(test_ft_isprint_M);
	MU_RUN_TEST(test_ft_isprint_N);
	MU_RUN_TEST(test_ft_isprint_O);
	MU_RUN_TEST(test_ft_isprint_P);
	MU_RUN_TEST(test_ft_isprint_Q);
	MU_RUN_TEST(test_ft_isprint_R);
	MU_RUN_TEST(test_ft_isprint_S);
	MU_RUN_TEST(test_ft_isprint_T);
	MU_RUN_TEST(test_ft_isprint_U);
	MU_RUN_TEST(test_ft_isprint_V);
	MU_RUN_TEST(test_ft_isprint_W);
	MU_RUN_TEST(test_ft_isprint_X);
	MU_RUN_TEST(test_ft_isprint_Y);
	MU_RUN_TEST(test_ft_isprint_Z);
	MU_RUN_TEST(test_ft_isprint_left_bracket);
	MU_RUN_TEST(test_ft_isprint_backslash);
	MU_RUN_TEST(test_ft_isprint_right_bracket);
	MU_RUN_TEST(test_ft_isprint_caret);
	MU_RUN_TEST(test_ft_isprint_underscore);
	MU_RUN_TEST(test_ft_isprint_grave);
	MU_RUN_TEST(test_ft_isprint_a);
	MU_RUN_TEST(test_ft_isprint_b);
	MU_RUN_TEST(test_ft_isprint_c);
	MU_RUN_TEST(test_ft_isprint_d);
	MU_RUN_TEST(test_ft_isprint_e);
	MU_RUN_TEST(test_ft_isprint_f);
	MU_RUN_TEST(test_ft_isprint_g);
	MU_RUN_TEST(test_ft_isprint_h);
	MU_RUN_TEST(test_ft_isprint_i);
	MU_RUN_TEST(test_ft_isprint_j);
	MU_RUN_TEST(test_ft_isprint_k);
	MU_RUN_TEST(test_ft_isprint_l);
	MU_RUN_TEST(test_ft_isprint_m);
	MU_RUN_TEST(test_ft_isprint_n);
	MU_RUN_TEST(test_ft_isprint_o);
	MU_RUN_TEST(test_ft_isprint_p);
	MU_RUN_TEST(test_ft_isprint_q);
	MU_RUN_TEST(test_ft_isprint_r);
	MU_RUN_TEST(test_ft_isprint_s);
	MU_RUN_TEST(test_ft_isprint_t);
	MU_RUN_TEST(test_ft_isprint_u);
	MU_RUN_TEST(test_ft_isprint_v);
	MU_RUN_TEST(test_ft_isprint_w);
	MU_RUN_TEST(test_ft_isprint_x);
	MU_RUN_TEST(test_ft_isprint_y);
	MU_RUN_TEST(test_ft_isprint_z);
	MU_RUN_TEST(test_ft_isprint_left_brace);
	MU_RUN_TEST(test_ft_isprint_vertical_bar);
	MU_RUN_TEST(test_ft_isprint_right_brace);
	MU_RUN_TEST(test_ft_isprint_tilde);
	MU_RUN_TEST(test_ft_isprint_tilde_plus_one);
	MU_RUN_TEST(test_ft_isprint_newline);
	MU_RUN_TEST(test_ft_isprint_tab);
	MU_RUN_TEST(test_ft_isprint_null);
}

int main(void) {
	MU_RUN_SUITE(ft_isprint_test_suite);
	MU_REPORT();
	return 0;
}
