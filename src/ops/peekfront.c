/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   peekfront.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/07 15:59:32 by sverschu      #+#    #+#                 */
/*   Updated: 2020/08/07 16:19:39 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

void			*vec_peekfront(void **root, t_sizes size, void *obj)
{
	t_vector *vec;

	vec = (t_vector *)*root;
	(void)size;
	(void)obj;
	if (vec->size > 0)
		return (vec->mem[vec->front]);
	else
		return (NULL);
}
