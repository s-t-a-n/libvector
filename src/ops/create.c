/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/06 18:15:53 by sverschu      #+#    #+#                 */
/*   Updated: 2020/08/07 17:12:51 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

#include <stdio.h>

static void		*unroll_and_free(void **root, size_t cap, size_t halt)
{
	t_vector *vec;

	vec = (t_vector *)*root;
	while (cap > halt)
	{
		free(vec->mem[cap - 1]);
		cap--;
	}
	free(vec->mem);
	free(*root);
	*root = NULL;
	return (root);
}

static void		*initialize(void **root, size_t size, size_t cap)
{
	t_vector *vec;

	vec = (t_vector *)*root;
	vec->mem = ft_calloc(cap, sizeof(void *));
	if (vec->mem)
	{
		vec->cap = cap;
		vec->size = 0;
		vec->front = 0;
		vec->back = 0;
		vec->elemsize = size;
		while (cap > 0)
		{
			vec->mem[cap - 1] = ft_calloc(1, size);
			if (!vec->mem[cap - 1])
				return (unroll_and_free(root, vec->cap, cap));
			cap--;
		}
		return (root);
	}
	else
	{
		free(*root);
		*root = NULL;
		return (NULL);
	}
}

void			*vec_create(void **root, size_t size, void *obj)
{
	if (!root || size <= 0 || !obj || *(size_t *)obj <= 0)
	{
		return (NULL);
	}
	else
	{
		*root = ft_calloc(1, sizeof(t_vector));
		return (*root ? initialize(root, size, *(size_t *)obj) : NULL);
	}
}
