/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   popback.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/07 16:19:49 by sverschu      #+#    #+#                 */
/*   Updated: 2020/08/07 16:19:57 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

void			*vec_popback(void **root, t_sizes size, void *obj)
{
	t_vector	*vec;

	vec = (t_vector *)*root;
	if (vec->size > 0)
	{
		if (vec->c_free)
			vec->c_free(vec->mem[vec->back], size, obj);
		else
			free(vec->mem[vec->back]);
		vec->back--;
		vec->size--;
	}
	return (NULL);
}
