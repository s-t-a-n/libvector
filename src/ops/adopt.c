/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   adopt.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/13 18:15:53 by sverschu      #+#    #+#                 */
/*   Updated: 2021/03/14 16:00:26 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

static void		*initialize(void **root, size_t size, void **mem)
{
	t_vector *vec;

	vec = (t_vector *)*root;
	vec->mem = mem;
	vec->cap = size;
	vec->size = size;
	vec->front = 0;
	vec->back = (size > 0) ? size - 1 : size;
	return (root);
}

void			*vec_adopt(void **root, size_t size, void *obj)
{
	if (!root || size == 0)
	{
		return (NULL);
	}
	else
	{
		*root = ft_calloc(1, sizeof(t_vector));
		return (*root ? initialize(root, size, (void **)obj) : NULL);
	}
}