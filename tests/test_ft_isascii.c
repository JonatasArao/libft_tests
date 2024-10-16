/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:25:44 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/16 08:15:58 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

int	ft_isascii(int c);

MU_TEST(test_ft_isascii_null) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('\0');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_start_of_heading) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii(1);

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_start_of_text) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii(2);

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_end_of_text) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii(3);

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_end_of_transmission) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii(4);

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_enquiry) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii(5);

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_acknowledge) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii(6);

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_bell) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('\a');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_backspace) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('\b');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_tab) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('\t');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_newline) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('\n');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_vertical_tab) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('\v');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_form_feed) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('\f');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_carriage_return) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('\r');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_shift_out) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii(14);

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_shift_in) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii(15);

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_data_link_escape) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii(16);

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_device_control_1) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii(17);

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_device_control_2) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii(18);

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_device_control_3) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii(19);

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_device_control_4) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii(20);

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_negative_acknowledge) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii(21);

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_synchronous_idle) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii(22);

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_end_of_trans_block) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii(23);

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_cancel) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii(24);

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_end_of_medium) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii(25);

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_substitute) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii(26);

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_escape) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii(27);

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_file_separator) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii(28);

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_group_separator) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii(29);

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_record_separator) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii(30);

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_unit_separator) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii(31);

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_space) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii(' ');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_exclamation) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('!');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_double_quote) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('"');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_hash) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('#');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_dollar) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('$');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_percent) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('%');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_ampersand) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('&');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_single_quote) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('\'');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_left_parenthesis) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('(');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_right_parenthesis) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii(')');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_asterisk) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('*');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_plus) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('+');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_comma) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii(',');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_minus) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('-');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_period) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('.');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_slash) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('/');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_zero) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('0');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_one) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('1');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_two) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('2');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_three) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('3');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_four) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('4');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_five) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('5');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_six) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('6');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_seven) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('7');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_eight) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('8');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_nine) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('9');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_colon) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii(':');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_semicolon) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii(';');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_less_than) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('<');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_equal) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('=');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_greater_than) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('>');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_question) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('?');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_at) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('@');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_A) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('A');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_B) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('B');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_C) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('C');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_D) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('D');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_E) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('E');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_F) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('F');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_G) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('G');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_H) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('H');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_I) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('I');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_J) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('J');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_K) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('K');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_L) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('L');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_M) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('M');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_N) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('N');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_O) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('O');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_P) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('P');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_Q) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('Q');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_R) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('R');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_S) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('S');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_T) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('T');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_U) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('U');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_V) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('V');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_W) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('W');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_X) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('X');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_Y) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('Y');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_Z) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('Z');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_left_bracket) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('[');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_backslash) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('\\');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_right_bracket) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii(']');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_caret) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('^');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_underscore) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('_');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_grave) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('`');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_a) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('a');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_b) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('b');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_c) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('c');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_d) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('d');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_e) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('e');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_f) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('f');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_g) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('g');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_h) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('h');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_i) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('i');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_j) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('j');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_k) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('k');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_l) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('l');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_m) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('m');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_n) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('n');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_o) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('o');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_p) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('p');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_q) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('q');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_r) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('r');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_s) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('s');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_t) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('t');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_u) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('u');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_v) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('v');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_w) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('w');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_x) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('x');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_y) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('y');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_z) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('z');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_left_brace) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('{');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_vertical_bar) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('|');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_right_brace) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('}');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_tilde) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii('~');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_delete) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isascii(127);

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isascii_128)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isascii(128);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}
MU_TEST(test_ft_isascii_non_ascii_cedilla)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isascii(231); // 'ç'

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isascii_non_ascii_enye)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isascii(241); // 'ñ'

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isascii_non_ascii_umlaut_u)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isascii(252); // 'ü'

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isascii_non_ascii_o_slash)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isascii(248); // 'ø'

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isascii_non_ascii_sharp_s)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isascii(223); // 'ß'

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isascii_max_unsigned_char)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isascii(255);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isascii_negative_value)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isascii(-1);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isascii_large_value)
{
	// ARRANGE
	int expected_result;
	int actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isascii(300);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_isascii_test_suite) {
	MU_RUN_TEST(test_ft_isascii_null);
	MU_RUN_TEST(test_ft_isascii_start_of_heading);
	MU_RUN_TEST(test_ft_isascii_start_of_text);
	MU_RUN_TEST(test_ft_isascii_end_of_text);
	MU_RUN_TEST(test_ft_isascii_end_of_transmission);
	MU_RUN_TEST(test_ft_isascii_enquiry);
	MU_RUN_TEST(test_ft_isascii_acknowledge);
	MU_RUN_TEST(test_ft_isascii_bell);
	MU_RUN_TEST(test_ft_isascii_backspace);
	MU_RUN_TEST(test_ft_isascii_tab);
	MU_RUN_TEST(test_ft_isascii_newline);
	MU_RUN_TEST(test_ft_isascii_vertical_tab);
	MU_RUN_TEST(test_ft_isascii_form_feed);
	MU_RUN_TEST(test_ft_isascii_carriage_return);
	MU_RUN_TEST(test_ft_isascii_shift_out);
	MU_RUN_TEST(test_ft_isascii_shift_in);
	MU_RUN_TEST(test_ft_isascii_data_link_escape);
	MU_RUN_TEST(test_ft_isascii_device_control_1);
	MU_RUN_TEST(test_ft_isascii_device_control_2);
	MU_RUN_TEST(test_ft_isascii_device_control_3);
	MU_RUN_TEST(test_ft_isascii_device_control_4);
	MU_RUN_TEST(test_ft_isascii_negative_acknowledge);
	MU_RUN_TEST(test_ft_isascii_synchronous_idle);
	MU_RUN_TEST(test_ft_isascii_end_of_trans_block);
	MU_RUN_TEST(test_ft_isascii_cancel);
	MU_RUN_TEST(test_ft_isascii_end_of_medium);
	MU_RUN_TEST(test_ft_isascii_substitute);
	MU_RUN_TEST(test_ft_isascii_escape);
	MU_RUN_TEST(test_ft_isascii_file_separator);
	MU_RUN_TEST(test_ft_isascii_group_separator);
	MU_RUN_TEST(test_ft_isascii_record_separator);
	MU_RUN_TEST(test_ft_isascii_unit_separator);
	MU_RUN_TEST(test_ft_isascii_space);
	MU_RUN_TEST(test_ft_isascii_exclamation);
	MU_RUN_TEST(test_ft_isascii_double_quote);
	MU_RUN_TEST(test_ft_isascii_hash);
	MU_RUN_TEST(test_ft_isascii_dollar);
	MU_RUN_TEST(test_ft_isascii_percent);
	MU_RUN_TEST(test_ft_isascii_ampersand);
	MU_RUN_TEST(test_ft_isascii_single_quote);
	MU_RUN_TEST(test_ft_isascii_left_parenthesis);
	MU_RUN_TEST(test_ft_isascii_right_parenthesis);
	MU_RUN_TEST(test_ft_isascii_asterisk);
	MU_RUN_TEST(test_ft_isascii_plus);
	MU_RUN_TEST(test_ft_isascii_comma);
	MU_RUN_TEST(test_ft_isascii_minus);
	MU_RUN_TEST(test_ft_isascii_period);
	MU_RUN_TEST(test_ft_isascii_slash);
	MU_RUN_TEST(test_ft_isascii_zero);
	MU_RUN_TEST(test_ft_isascii_one);
	MU_RUN_TEST(test_ft_isascii_two);
	MU_RUN_TEST(test_ft_isascii_three);
	MU_RUN_TEST(test_ft_isascii_four);
	MU_RUN_TEST(test_ft_isascii_five);
	MU_RUN_TEST(test_ft_isascii_six);
	MU_RUN_TEST(test_ft_isascii_seven);
	MU_RUN_TEST(test_ft_isascii_eight);
	MU_RUN_TEST(test_ft_isascii_nine);
	MU_RUN_TEST(test_ft_isascii_colon);
	MU_RUN_TEST(test_ft_isascii_semicolon);
	MU_RUN_TEST(test_ft_isascii_less_than);
	MU_RUN_TEST(test_ft_isascii_equal);
	MU_RUN_TEST(test_ft_isascii_greater_than);
	MU_RUN_TEST(test_ft_isascii_question);
	MU_RUN_TEST(test_ft_isascii_at);
	MU_RUN_TEST(test_ft_isascii_A);
	MU_RUN_TEST(test_ft_isascii_B);
	MU_RUN_TEST(test_ft_isascii_C);
	MU_RUN_TEST(test_ft_isascii_D);
	MU_RUN_TEST(test_ft_isascii_E);
	MU_RUN_TEST(test_ft_isascii_F);
	MU_RUN_TEST(test_ft_isascii_G);
	MU_RUN_TEST(test_ft_isascii_H);
	MU_RUN_TEST(test_ft_isascii_I);
	MU_RUN_TEST(test_ft_isascii_J);
	MU_RUN_TEST(test_ft_isascii_K);
	MU_RUN_TEST(test_ft_isascii_L);
	MU_RUN_TEST(test_ft_isascii_M);
	MU_RUN_TEST(test_ft_isascii_N);
	MU_RUN_TEST(test_ft_isascii_O);
	MU_RUN_TEST(test_ft_isascii_P);
	MU_RUN_TEST(test_ft_isascii_Q);
	MU_RUN_TEST(test_ft_isascii_R);
	MU_RUN_TEST(test_ft_isascii_S);
	MU_RUN_TEST(test_ft_isascii_T);
	MU_RUN_TEST(test_ft_isascii_U);
	MU_RUN_TEST(test_ft_isascii_V);
	MU_RUN_TEST(test_ft_isascii_W);
	MU_RUN_TEST(test_ft_isascii_X);
	MU_RUN_TEST(test_ft_isascii_Y);
	MU_RUN_TEST(test_ft_isascii_Z);
	MU_RUN_TEST(test_ft_isascii_left_bracket);
	MU_RUN_TEST(test_ft_isascii_backslash);
	MU_RUN_TEST(test_ft_isascii_right_bracket);
	MU_RUN_TEST(test_ft_isascii_caret);
	MU_RUN_TEST(test_ft_isascii_underscore);
	MU_RUN_TEST(test_ft_isascii_grave);
	MU_RUN_TEST(test_ft_isascii_a);
	MU_RUN_TEST(test_ft_isascii_b);
	MU_RUN_TEST(test_ft_isascii_c);
	MU_RUN_TEST(test_ft_isascii_d);
	MU_RUN_TEST(test_ft_isascii_e);
	MU_RUN_TEST(test_ft_isascii_f);
	MU_RUN_TEST(test_ft_isascii_g);
	MU_RUN_TEST(test_ft_isascii_h);
	MU_RUN_TEST(test_ft_isascii_i);
	MU_RUN_TEST(test_ft_isascii_j);
	MU_RUN_TEST(test_ft_isascii_k);
	MU_RUN_TEST(test_ft_isascii_l);
	MU_RUN_TEST(test_ft_isascii_m);
	MU_RUN_TEST(test_ft_isascii_n);
	MU_RUN_TEST(test_ft_isascii_o);
	MU_RUN_TEST(test_ft_isascii_p);
	MU_RUN_TEST(test_ft_isascii_q);
	MU_RUN_TEST(test_ft_isascii_r);
	MU_RUN_TEST(test_ft_isascii_s);
	MU_RUN_TEST(test_ft_isascii_t);
	MU_RUN_TEST(test_ft_isascii_u);
	MU_RUN_TEST(test_ft_isascii_v);
	MU_RUN_TEST(test_ft_isascii_w);
	MU_RUN_TEST(test_ft_isascii_x);
	MU_RUN_TEST(test_ft_isascii_y);
	MU_RUN_TEST(test_ft_isascii_z);
	MU_RUN_TEST(test_ft_isascii_left_brace);
	MU_RUN_TEST(test_ft_isascii_vertical_bar);
	MU_RUN_TEST(test_ft_isascii_right_brace);
	MU_RUN_TEST(test_ft_isascii_tilde);
	MU_RUN_TEST(test_ft_isascii_delete);
	MU_RUN_TEST(test_ft_isascii_128);
	MU_RUN_TEST(test_ft_isascii_non_ascii_cedilla);
	MU_RUN_TEST(test_ft_isascii_non_ascii_enye);
	MU_RUN_TEST(test_ft_isascii_non_ascii_umlaut_u);
	MU_RUN_TEST(test_ft_isascii_non_ascii_o_slash);
	MU_RUN_TEST(test_ft_isascii_non_ascii_sharp_s);
	MU_RUN_TEST(test_ft_isascii_max_unsigned_char);
	MU_RUN_TEST(test_ft_isascii_negative_value);
	MU_RUN_TEST(test_ft_isascii_large_value);
}

int main(void) {
	MU_RUN_SUITE(ft_isascii_test_suite);
	MU_REPORT();
	return 0;
}
