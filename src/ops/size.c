/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   size.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/07 14:48:00 by sverschu      #+#    #+#                 */
/*   Updated: 2020/08/07 16:21:06 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

void			*vec_size(void **root, size_t n, void *obj)
{
	t_vector *vec;

	vec = (t_vector *)*root;
	return (&vec->size);
	(void)obj;
	(void)n;
}
