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
