/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transform.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/16/04 16:11:06 by sverschu      #+#    #+#                 */
/*   Updated: 2021/16/04 19:38:19 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

void			*vec_transform(void **root, size_t n, void *obj)
{
	int			(*f)(void **obj);
	size_t		index;
	t_vector	*vec;

	f = (int (*)(void **))obj;
	vec = (t_vector *)*root;
	index = 0;
	while (index < vec->size)
	{
		if (!f(&vec->mem[index]))
			return (vec->mem[index]);
		index++;
	}
	return (NULL);
	(void)n;
}
