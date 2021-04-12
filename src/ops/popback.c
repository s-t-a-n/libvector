/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   popback.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/07 16:19:49 by sverschu      #+#    #+#                 */
/*   Updated: 2020/09/06 16:12:29 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "assert.h"
#include "vector_internal.h"

void			*vec_popback(void **root, size_t n, void *obj)
{
	t_vector	*vec;

	vec = (t_vector *)*root;
	if (vec->size > 0)
	{
		obj = vec->mem[vec->back];
		vec->mem[vec->back] = NULL;
		if (vec->back > 0)
			vec->back--;
		vec->size--;
		return (obj);
	}
	(void)n;
	return (NULL);
}
