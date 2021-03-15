/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_internal.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/06 17:21:47 by sverschu      #+#    #+#                 */
/*   Updated: 2020/09/06 16:03:55 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_INTERNAL_H
# define VECTOR_INTERNAL_H

# include <stdlib.h>

# include "vector.h"

#define TRUE	1
#define FALSE	0

typedef struct	s_vector
{
	size_t		cap;
	size_t		size;
	size_t		front;
	size_t		back;
	void		**mem;
}				t_vector;

typedef void	*(*t_jumpfunc)(void **root, size_t n, void *obj);
t_jumpfunc		dispatch(t_ops op);

void			*vec_create(void **root, size_t n, void *obj);
void			*vec_adopt(void **root, size_t n, void *obj);
void			*vec_abandon(void **root, size_t n, void *obj);
void			*vec_resize(void **root, size_t n, void *obj);
void			*vec_destroy(void **root, size_t is_malloced, void *obj);
void			*vec_clear(void **root, size_t is_malloced, void *obj);
void			*vec_clone(void **root, size_t n, void *obj);
void			*vec_pushfront(void **root, size_t n, void *obj);
void			*vec_pushback(void **root, size_t n, void *obj);
void			*vec_pushat(void **root, size_t n, void *obj);
void			*vec_peekfront(void **root, size_t n, void *obj);
void			*vec_peekback(void **root, size_t n, void *obj);
void			*vec_peekat(void **root, size_t n, void *obj);
void			*vec_popfront(void **root, size_t n, void *obj);
void			*vec_popback(void **root, size_t n, void *obj);
void			*vec_popat(void **root, size_t n, void *obj);
void			*vec_find_nth(void **root, size_t n, void *obj);
void			*vec_find_nth_rev(void **root, size_t n, void *obj);
void			*vec_size(void **root, size_t n, void *obj);

void			*reallocate(t_vector *vec, size_t cap, size_t new_cap);

/*
** LIBC functions which may not be used in 42-curriculum
** To use LIBC functions, run in 'src' folder:
** find . -type f -print0 | xargs -0 sed -i 's/ ft_/ /g'
*/

void			*ft_calloc(size_t count, size_t size);
void			*ft_realloc(void *ptr, size_t size, size_t new_size);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
#endif
