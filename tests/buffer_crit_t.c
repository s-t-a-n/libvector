/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   buffer_crit_t.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/07 13:10:11 by sverschu      #+#    #+#                 */
/*   Updated: 2020/08/07 13:10:15 by sverschu      ########   odam.nl         */
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

	int count = 8;
	cr_assert(vector(&root, V_CREATE, S_INT, (void *)&count));
}
