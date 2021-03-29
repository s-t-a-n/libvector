/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_freefunc.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/29 18:15:53 by sverschu      #+#    #+#                 */
/*   Updated: 2021/03/29 16:00:26 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

void			*vec_set_freefunc(void **root, size_t size, void *obj)
{
	t_vector	*vec;

	if (!root || !obj)
	{
		return (NULL);
	}
	else
	{
		vec = (t_vector *)*root;
		vec->free = (void (*)(void*))obj;
		return (obj);
	}
	(void)size;
}
