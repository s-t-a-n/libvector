/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushat.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/07 16:04:13 by sverschu      #+#    #+#                 */
/*   Updated: 2020/09/20 00:02:51 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

/*
** pushat only allows pushing between existing indices
*/

void			*vec_pushat(void **root, size_t index, void *obj)
{
	t_vector	*vec;

	vec = (t_vector *)*root;
	if (vec->front > 0 && index == 0)
		return (vec_pushfront(root, index, obj));
	else if (index <= vec->front + vec->back)
	{
		vec->size++;
		index += vec->front;
		if (vec->size >= vec->cap && !reallocate(vec, vec->cap, vec->cap * 2))
			return (NULL);
		ft_memmove(&vec->mem[index + 1], &vec->mem[index],
				(vec->size - index - 1) * sizeof(void *));
		vec->mem[index] = obj;
		if (vec->size > 1)
			vec->back++;
		return (root);
	}
	else if (index == vec->size)
		return (vec_pushback(root, index, obj));
	else
		return (NULL);
}
