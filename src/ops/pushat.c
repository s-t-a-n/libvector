/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushat.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/07 16:04:13 by sverschu      #+#    #+#                 */
/*   Updated: 2020/08/07 16:21:19 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

void			*vec_pushat(void **root, size_t index, void *obj)
{
	t_vector	*vec;

	vec = (t_vector *)*root;
	if (index > vec->front && index < vec->back)
	{
		if (vec->size == vec->cap && !resize(vec, vec->cap, vec->cap * 2))
			return (NULL);
		ft_memmove(vec->mem[index + 1], vec->mem[index],
				(vec->size - index - 1) * vec->elemsize);
		ft_memcpy(vec->mem[index], obj, vec->elemsize);
		vec->size++;
		vec->back++;
		return (root);
	}
	else
		return (NULL);
}
