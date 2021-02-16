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
	char	*str = (char *)"Vector life.";
	size_t	size = 1;

	CHECK(vector(&root, V_CREATE, size, NULL));
	CHECK(vector(&root, V_PUSHBACK, 0, str));
	printf("%s\n", (char *)vector(&root, V_PEEKBACK, 0, NULL));
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
		char *str = (char *)calloc(1024, 1);
		CHECK(vector(&root, V_PUSHBACK, 0, str));
	}

	char *cmpstr = (char *)calloc(1024, 1);
	for (unsigned int i = 0; i < run_size; i++)
	{
		char *str = (char *)vector(&root, V_PEEKBACK, 0, NULL);
		CHECK(str);
		CHECK(memcmp(str, cmpstr, 1024) == 0);
		free(str);
		CHECK(vector(&root, V_POPBACK, 0, NULL) == NULL);
	}
	free(cmpstr);
	CHECK(*(size_t *)vector(&root, V_SIZE, 0, NULL) == 0);
	CHECK(vector(&root, V_DESTROY, 0, NULL) == NULL);
}

TEST_CASE( "clear_realloced", "[vector]" ) {
	void	*root;
	size_t	size = 1;
	size_t	run_size = 50;

	CHECK(vector(&root, V_CREATE, size, NULL));
	for (unsigned int i = 0; i < run_size; i++)
	{
		char *str = (char *)calloc(1024, 1);
		CHECK(vector(&root, V_PUSHBACK, 0, str));
	}

	CHECK(*(size_t *)vector(&root, V_SIZE, 0, NULL) == run_size);
	CHECK(vector(&root, V_CLEAR, true, NULL));
	CHECK(*(size_t *)vector(&root, V_SIZE, 0, NULL) == 0);
	for (unsigned int i = 0; i < run_size; i++)
	{
		char *str = (char *)calloc(1024, 1);
		CHECK(vector(&root, V_PUSHBACK, 0, str));
	}
	CHECK(*(size_t *)vector(&root, V_SIZE, 0, NULL) == run_size);
	CHECK(vector(&root, V_DESTROY, true, NULL) == NULL);
}

TEST_CASE( "clear_oversized", "[vector]" ) {
	void	*root;
	size_t	size = 100;
	size_t	run_size = 50;

	CHECK(vector(&root, V_CREATE, size, NULL));
	for (unsigned int i = 0; i < run_size; i++)
	{
		char *str = (char *)calloc(1024, 1);
		CHECK(vector(&root, V_PUSHBACK, 0, str));
	}

	CHECK(*(size_t *)vector(&root, V_SIZE, 0, NULL) == run_size);
	CHECK(vector(&root, V_CLEAR, true, NULL));
	CHECK(*(size_t *)vector(&root, V_SIZE, 0, NULL) == 0);
	for (unsigned int i = 0; i < run_size; i++)
	{
		char *str = (char *)calloc(1024, 1);
		CHECK(vector(&root, V_PUSHBACK, 0, str));
	}
	CHECK(*(size_t *)vector(&root, V_SIZE, 0, NULL) == run_size);
	CHECK(vector(&root, V_DESTROY, true, NULL) == NULL);
}
