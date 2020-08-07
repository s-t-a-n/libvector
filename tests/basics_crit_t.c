/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   basics_crit_t.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/07 17:00:48 by sverschu      #+#    #+#                 */
/*   Updated: 2020/08/07 17:14:25 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/logging.h>

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

#include "vector.h"

Test(generic, create_destroy)
{
	void *root;

	size_t count = 8;
	cr_assert(vector(&root, V_CREATE, S_PTR, (void *)&count));

	cr_assert(vector(&root, V_DESTROY, S_PTR, (void *)&count) == NULL);
}

Test(generic, push_pop)
{
	void *root;
	char *t_str = "Vector life.";
	size_t count = 1;

	cr_assert(vector(&root, V_CREATE, S_PTR, (void *)&count));
	cr_assert(vector(&root, V_PUSHBACK, S_PTR, t_str));
	printf("%s\n", vector(&root, V_PEEKBACK, S_PTR, NULL));
	cr_assert(memcmp(vector(&root, V_PEEKBACK, S_PTR, NULL), t_str, strlen(t_str)) == 0);
	//cr_assert(vector(&root, V_POPBACK, S_PTR, NULL) == NULL);
	//cr_assert(*(size_t *)vector(&root, V_SIZE, S_PTR, NULL) == 0);

	cr_assert(vector(&root, V_DESTROY, S_PTR, (void *)&count) == NULL);
}
