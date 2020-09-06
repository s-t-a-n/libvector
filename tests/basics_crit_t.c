/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   basics_crit_t.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/07 17:00:48 by sverschu      #+#    #+#                 */
/*   Updated: 2020/09/06 16:13:38 by sverschu      ########   odam.nl         */
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
	cr_assert(vector(&root, V_CREATE, count, NULL));

	cr_assert(vector(&root, V_DESTROY, 0, NULL) == NULL);
}

Test(generic, push_pop)
{
	void	*root;
	char	*str = "Vector life.";
	size_t	size = 1;

	cr_assert(vector(&root, V_CREATE, size, NULL));
	cr_assert(vector(&root, V_PUSHBACK, 0, str));
	printf("%s\n", vector(&root, V_PEEKBACK, 0, NULL));
	cr_assert(memcmp(vector(&root, V_PEEKBACK, 0, NULL), str, strlen(str)) == 0);
	cr_assert(vector(&root, V_POPBACK, 0, NULL) == NULL);
	cr_assert(*(size_t *)vector(&root, V_SIZE, 0, NULL) == 0);

	cr_assert(vector(&root, V_DESTROY, 0, NULL) == NULL);
}

Test(generic, push_realloc)
{
	void	*root;
	size_t	size = 1;
	size_t	run_size = 50;

	cr_assert(vector(&root, V_CREATE, size, NULL));
	for (unsigned int i = 0; i < run_size; i++)
	{
		char *str = calloc(1024, 1);
		cr_assert(vector(&root, V_PUSHBACK, 0, str));
	}

	char *cmpstr = calloc(1024, 1);
	for (unsigned int i = 0; i < run_size; i++)
	{
		char *str = vector(&root, V_PEEKBACK, 0, NULL);
		cr_assert(str);
		cr_assert(memcmp(str, cmpstr, 1024) == 0);
		free(str);
		cr_assert(vector(&root, V_POPBACK, 0, NULL) == NULL);
	}
	free(cmpstr);
	cr_assert(*(size_t *)vector(&root, V_SIZE, 0, NULL) == 0);
	cr_assert(vector(&root, V_DESTROY, 0, NULL) == NULL);
}
