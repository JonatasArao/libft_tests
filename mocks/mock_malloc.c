/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:17:33 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/24 18:03:10 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>

// Global variables to control the behavior of the mock malloc function
int mock_malloc_memset_active = 0; // Flag to activate memset in malloc
int mock_malloc_failure_active = 0; // Flag to activate malloc failure
int mock_malloc_failure_threshold = 1; // Call count at which malloc should fail
int mock_malloc_failure_counter = 0; // Counter for the number of malloc calls

// Mock malloc function
void* malloc(size_t size) {
	void *(*original_malloc)(size_t); // Function pointer to the original malloc
	char *error;

	// Get the pointer to the original malloc function
	original_malloc = dlsym(RTLD_NEXT, "malloc");
	if ((error = dlerror()) != NULL) { // Check for errors in dlsym
		fprintf(stderr, "%s\n", error); // Print the error message
		exit(EXIT_FAILURE); // Exit the program on error
	}

	// If failure mode is active and the call count matches, return NULL
	if (mock_malloc_failure_active) {
		mock_malloc_failure_counter++;
		if (mock_malloc_failure_counter >= mock_malloc_failure_threshold) {
			mock_malloc_failure_counter = 0;
			return (NULL);
		}
	}

	// If memset mode is active, allocate memory and set it to 0xFF
	if (mock_malloc_memset_active) {
		void *tmp = original_malloc(size + 1); // Allocate extra byte for memset
		if (tmp != NULL) {
			memset(tmp, 0xFF, size + 1); // Set allocated memory to 0xFF
		}
		return (tmp); // Return the allocated memory
	}

	// Otherwise, just return the result of the original malloc
	return (original_malloc(size));
}
