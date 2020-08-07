/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clone.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/06 19:51:57 by sverschu      #+#    #+#                 */
/*   Updated: 2020/08/07 16:18:47 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

static void		clone(t_vector *dst, t_vector *src, t_sizes size)
{
	void		**tmp_mem;
	size_t		cap;

	tmp_mem = dst->mem;
	ft_memcpy(dst, src, sizeof(t_vector));
	dst->mem = tmp_mem;
	cap = src->cap;
	while (cap > 0)
	{
		if (!src->c_clone)
			ft_memcpy(dst->mem[cap - 1], src->mem[cap - 1], size);
		else
			src->c_clone(dst->mem[cap - 1], src->mem[cap - 1],
				size);
		cap--;
	}
}

void			*vec_clone(void **root, t_sizes size, void *obj)
{
	void		**new_root;

	if (!root || !*root)
		return (NULL);
	new_root = malloc(sizeof(void *));
	if (new_root && vec_create(new_root, size,
				(void *)&((t_vector *)*root)->cap))
	{
		clone((t_vector *)*new_root, (t_vector *)*root, size);
		return (new_root);
	}
	else
		return (NULL);
	(void)obj;
}
