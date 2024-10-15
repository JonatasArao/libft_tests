/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:17:33 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/15 11:34:53 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>

void* malloc(size_t size) {
	void *(*original_malloc)(size_t);
	char *error;

	// Get the pointer to the original malloc function
	original_malloc = dlsym(RTLD_NEXT, "malloc");
	if ((error = dlerror()) != NULL) {
		fprintf(stderr, "%s\n", error);
		exit(EXIT_FAILURE);
	}

	void *tmp = original_malloc(size);
	if (tmp != NULL) {
		memset(tmp, ' ', size);
	}
	return tmp;
}
