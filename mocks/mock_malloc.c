/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:17:33 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/22 16:43:51 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>

int mock_malloc_memset_active = 0;
int mock_malloc_failure_active = 0;

void* malloc(size_t size) {
	void *(*original_malloc)(size_t);
	char *error;

	// Get the pointer to the original malloc function
	original_malloc = dlsym(RTLD_NEXT, "malloc");
	if ((error = dlerror()) != NULL) {
		fprintf(stderr, "%s\n", error);
		exit(EXIT_FAILURE);
	}

	if (mock_malloc_failure_active) {
		return (NULL);
	}

	if (mock_malloc_memset_active) {
		void *tmp = original_malloc(size + 1);
		if (tmp != NULL) {
			memset(tmp, 0xFF, size + 1);
		}
		return (tmp);
	}

	return (original_malloc(size));
}
