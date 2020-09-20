/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/06 17:14:23 by sverschu      #+#    #+#                 */
/*   Updated: 2020/09/20 00:02:15 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** inspired upon:
** stackoverflow.com/questions/3456446/a-good-c-equivalent-of-stl-vector
*/

#ifndef VECTOR_H
# define VECTOR_H

# include <sys/types.h>
# include <stddef.h>

typedef enum	e_ops
{
	E_OPS_BEGIN,
	V_CREATE,
	V_DESTROY,
	V_CLONE,
	V_PUSHFRONT,
	V_PUSHBACK,
	V_PUSHAT,
	V_PEEKFRONT,
	V_PEEKBACK,
	V_PEEKAT,
	V_POPFRONT,
	V_POPBACK,
	V_POPAT,
	V_SIZE,
	E_OPS_END
}				t_ops;

void	*vector(void **root, t_ops op, size_t n, void *obj);

#endif
