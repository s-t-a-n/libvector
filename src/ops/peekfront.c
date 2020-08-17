/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   peekfront.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/07 15:59:32 by sverschu      #+#    #+#                 */
/*   Updated: 2020/08/07 16:19:39 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

void			*vec_peekfront(void **root, size_t n, void *obj)
{
	t_vector *vec;

	vec = (t_vector *)*root;
	return (vec->size > 0 ? vec->mem[vec->front] : NULL);
	(void)n;
	(void)obj;
}
