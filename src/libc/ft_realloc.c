/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/07 14:52:23 by sverschu      #+#    #+#                 */
/*   Updated: 2020/08/07 15:11:14 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "vector_internal.h"

void	*ft_realloc(void *ptr, size_t size, size_t new_size)
{
	void *nptr;

	if (!ptr)
		return (malloc(new_size));
	else if (ptr && new_size == 0)
	{
		free(ptr);
		return (malloc(1));
	}
	else
	{
		nptr = malloc(new_size);
		if (nptr)
		{
			ft_memcpy(nptr, ptr, size);
			free(ptr);
		}
		return (nptr);
	}
}
