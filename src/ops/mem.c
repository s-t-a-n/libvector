/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mem.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 18:50:42 by sverschu      #+#    #+#                 */
/*   Updated: 2021/03/15 19:10:28 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

void	*vec_mem(void **root, size_t n, void *obj)
{
	void		**mem;
	t_vector	*vec;

	(void)obj;
	if (!root || !*root)
		return (NULL);
	vec = (t_vector *)*root;
	mem = &vec->mem[n];
	return ((void *)mem);
}
