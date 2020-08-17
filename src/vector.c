/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/06 17:10:53 by sverschu      #+#    #+#                 */
/*   Updated: 2020/08/07 16:22:04 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

#ifdef DEBUG

# include <assert.h>

void		*vector(void **root, t_ops op, size_t n, void *obj)
{
	assert(dispatch(op) != NULL);
	return (dispatch(op)(root, n, obj));
}

#else

void		*vector(void **root, t_ops op, size_t n, void *obj)
{
	return (dispatch(op)(root, n, obj));
}

#endif
