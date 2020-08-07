/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   destroy.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/06 18:50:42 by sverschu      #+#    #+#                 */
/*   Updated: 2020/08/07 17:10:57 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

void	*vec_destroy(void **root, t_sizes size, void *obj)
{
	t_vector *vec;

	if (!root || !*root)
		return (NULL);
	vec = (t_vector *)*root;
	while (vec->size > 0 && vec->front <= vec->back)
	{
		if (vec->c_free)
			vec->c_free(vec->mem[vec->front], size, obj);
		else
			free(vec->mem[vec->front]);
		vec->front++;
	}
	free(vec->mem);
	free(*root);
	*root = NULL;
	return (NULL);
}
