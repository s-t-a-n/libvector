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
	V_ADOPT,
	V_ABANDON,
	V_RESIZE,
	V_DESTROY,
	V_CLEAR,
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
	V_FIND_NTH,
	V_FIND_NTH_REV,
	V_SIZE,
	E_OPS_END
}				t_ops;

void	*vector(void **root, t_ops op, size_t n, void *obj);

/*
** Important:
** - V_FIND_NTH / V_FIND_NTH_REV expect as 'void *obj' a function pointer of
**   the type 'int (*f)(void *obj)' which returns above zero if the object
**   is a match.
**
** - V_DESTROY takes the 'n' argument as boolean whether or not to call free()
**   on it's members. Passing a function pointer as 'void (*f)(void *)' to 'obj'
**   will use that function to free the variables. NULL as 'obj' will use free()
**
** - V_ADOPT takes as 'obj' an array of pointers, takes as 'n', the number
**   of current elements. V_ADOPT will realloc on the first next insertion.
**
** - V_ABANDON destroys itself with the exception of the backing memory store,
**   which it returns.
**
** - V_CLONE takes as 'obj' a void ** to where the vector will be cloned. 
**   it also takes as optional 'n' argument a size of the elements to clone. If
**   bigger than the current vector's size, aditional space  will be allocated.
**   If smaller than the current vector's size, only 'n' elements will be copied
**
** - V_RESIZE takes as 'n' the new size. If smaller than the current size, the
**   objects will be freed by the void (*f)(void *) function pass to 'obj' or
**   by free() if 'obj' is NULL
*/

#endif
