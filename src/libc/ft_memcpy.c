/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/19 21:57:35 by sverschu      #+#    #+#                 */
/*   Updated: 2020/06/19 21:58:30 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst_, const void *src_, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*src = src_;
	const void			*orig_dst = dst_;

	dst = dst_;
	if (dst == src)
		return ((void *)orig_dst);
	while (n > 0)
	{
		*dst = *src;
		n--;
		dst++;
		src++;
	}
	return ((void *)orig_dst);
}
