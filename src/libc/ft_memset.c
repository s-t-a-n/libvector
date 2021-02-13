/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/19 21:58:39 by sverschu      #+#    #+#                 */
/*   Updated: 2020/06/19 21:58:41 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b_, int c, size_t len)
{
	unsigned char	*b;
	const void		*b_orig = b_;

	b = b_;
	while (len > 0)
	{
		*b = (unsigned char)c;
		b++;
		len--;
	}
	return ((void *)b_orig);
}
