/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isspace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:25:44 by jarao-de          #+#    #+#             */
/*   Updated: 2025/01/24 15:01:08 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

int	ft_isspace(int c);

MU_TEST(test_ft_isspace_null) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(255);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_start_of_heading) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(1);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_start_of_text) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(2);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_end_of_text) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(3);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_end_of_transmission) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(4);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_enquiry) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(5);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_acknowledge) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(6);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_bell) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('\a');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_backspace) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('\b');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_tab) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isspace('\t');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isspace_newline) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isspace('\n');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isspace_vertical_tab) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isspace('\v');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isspace_form_feed) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isspace('\f');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isspace_carriage_return) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isspace('\r');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isspace_shift_out) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(14);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_shift_in) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(15);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_data_link_escape) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(16);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_device_control_1) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(17);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_device_control_2) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(18);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_device_control_3) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(19);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_device_control_4) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(20);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_negative_acknowledge) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(21);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_synchronous_idle) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(22);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_end_of_trans_block) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(23);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_cancel) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(24);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_end_of_medium) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(25);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_substitute) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(26);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_escape) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(27);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_file_separator) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(28);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_group_separator) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(29);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_record_separator) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(30);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_unit_separator) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(31);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_space) {
	// ARRANGE
	int actual_result;

	// ACT
	actual_result = ft_isspace(' ');

	// ASSERT
	mu_assert(actual_result != 0, "expected nonzero value");
}

MU_TEST(test_ft_isspace_exclamation) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('!');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_double_quote) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('"');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_hash) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('#');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_dollar) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('$');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_percent) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('%');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_ampersand) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('&');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_single_quote) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('\'');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_left_parenthesis) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('(');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_right_parenthesis) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(')');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_asterisk) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('*');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_plus) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('+');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_comma) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(',');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_minus) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('-');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_period) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('.');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_slash) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('/');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_zero) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('0');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_one) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('1');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_two) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('2');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_three) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('3');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_four) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('4');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_five) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('5');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_six) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('6');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_seven) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('7');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_eight) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('8');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_nine) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('9');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_colon) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(':');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_semicolon) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(';');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_less_than) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('<');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_equal) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('=');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_greater_than) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('>');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_question) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('?');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_at) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('@');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_A) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('A');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_B) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('B');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_C) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('C');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_D) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('D');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_E) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('E');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_F) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('F');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_G) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('G');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_H) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('H');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_I) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('I');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_J) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('J');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_K) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('K');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_L) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('L');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_M) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('M');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_N) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('N');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_O) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('O');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_P) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('P');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_Q) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('Q');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_R) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('R');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_S) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('S');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_T) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('T');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_U) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('U');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_V) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('V');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_W) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('W');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_X) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('X');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_Y) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('Y');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_Z) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('Z');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_left_bracket) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('[');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_backslash) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('\\');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_right_bracket) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(']');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_caret) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('^');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_underscore) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('_');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_grave) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('`');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_a) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('a');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_b) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('b');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_c) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('c');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_d) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('d');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_e) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('e');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_f) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('f');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_g) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('g');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_h) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('h');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_i) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('i');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_j) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('j');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_k) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('k');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_l) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('l');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_m) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('m');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_n) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('n');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_o) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('o');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_p) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('p');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_q) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('q');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_r) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('r');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_s) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('s');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_t) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('t');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_u) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('u');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_v) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('v');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_w) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('w');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_x) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('x');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_y) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('y');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_z) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('z');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_left_brace) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('{');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_vertical_bar) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('|');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_right_brace) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('}');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_tilde) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace('~');

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_delete) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(127);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_128) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(128);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_non_ascii_cedilla) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(231); // 'ç'

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_non_ascii_enye) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(241); // 'ñ'

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_non_ascii_umlaut_u) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(252); // 'ü'

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_non_ascii_o_slash) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(248); // 'ø'

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_non_ascii_sharp_s) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(223); // 'ß'

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_max_unsigned_char) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(255);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_negative_value) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(-1);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_isspace_large_value) {
	// ARRANGE
	int actual_result;
	int expected_result;

	// ACT
	expected_result = 0;
	actual_result = ft_isspace(300);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_isspace_test_suite) {
	MU_RUN_TEST(test_ft_isspace_null);
	MU_RUN_TEST(test_ft_isspace_start_of_heading);
	MU_RUN_TEST(test_ft_isspace_start_of_text);
	MU_RUN_TEST(test_ft_isspace_end_of_text);
	MU_RUN_TEST(test_ft_isspace_end_of_transmission);
	MU_RUN_TEST(test_ft_isspace_enquiry);
	MU_RUN_TEST(test_ft_isspace_acknowledge);
	MU_RUN_TEST(test_ft_isspace_bell);
	MU_RUN_TEST(test_ft_isspace_backspace);
	MU_RUN_TEST(test_ft_isspace_tab);
	MU_RUN_TEST(test_ft_isspace_newline);
	MU_RUN_TEST(test_ft_isspace_vertical_tab);
	MU_RUN_TEST(test_ft_isspace_form_feed);
	MU_RUN_TEST(test_ft_isspace_carriage_return);
	MU_RUN_TEST(test_ft_isspace_shift_out);
	MU_RUN_TEST(test_ft_isspace_shift_in);
	MU_RUN_TEST(test_ft_isspace_data_link_escape);
	MU_RUN_TEST(test_ft_isspace_device_control_1);
	MU_RUN_TEST(test_ft_isspace_device_control_2);
	MU_RUN_TEST(test_ft_isspace_device_control_3);
	MU_RUN_TEST(test_ft_isspace_device_control_4);
	MU_RUN_TEST(test_ft_isspace_negative_acknowledge);
	MU_RUN_TEST(test_ft_isspace_synchronous_idle);
	MU_RUN_TEST(test_ft_isspace_end_of_trans_block);
	MU_RUN_TEST(test_ft_isspace_cancel);
	MU_RUN_TEST(test_ft_isspace_end_of_medium);
	MU_RUN_TEST(test_ft_isspace_substitute);
	MU_RUN_TEST(test_ft_isspace_escape);
	MU_RUN_TEST(test_ft_isspace_file_separator);
	MU_RUN_TEST(test_ft_isspace_group_separator);
	MU_RUN_TEST(test_ft_isspace_record_separator);
	MU_RUN_TEST(test_ft_isspace_unit_separator);
	MU_RUN_TEST(test_ft_isspace_space);
	MU_RUN_TEST(test_ft_isspace_exclamation);
	MU_RUN_TEST(test_ft_isspace_double_quote);
	MU_RUN_TEST(test_ft_isspace_hash);
	MU_RUN_TEST(test_ft_isspace_dollar);
	MU_RUN_TEST(test_ft_isspace_percent);
	MU_RUN_TEST(test_ft_isspace_ampersand);
	MU_RUN_TEST(test_ft_isspace_single_quote);
	MU_RUN_TEST(test_ft_isspace_left_parenthesis);
	MU_RUN_TEST(test_ft_isspace_right_parenthesis);
	MU_RUN_TEST(test_ft_isspace_asterisk);
	MU_RUN_TEST(test_ft_isspace_plus);
	MU_RUN_TEST(test_ft_isspace_comma);
	MU_RUN_TEST(test_ft_isspace_minus);
	MU_RUN_TEST(test_ft_isspace_period);
	MU_RUN_TEST(test_ft_isspace_slash);
	MU_RUN_TEST(test_ft_isspace_zero);
	MU_RUN_TEST(test_ft_isspace_one);
	MU_RUN_TEST(test_ft_isspace_two);
	MU_RUN_TEST(test_ft_isspace_three);
	MU_RUN_TEST(test_ft_isspace_four);
	MU_RUN_TEST(test_ft_isspace_five);
	MU_RUN_TEST(test_ft_isspace_six);
	MU_RUN_TEST(test_ft_isspace_seven);
	MU_RUN_TEST(test_ft_isspace_eight);
	MU_RUN_TEST(test_ft_isspace_nine);
	MU_RUN_TEST(test_ft_isspace_colon);
	MU_RUN_TEST(test_ft_isspace_semicolon);
	MU_RUN_TEST(test_ft_isspace_less_than);
	MU_RUN_TEST(test_ft_isspace_equal);
	MU_RUN_TEST(test_ft_isspace_greater_than);
	MU_RUN_TEST(test_ft_isspace_question);
	MU_RUN_TEST(test_ft_isspace_at);
	MU_RUN_TEST(test_ft_isspace_A);
	MU_RUN_TEST(test_ft_isspace_B);
	MU_RUN_TEST(test_ft_isspace_C);
	MU_RUN_TEST(test_ft_isspace_D);
	MU_RUN_TEST(test_ft_isspace_E);
	MU_RUN_TEST(test_ft_isspace_F);
	MU_RUN_TEST(test_ft_isspace_G);
	MU_RUN_TEST(test_ft_isspace_H);
	MU_RUN_TEST(test_ft_isspace_I);
	MU_RUN_TEST(test_ft_isspace_J);
	MU_RUN_TEST(test_ft_isspace_K);
	MU_RUN_TEST(test_ft_isspace_L);
	MU_RUN_TEST(test_ft_isspace_M);
	MU_RUN_TEST(test_ft_isspace_N);
	MU_RUN_TEST(test_ft_isspace_O);
	MU_RUN_TEST(test_ft_isspace_P);
	MU_RUN_TEST(test_ft_isspace_Q);
	MU_RUN_TEST(test_ft_isspace_R);
	MU_RUN_TEST(test_ft_isspace_S);
	MU_RUN_TEST(test_ft_isspace_T);
	MU_RUN_TEST(test_ft_isspace_U);
	MU_RUN_TEST(test_ft_isspace_V);
	MU_RUN_TEST(test_ft_isspace_W);
	MU_RUN_TEST(test_ft_isspace_X);
	MU_RUN_TEST(test_ft_isspace_Y);
	MU_RUN_TEST(test_ft_isspace_Z);
	MU_RUN_TEST(test_ft_isspace_left_bracket);
	MU_RUN_TEST(test_ft_isspace_backslash);
	MU_RUN_TEST(test_ft_isspace_right_bracket);
	MU_RUN_TEST(test_ft_isspace_caret);
	MU_RUN_TEST(test_ft_isspace_underscore);
	MU_RUN_TEST(test_ft_isspace_grave);
	MU_RUN_TEST(test_ft_isspace_a);
	MU_RUN_TEST(test_ft_isspace_b);
	MU_RUN_TEST(test_ft_isspace_c);
	MU_RUN_TEST(test_ft_isspace_d);
	MU_RUN_TEST(test_ft_isspace_e);
	MU_RUN_TEST(test_ft_isspace_f);
	MU_RUN_TEST(test_ft_isspace_g);
	MU_RUN_TEST(test_ft_isspace_h);
	MU_RUN_TEST(test_ft_isspace_i);
	MU_RUN_TEST(test_ft_isspace_j);
	MU_RUN_TEST(test_ft_isspace_k);
	MU_RUN_TEST(test_ft_isspace_l);
	MU_RUN_TEST(test_ft_isspace_m);
	MU_RUN_TEST(test_ft_isspace_n);
	MU_RUN_TEST(test_ft_isspace_o);
	MU_RUN_TEST(test_ft_isspace_p);
	MU_RUN_TEST(test_ft_isspace_q);
	MU_RUN_TEST(test_ft_isspace_r);
	MU_RUN_TEST(test_ft_isspace_s);
	MU_RUN_TEST(test_ft_isspace_t);
	MU_RUN_TEST(test_ft_isspace_u);
	MU_RUN_TEST(test_ft_isspace_v);
	MU_RUN_TEST(test_ft_isspace_w);
	MU_RUN_TEST(test_ft_isspace_x);
	MU_RUN_TEST(test_ft_isspace_y);
	MU_RUN_TEST(test_ft_isspace_z);
	MU_RUN_TEST(test_ft_isspace_left_brace);
	MU_RUN_TEST(test_ft_isspace_vertical_bar);
	MU_RUN_TEST(test_ft_isspace_right_brace);
	MU_RUN_TEST(test_ft_isspace_tilde);
	MU_RUN_TEST(test_ft_isspace_delete);
	MU_RUN_TEST(test_ft_isspace_128);
	MU_RUN_TEST(test_ft_isspace_non_ascii_cedilla);
	MU_RUN_TEST(test_ft_isspace_non_ascii_enye);
	MU_RUN_TEST(test_ft_isspace_non_ascii_umlaut_u);
	MU_RUN_TEST(test_ft_isspace_non_ascii_o_slash);
	MU_RUN_TEST(test_ft_isspace_non_ascii_sharp_s);
	MU_RUN_TEST(test_ft_isspace_max_unsigned_char);
	MU_RUN_TEST(test_ft_isspace_negative_value);
	MU_RUN_TEST(test_ft_isspace_large_value);
}

int main(void) {
	MU_RUN_SUITE(ft_isspace_test_suite);
	MU_REPORT();
	return 0;
}
