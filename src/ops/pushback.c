/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushback.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/07 14:47:55 by sverschu      #+#    #+#                 */
/*   Updated: 2020/08/07 16:20:38 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

void			*vec_pushback(void **root, t_sizes size, void *obj)
{
	t_vector	*vec;

	vec = (t_vector *)*root;
	if (vec->size == vec->cap && !resize(vec, vec->cap, vec->cap * 2))
		return (NULL);
	vec->back++;
	vec->size++;
	ft_memcpy(vec->mem[vec->back], obj, size);
	return (root);
}
