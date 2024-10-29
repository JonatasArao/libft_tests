/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:17:33 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/29 15:23:08 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>

// Global variables to control the behavior of the mock free function
int mock_free_failure_active = 0; // Flag to activate mock behavior in free
int mock_free_memset_active = 0; // Flag to activate mock behavior in free
int mock_free_memset_size = 0; // Flag to activate mock behavior in free

// Mock free function
void free(void *ptr) {
	void (*original_free)(void *); // Pointer to the original free function
	char *error;

	// Get the pointer to the original free function
	original_free = dlsym(RTLD_NEXT, "free");
	if ((error = dlerror()) != NULL) { // Check for errors in dlsym
		fprintf(stderr, "%s\n", error); // Print the error message
		exit(EXIT_FAILURE); // Exit the program in case of error
	}

	// If mock free failure and memset size are active, return early
	if (mock_free_memset_active && mock_free_memset_size && ptr) {
		memset(ptr, 0xFF, mock_free_memset_size); // Set allocated memory to 0xFF
		return ; // Return early to avoid calling the original free function
	}

	// If mock behavior is active, return early to avoid calling the original free function
	if (mock_free_failure_active) {
		return ; // Return early to avoid calling the original free function
	}

	// Call the original free function
	original_free(ptr);
}
