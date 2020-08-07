/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   popfront.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/07 16:12:35 by sverschu      #+#    #+#                 */
/*   Updated: 2020/08/07 16:20:09 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

void			*vec_popfront(void **root, t_sizes size, void *obj)
{
	t_vector	*vec;

	vec = (t_vector *)*root;
	if (vec->size > 0)
	{
		if (vec->c_free)
			vec->c_free(vec->mem[vec->front], size, obj);
		else
			free(vec->mem[vec->front]);
		vec->front++;
		vec->size--;
	}
	return (NULL);
}
