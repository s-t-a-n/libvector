#include <catch2/catch.hpp>

extern "C" {
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

#include "vector.h"
}

TEST_CASE( "create_destroy", "[vector]" ) {
	void *root;

	size_t count = 8;
	CHECK(vector(&root, V_CREATE, count, NULL));

	CHECK(vector(&root, V_DESTROY, 0, NULL) == NULL);
}

TEST_CASE( "push_pop", "[vector]" ) {
	void	*root;
	char	*str = "Vector life.";
	size_t	size = 1;

	CHECK(vector(&root, V_CREATE, size, NULL));
	CHECK(vector(&root, V_PUSHBACK, 0, str));
	printf("%s\n", vector(&root, V_PEEKBACK, 0, NULL));
	CHECK(memcmp(vector(&root, V_PEEKBACK, 0, NULL), str, strlen(str)) == 0);
	CHECK(vector(&root, V_POPBACK, 0, NULL) == NULL);
	CHECK(*(size_t *)vector(&root, V_SIZE, 0, NULL) == 0);

	CHECK(vector(&root, V_DESTROY, 0, NULL) == NULL);
}

TEST_CASE( "push_realloc", "[vector]" ) {
	void	*root;
	size_t	size = 1;
	size_t	run_size = 50;

	CHECK(vector(&root, V_CREATE, size, NULL));
	for (unsigned int i = 0; i < run_size; i++)
	{
		char *str = calloc(1024, 1);
		CHECK(vector(&root, V_PUSHBACK, 0, str));
	}

	char *cmpstr = calloc(1024, 1);
	for (unsigned int i = 0; i < run_size; i++)
	{
		char *str = vector(&root, V_PEEKBACK, 0, NULL);
		CHECK(str);
		CHECK(memcmp(str, cmpstr, 1024) == 0);
		free(str);
		CHECK(vector(&root, V_POPBACK, 0, NULL) == NULL);
	}
	free(cmpstr);
	CHECK(*(size_t *)vector(&root, V_SIZE, 0, NULL) == 0);
	CHECK(vector(&root, V_DESTROY, 0, NULL) == NULL);
}
