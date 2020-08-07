/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   resize.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/07 14:49:11 by sverschu      #+#    #+#                 */
/*   Updated: 2020/08/07 16:22:20 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

void	*resize(t_vector *vec, size_t cap, size_t new_cap)
{
	void	*nmem;

	nmem = ft_realloc(vec->mem, sizeof(void *) * cap, sizeof(void *) * new_cap);
	if (nmem)
	{
		vec->mem = nmem;
		vec->cap = new_cap;
	}
	return (nmem);
}
