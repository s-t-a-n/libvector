/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_internal.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/06 17:21:47 by sverschu      #+#    #+#                 */
/*   Updated: 2020/08/06 20:08:08 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_INTERNAL_H
# define VECTOR_INTERNAL_H

#include <stdlib.h>

#include "vector.h"

typedef struct	s_vector
{
   size_t		cap;
   size_t		size;
   size_t		front;
   size_t		back;
   void			**mem;
   void			(*c_free)(void *ptr, size_t size, void *obj);
   void			(*c_clone)(void *dst, void *src, size_t size);
}				t_vector;

typedef void	*(*t_jumpfunc)(void **root, t_sizes size, void *obj);
t_jumpfunc		dispatch(t_ops op);

void			*vec_create(void **root, t_sizes size, void *obj);
void			*vec_destroy(void **root, t_sizes size, void *obj);
void			*vec_clone(void **root, t_sizes size, void *obj);
void			*vec_pushfront(void **root, t_sizes size, void *obj);
void			*vec_pushback(void **root, t_sizes size, void *obj);
void			*vec_pushat(void **root, t_sizes size, void *obj);
void			*vec_peekfront(void **root, t_sizes size, void *obj);
void			*vec_peekback(void **root, t_sizes size, void *obj);
void			*vec_peekat(void **root, t_sizes size, void *obj);
void			*vec_popfront(void **root, t_sizes size, void *obj);
void			*vec_popback(void **root, t_sizes size, void *obj);
void			*vec_popat(void **root, t_sizes size, void *obj);
void			*vec_size(void **root, t_sizes size, void *obj);

/*
** LIBC functions which may not be used in 42-curriculum
** To use LIBC functions, run in 'src' folder:
** find . -type f -print0 | xargs -0 sed -i 's/ ft_/ /g'
*/

void			*ft_calloc(size_t count, size_t size);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
#endif
