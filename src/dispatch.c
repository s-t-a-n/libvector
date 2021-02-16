/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dispatch.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/06 17:26:24 by sverschu      #+#    #+#                 */
/*   Updated: 2020/08/06 18:13:53 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_internal.h"

t_jumpfunc		dispatch(t_ops op)
{
	static const t_jumpfunc jtable[E_OPS_END - E_OPS_BEGIN] = {
		[V_CREATE] = &vec_create,
		[V_DESTROY] = &vec_destroy,
		[V_CLEAR] = &vec_clear,
		[V_CLONE] = &vec_clone,
		[V_PUSHFRONT] = &vec_pushfront,
		[V_PUSHBACK] = &vec_pushback,
		[V_PUSHAT] = &vec_pushat,
		[V_PEEKFRONT] = &vec_peekfront,
		[V_PEEKBACK] = &vec_peekback,
		[V_PEEKAT] = &vec_peekat,
		[V_POPFRONT] = &vec_popfront,
		[V_POPBACK] = &vec_popback,
		[V_POPAT] = &vec_popat,
		[V_SIZE] = &vec_size
	};

	return ((op > E_OPS_BEGIN && op < E_OPS_END) ? jtable[op] : NULL);
}
