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

void			*vec_peekat(void **root, size_t index, void *obj)
{
	t_vector	*vec;

	vec = (t_vector *)*root;
	if (index > vec->front && index < vec->back)
		return (vec->mem[index]);
	else
		return (NULL);
	(void)obj;
}
