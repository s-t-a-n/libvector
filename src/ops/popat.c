/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   popat.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/07 16:13:15 by sverschu      #+#    #+#                 */
/*   Updated: 2020/09/06 16:13:11 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

void			*vec_popat(void **root, size_t index, void *obj)
{
	t_vector	*vec;

	vec = (t_vector *)*root;
	if (vec->size > 0 && index >= vec->front && index <= vec->back)
	{
		obj = vec->mem[index];
		ft_memmove(&vec->mem[index], &vec->mem[index + 1],
				(vec->size - index - 1) * sizeof(void *));
		vec->mem[vec->back] = NULL;
		vec->back--;
		vec->size--;
		return (obj);
	}
	return (NULL);
}
