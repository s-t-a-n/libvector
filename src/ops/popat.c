/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   popat.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/07 16:13:15 by sverschu      #+#    #+#                 */
/*   Updated: 2020/08/07 16:17:44 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

void			*vec_popat(void **root, t_sizes size, void *obj)
{
	size_t		index;
	t_vector	*vec;

	vec = (t_vector *)*root;
	index = *(size_t *)obj;
	if (vec->size > 0 && index > vec->front && index < vec->back)
	{
		if (vec->c_free)
			vec->c_free(vec->mem[index], size, obj);
		else
			free(vec->mem[index]);
		ft_memmove(vec->mem[index], vec->mem[index + 1],
				(vec->size - index - 1) * size);
		vec->mem[vec->back] = NULL;
		vec->back--;
		vec->size--;
	}
	return (NULL);
}
