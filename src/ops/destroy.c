/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   destroy.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/06 18:50:42 by sverschu      #+#    #+#                 */
/*   Updated: 2020/09/06 16:05:30 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

void	*vec_destroy(void **root, size_t n, void *obj)
{
	t_vector *vec;

	if (!root || !*root)
		return (NULL);
	vec = (t_vector *)*root;
	free(vec->mem);
	free(*root);
	*root = NULL;
	return (NULL);
	(void)n;
	(void)obj;
}
