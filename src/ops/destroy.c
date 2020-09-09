/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   destroy.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/06 18:50:42 by sverschu      #+#    #+#                 */
/*   Updated: 2020/09/06 18:11:23 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

void	*vec_destroy(void **root, size_t is_malloced, void *obj)
{
	t_vector *vec;

	if (!root || !*root)
		return (NULL);
	vec = (t_vector *)*root;
	if (is_malloced)
	{
		while(vec->size > 0)
		{
			free(vec_peekback(root, 0, obj));
			vec_popback(root, 0, obj);
		}
	}
	free(vec->mem);
	free(*root);
	*root = NULL;
	return (NULL);
}
