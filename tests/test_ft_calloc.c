/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:14:15 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/19 19:43:01 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include "minunit.h"

void	*ft_calloc(size_t nmemb, size_t size);

extern int mock_malloc_active;

MU_TEST(test_ft_calloc_nmeb_zero)
{
	// ARRANGE
	char	*actual_result;

	// ACT
	actual_result = ft_calloc(0, 1);

	// ASSERT
	mu_assert(actual_result != NULL, "Expected non-NULL pointer");

	// CLEANUP
	free(actual_result);
}

MU_TEST(test_ft_calloc_size_zero)
{
	// ARRANGE
	char	*actual_result;

	// ACT
	actual_result = ft_calloc(1, 0);

	// ASSERT
	mu_assert(actual_result != NULL, "Expected non-NULL pointer");

	// CLEANUP
	free(actual_result);
}

MU_TEST(test_ft_calloc_nmeb_zero_size_zero)
{
	// ARRANGE
	char	*actual_result;

	// ACT
	actual_result = ft_calloc(0, 0);

	// ASSERT
	mu_assert(actual_result != NULL, "Expected non-NULL pointer");

	// CLEANUP
	free(actual_result);
}

MU_TEST(test_ft_calloc_nmeb_one_size_one)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;

	// ACT
	expected_result = malloc(1);
	if (!expected_result) {
		mu_fail("Memory allocation failed");
		return;
	}
	memset(expected_result, 0, 1);
	actual_result = ft_calloc(1, 1);
	if (!actual_result) {
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	if (((char*) expected_result)[1] == ((char*) actual_result)[1])
		mu_assert_mem_eq(expected_result, actual_result, 1);
	else
		mu_fail("Incorrect allocation size. Expected was 1 byte");

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_calloc_nmeb_three_size_one)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;

	// ACT
	expected_result = malloc(3);
	if (!expected_result) {
		mu_fail("Memory allocation failed");
		return;
	}
	memset(expected_result, 0, 3);
	actual_result = ft_calloc(3, 1);
	if (!actual_result) {
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	if (((char*) expected_result)[3] == ((char*) actual_result)[3])
		mu_assert_mem_eq(expected_result, actual_result, 3);
	else
		mu_fail("Incorrect allocation size. Expected was 3 bytes");

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_calloc_nmeb_one_size_three)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;

	// ACT
	expected_result = malloc(3);
	if (!expected_result) {
		mu_fail("Memory allocation failed");
		return;
	}
	memset(expected_result, 0, 3);
	actual_result = ft_calloc(1, 3);
	if (!actual_result) {
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	if (((char*) expected_result)[3] == ((char*) actual_result)[3])
		mu_assert_mem_eq(expected_result, actual_result, 3);
	else
		mu_fail("Incorrect allocation size. Expected was 3 bytes");

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_calloc_nmeb_two_size_three)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;

	// ACT
	expected_result = malloc(6);
	if (!expected_result) {
		mu_fail("Memory allocation failed");
		return;
	}
	memset(expected_result, 0, 6);
	actual_result = ft_calloc(2, 3);
	if (!actual_result) {
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	if (((char*) expected_result)[6] == ((char*) actual_result)[6])
		mu_assert_mem_eq(expected_result, actual_result, 6);
	else
		mu_fail("Incorrect allocation size. Expected was 6 bytes");

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_calloc_nmeb_two_size_four)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;

	// ACT
	expected_result = malloc(8);
	if (!expected_result) {
		mu_fail("Memory allocation failed");
		return;
	}
	memset(expected_result, 0, 8);
	actual_result = ft_calloc(2, 4);
	if (!actual_result) {
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	if (((char*) expected_result)[8] == ((char*) actual_result)[8])
		mu_assert_mem_eq(expected_result, actual_result, 8);
	else
		mu_fail("Incorrect allocation size. Expected was 8 bytes");

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_calloc_nmeb_four_size_two)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;

	// ACT
	expected_result = malloc(8);
	if (!expected_result) {
		mu_fail("Memory allocation failed");
		return;
	}
	memset(expected_result, 0, 8);
	actual_result = ft_calloc(4, 2);
	if (!actual_result) {
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	if (((char*) expected_result)[8] == ((char*) actual_result)[8])
		mu_assert_mem_eq(expected_result, actual_result, 8);
	else
		mu_fail("Incorrect allocation size. Expected was 8 bytes");

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST(test_ft_calloc_nmeb_forty_two_size_forty_two)
{
	// ARRANGE
	void	*expected_result;
	void	*actual_result;

	// ACT
	expected_result = malloc(42 * 42);
	if (!expected_result) {
		mu_fail("Memory allocation failed");
		return;
	}
	memset(expected_result, 0, 42 * 42);
	actual_result = ft_calloc(42, 42);
	if (!actual_result) {
		free(expected_result);
		mu_fail("Memory allocation failed");
		return;
	}

	// ASSERT
	if (((char*) expected_result)[42 * 42] == ((char*) actual_result)[42 * 42])
		mu_assert_mem_eq(expected_result, actual_result, 42 * 42);
	else
		mu_fail("Incorrect allocation size. Expected was 1764 bytes");

	// CLEANUP
	free(actual_result);
	free(expected_result);
}

MU_TEST_SUITE(ft_calloc_test_suite)
{
	MU_RUN_TEST(test_ft_calloc_nmeb_zero);
	MU_RUN_TEST(test_ft_calloc_size_zero);
	MU_RUN_TEST(test_ft_calloc_nmeb_zero_size_zero);
	MU_RUN_TEST(test_ft_calloc_nmeb_one_size_one);
	MU_RUN_TEST(test_ft_calloc_nmeb_three_size_one);
	MU_RUN_TEST(test_ft_calloc_nmeb_one_size_three);
	MU_RUN_TEST(test_ft_calloc_nmeb_two_size_three);
	MU_RUN_TEST(test_ft_calloc_nmeb_two_size_four);
	MU_RUN_TEST(test_ft_calloc_nmeb_four_size_two);
	MU_RUN_TEST(test_ft_calloc_nmeb_forty_two_size_forty_two);
}

int	main(void) {
	mock_malloc_active = 1;
	MU_RUN_SUITE(ft_calloc_test_suite);
	mock_malloc_active = 0;
	MU_REPORT();
	return MU_EXIT_CODE;
}
