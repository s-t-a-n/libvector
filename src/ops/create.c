/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/06 18:15:53 by sverschu      #+#    #+#                 */
/*   Updated: 2020/09/06 16:00:26 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

#include <stdio.h>

static void		*initialize(void **root, size_t cap)
{
	t_vector *vec;

	vec = (t_vector *)*root;
	vec->mem = ft_calloc(cap, sizeof(void *));
	if (vec->mem)
	{
		vec->cap = cap;
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
	if (!root || size <= 0)
	{
		return (NULL);
	}
	else
	{
		*root = ft_calloc(1, sizeof(t_vector));
		return (*root ? initialize(root, size) : NULL);
	}
	(void)obj;
}
