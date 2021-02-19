/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_nth.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/07 16:11:06 by sverschu      #+#    #+#                 */
/*   Updated: 2020/09/06 19:38:19 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

void			*vec_find_nth(void **root, size_t n, void *obj)
{
	size_t		index;
	t_vector	*vec;
	int	(*f)(void *obj) = (int (*)(void *))obj;

	vec = (t_vector *)*root;
	index = 0;
	while (index < vec->size)
	{
		if (f(vec->mem[index]))
		{
			if (n == 0)
				return (vec->mem[index]);
			n--;
		}
		index++;
	}
	return (NULL);
}
