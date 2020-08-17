/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   peekback.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/07 15:59:48 by sverschu      #+#    #+#                 */
/*   Updated: 2020/08/07 16:19:27 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

void			*vec_peekback(void **root, size_t n, void *obj)
{
	t_vector	*vec;

	vec = (t_vector *)*root;
	return (vec->size > 0 ? vec->mem[vec->back] : NULL);
	(void)n;
	(void)obj;
}
