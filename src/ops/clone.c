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

static void		clone(t_vector *dst, t_vector *src)
{
	void		**tmp_mem;

	tmp_mem = dst->mem;
	ft_memcpy(dst, src, sizeof(t_vector));
	dst->mem = tmp_mem;
	ft_memcpy(dst->mem, src->mem, dst->cap);
}

void			*vec_clone(void **root, size_t n, void *obj)
{
	void		*new_root;

	if (!root || !*root)
		return (NULL);
	new_root = malloc(sizeof(t_vector));
	if (new_root && vec_create(&new_root, n,
				(void *)&((t_vector *)*root)->cap))
	{
		clone((t_vector *)new_root, (t_vector *)*root);
		return (new_root);
	}
	else
		return (NULL);
	(void)obj;
}
