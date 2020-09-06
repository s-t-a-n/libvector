/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushback.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/07 14:47:55 by sverschu      #+#    #+#                 */
/*   Updated: 2020/09/06 15:23:16 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

void			*vec_pushback(void **root, size_t n, void *obj)
{
	t_vector	*vec;

	vec = (t_vector *)*root;
	vec->size++;
	if (vec->size == vec->cap && !resize(vec, vec->cap, vec->cap * 2))
		return (NULL);
	if (vec->size > 0)
		vec->back++;
	ft_memcpy(vec->mem[vec->back], obj, vec->elemsize);
	return (root);
	(void)n;
}
