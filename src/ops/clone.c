/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clone.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/06 19:51:57 by sverschu      #+#    #+#                 */
/*   Updated: 2020/09/06 16:11:42 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

static void		clone(t_vector *dst, t_vector *src, size_t n)
{
	if (n > src->size)
	{
		dst->size = src->size;
		ft_memcpy(dst->mem,
					&src->mem[src->front],
					src->size * sizeof(void *));
	}
	else
	{
		ft_memcpy(dst->mem,
					&src->mem[src->front],
					n * sizeof(void *));
		dst->size = n;
	}
	dst->front = 0;
	dst->back = dst->size - 1;
}

void			*vec_clone(void **old_root, size_t n, void *obj)
{
	void		**new_root;

	if (!old_root || !*old_root || !obj)
		return (NULL);
	new_root = (void **)obj;
	if (n == 0)
		n = ((t_vector *)*old_root)->size;
	if (vec_create(new_root, n, NULL) != NULL)
	{
		clone((t_vector *)*new_root, (t_vector *)*old_root, n);
		return (obj);
	}
	return (NULL);
}
