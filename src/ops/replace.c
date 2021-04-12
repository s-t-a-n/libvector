/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   replace.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/07 16:04:13 by sverschu      #+#    #+#                 */
/*   Updated: 2020/09/20 00:02:51 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

void			*vec_replace(void **root, size_t index, void *obj)
{
	t_vector	*vec;

	vec = (t_vector *)*root;
	if (index <= vec->front + vec->back)
	{
		index += vec->front;
		vec->free(vec->mem[index]);
		vec->mem[index] = obj;
		return (obj);
	}
	else
		return (NULL);
}
