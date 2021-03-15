/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_nth_rev.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/07 16:11:06 by sverschu      #+#    #+#                 */
/*   Updated: 2020/09/06 19:38:19 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

void			*vec_find_nth_rev(void **root, size_t n, void *obj)
{
	int			(*f)(void *obj);
	ssize_t		index;
	t_vector	*vec;

	f = (int (*)(void *))obj;
	vec = (t_vector *)*root;
	index = vec->size - 1;
	while (index >= 0)
	{
		if (f(vec->mem[index]))
		{
			if (n == 0)
				return (vec->mem[index]);
			n--;
		}
		index--;
	}
	return (NULL);
}
