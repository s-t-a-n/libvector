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

static int	number;

static int	test_is_number(void *obj)
{
	struct tst {
		int a;
	};

	tst *t = (tst *)obj;
	return ((t->a == number) ? t->a : 0);
}

TEST_CASE( "find_nth", "[vector]" ) {
	/* this test deserves a whole lot more love */
	struct tst {
		int a;
	};
	tst		*t;
	void	*root;
	size_t	size = 100;
	size_t	run_size = 100;

	
	CHECK(vector(&root, V_CREATE, size, NULL));
	for (unsigned int i = 0; i < run_size; i++)
	{
		t = (tst *)malloc(sizeof(struct tst));
		t->a = i;
		CHECK(vector(&root, V_PUSHBACK, 0, t));
	}

	/* check if function passed bool function returns correct item */
	number = 5;
	tst *t1 = (tst *)vector(&root, V_FIND_NTH, 0, (void *)test_is_number);
	REQUIRE(t1 != NULL);
	CHECK(t1->a == number);

	/* check that there was indeed no second occasion of the same number */
	t = (tst *)vector(&root, V_FIND_NTH, 1, (void *)test_is_number);
	CHECK(t == NULL);

	/* check if calling again returns the same pointer */
	t = (tst *)vector(&root, V_FIND_NTH, 0, (void *)test_is_number);
	REQUIRE(t != NULL);
	CHECK(t1->a == number);
	CHECK(t1 == t);
	
	/*check that when pushing another element of the same type does return properly when asked for*/
	t = (tst *)malloc(sizeof(struct tst));
	t->a = number;
	CHECK(vector(&root, V_PUSHBACK, 0, t));

	t = (tst *)vector(&root, V_FIND_NTH, 1, (void *)test_is_number);
	REQUIRE(t != NULL);
	CHECK(t->a == number);
	CHECK(t != t1);
	
	CHECK(vector(&root, V_DESTROY, true, NULL) == NULL);
}
