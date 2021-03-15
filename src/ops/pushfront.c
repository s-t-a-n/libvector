/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushfront.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/07 16:00:07 by sverschu      #+#    #+#                 */
/*   Updated: 2020/09/06 16:03:02 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

void			*vec_pushfront(void **root, size_t n, void *obj)
{
	t_vector *vec;

	vec = (t_vector *)*root;
	vec->size++;
	if (vec->size >= vec->cap && !reallocate(vec, vec->cap, vec->cap * 2))
		return (NULL);
	if (vec->front > 0)
	{
		vec->front--;
		vec->mem[vec->front] = obj;
	}
	else
	{
		ft_memmove(&vec->mem[vec->front + 1], &vec->mem[vec->front],
				(vec->size - 1) * sizeof(void *));
		vec->mem[vec->front] = obj;
	}
	return (root);
	(void)n;
}
