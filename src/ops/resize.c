/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   resize.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 18:15:53 by sverschu      #+#    #+#                 */
/*   Updated: 2021/03/15 16:00:26 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

static void		remove_and_destroy(t_vector *old_vec,
									size_t new_size)
{
	while (old_vec->size > new_size)
		old_vec->free(vec_popback((void **)&old_vec, 0, NULL));
	free(old_vec->mem);
	free(old_vec);
}

void			*vec_resize(void **root, size_t new_size, void *obj)
{
	void		*new_root;

	if (!root || new_size == 0)
	{
		return (NULL);
	}
	else
	{
		if (vec_clone(root, new_size, &new_root))
		{
			remove_and_destroy((t_vector *)*root, new_size);
			*root = new_root;
			return (root);
		}
		return (NULL);
	}
	(void)obj;
}
