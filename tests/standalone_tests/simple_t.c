/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple_t.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sverschu <sverschu@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/07 13:12:12 by sverschu      #+#    #+#                 */
/*   Updated: 2020/08/07 15:25:20 by sverschu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <assert.h>

#include "vector.h"

int	main()
{
	void *root;

	size_t count = 8;
	assert(vector(&root, V_CREATE, S_PTR, (void *)&count));


	assert(vector(&root, V_PUSHBACK, S_PTR, "FAKKA1"));
	assert(vector(&root, V_PUSHBACK, S_PTR, "FAKKA2"));
	assert(vector(&root, V_PUSHBACK, S_PTR, "FAKKA3"));
	assert(vector(&root, V_PUSHBACK, S_PTR, "FAKKA4"));
	//assert(vector(&root, V_PUSHBACK, S_PTR, "FAKKA5"));

	printf("peekback : |%s|\n", (char *)vector(&root, V_PEEKBACK, S_PTR, NULL));
	vector(&root, V_POPBACK, S_PTR, NULL);
	printf("peekback : |%s|\n", (char *)vector(&root, V_PEEKBACK, S_PTR, NULL));
	vector(&root, V_POPBACK, S_PTR, NULL);
	printf("peekback : |%s|\n", (char *)vector(&root, V_PEEKBACK, S_PTR, NULL));
	vector(&root, V_POPBACK, S_PTR, NULL);
	printf("peekback : |%s|\n", (char *)vector(&root, V_PEEKBACK, S_PTR, NULL));
	vector(&root, V_POPBACK, S_PTR, NULL);
	printf("peekback : |%s|\n", (char *)vector(&root, V_PEEKBACK, S_PTR, NULL));

	assert(vector(&root, V_DESTROY, S_PTR, (void *)&count) == NULL);
	assert(root == NULL);

	//system("leaks a.out");
}
