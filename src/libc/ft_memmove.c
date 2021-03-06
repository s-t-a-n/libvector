/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/19 21:58:34 by sverschu      #+#    #+#                 */
/*   Updated: 2020/06/19 21:58:36 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

static void	*ft_memcpy_rev(void *dst_, const void *src_, size_t len)
{
	unsigned char		*dst;
	const unsigned char	*src = src_;
	const void			*orig_dst = dst_;

	dst = dst_;
	dst += len - 1;
	src += len - 1;
	while (len > 0)
	{
		*(unsigned char *)dst = *(unsigned char *)src;
		dst--;
		src--;
		len--;
	}
	return ((void *)orig_dst);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	if (len == 0 || dst == src)
		return (dst);
	else if (src > dst)
		return (ft_memcpy(dst, src, len));
	else
		return (ft_memcpy_rev(dst, src, len));
}
