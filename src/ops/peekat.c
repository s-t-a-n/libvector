/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   peekat.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/07 16:11:06 by sverschu      #+#    #+#                 */
/*   Updated: 2020/09/06 19:38:19 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

void			*vec_peekat(void **root, size_t index, void *obj)
{
	t_vector	*vec;

	vec = (t_vector *)*root;
	if (vec->size > 0 && index <= vec->front + vec->back)
	{
		index += vec->front;
		return (vec->mem[index]);
	}
	return (NULL);
	(void)obj;
}
