/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushfront.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/07 16:00:07 by sverschu      #+#    #+#                 */
/*   Updated: 2020/08/07 16:21:34 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

void			*vec_pushfront(void **root, t_sizes size, void *obj)
{
	t_vector *vec;

	vec = (t_vector *)*root;
	if (vec->size == vec->cap && !resize(vec, vec->cap, vec->cap * 2))
		return (NULL);
	if (vec->front > 0)
	{
		vec->front--;
		ft_memcpy(vec->mem[vec->front], obj, size);
		vec->size++;
	}
	else
	{
		ft_memmove(vec->mem[vec->front + 1], vec->mem[vec->front],
				vec->size * size);
		ft_memcpy(vec->mem[vec->front], obj, size);
		vec->size++;
	}
	return (root);
}
