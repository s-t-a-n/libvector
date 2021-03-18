/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   destroy.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/06 18:50:42 by sverschu      #+#    #+#                 */
/*   Updated: 2020/09/20 00:02:28 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

void	*vec_destroy(void **root, size_t is_malloced, void *obj)
{
	t_vector	*vec;
	int			(*your_free)(void *obj);

	if (!root || !*root)
		return (NULL);
	vec = (t_vector *)*root;
	if (is_malloced)
	{
		if (obj != NULL)
			your_free = (int (*)(void *))obj;
		while (vec->size > 0)
		{
			if (obj)
				your_free(vec_popback(root, 0, obj));
			else
				free(vec_popback(root, 0, obj));
		}
	}
	free(vec->mem);
	free(*root);
	*root = NULL;
	return (NULL);
}
