/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/06 17:14:23 by sverschu      #+#    #+#                 */
/*   Updated: 2020/08/07 16:23:23 by sverschu      ########   odam.nl         */
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

# ifndef S_C1_STRUCT
#  define S_C1_STRUCT	NULL
# endif

# ifndef S_C2_STRUCT
#  define S_C2_STRUCT	NULL
# endif

# ifndef S_C3_STRUCT
#  define S_C3_STRUCT	NULL
# endif

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

/*
typedef enum	e_sizes
{
	S_CHAR = sizeof(char),
	S_SHORT = sizeof(short),
	S_INT = sizeof(int),
	S_LONG = sizeof(long),
	S_SIZET = sizeof(size_t),
	S_DOUBLE = sizeof(double),
	S_PTR = sizeof(void *),
	S_C1 = sizeof(S_C1_STRUCT),
	S_C2 = sizeof(S_C2_STRUCT),
	S_C3 = sizeof(S_C3_STRUCT),
}				t_sizes;
*/

void	*vector(void **root, t_ops op, size_t n, void *obj);

#endif
