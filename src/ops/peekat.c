/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   peekat.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/07 16:11:06 by sverschu      #+#    #+#                 */
/*   Updated: 2020/08/07 16:19:16 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

void			*vec_peekat(void **root, t_sizes size, void *obj)
{
	size_t		index;
	t_vector	*vec;

	index = *(size_t *)obj;
	vec = (t_vector *)*root;
	(void)size;
	if (index > vec->front && index < vec->back)
		return (vec->mem[index]);
	else
		return (NULL);
}
