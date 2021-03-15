#include <catch2/catch.hpp>

extern "C" {
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

#include "vector.h"
}

#define TEST_SIZE	256
static_assert(TEST_SIZE > 1, "test requirement of minimal size");

TEST_CASE( "create_destroy", "[vector]" ) {
	void *root;
	size_t size = 8;

	CHECK(vector(&root, V_CREATE, size, NULL));

	CHECK(vector(&root, V_DESTROY, 0, NULL) == NULL);
}

TEST_CASE( "adopt", "[vector]" )
{
	void	*root;
	char	*str = (char *)"Hello Vector.";
	size_t	max_size = TEST_SIZE;

	for (size_t size = 1; size < max_size; size++)
	{ 
		/* build example string ** array, check if vector can adopt it */
		char **str_array = (char **)calloc(sizeof(char *), size); 
		REQUIRE(str_array);
		CHECK(vector(&root, V_ADOPT, size, str_array));

		/* verify memory locations are actually the same */
		str_array[0] = str;
		CHECK(vector(&root, V_PEEKFRONT, 0, NULL) != NULL);
		CHECK(memcmp(vector(&root, V_PEEKFRONT, 0, NULL), str_array[0], strlen(str) + 1) == 0);
		CHECK(*(size_t *)vector(&root, V_SIZE, 0, NULL) == size);

		/* check if reallocation is working */
		void *test_obj = (void *)1;
		CHECK(vector(&root, V_PUSHBACK, 0, test_obj) != NULL);
		CHECK(vector(&root, V_PUSHFRONT, 0, test_obj) != NULL);
		CHECK(vector(&root, V_PUSHBACK, 0, test_obj) != NULL);
		CHECK(*(size_t *)vector(&root, V_SIZE, 0, NULL) == size + 3);

		CHECK(vector(&root, V_DESTROY, false, NULL) == NULL);
	}
}

TEST_CASE( "abandon", "[vector]" )
{
	void	*root;
	char	*str = (char *)"Hello Vector.";
	size_t	max_size = TEST_SIZE;

	for (size_t size = 1; size < max_size; size++)
	{ 
		/* build example string ** array, check if vector can adopt it */
		char **str_array = (char **)calloc(sizeof(char *), size); 
		REQUIRE(str_array);
		for (size_t i = 0; i < size; i++)
			str_array[i] = str;
		CHECK(vector(&root, V_ADOPT, size, str_array));

		/* retreive backing memory from vector by abandoning the vector */
		char **str_array_abandoned = (char **)vector(&root, V_ABANDON, 0, NULL);
		CHECK(str_array_abandoned == str_array);
		free(str_array_abandoned);
	}
}

TEST_CASE( "resize", "[vector]" )
{
	void			*root;
	const size_t	buflen = 1;
	const size_t	max_size = TEST_SIZE;

	for (size_t size = 2; size < max_size; size++)
	{ 
		REQUIRE(vector(&root, V_CREATE, size, NULL));
		
		for (size_t i = 0; i < size; i++)
			CHECK(vector(&root, V_PUSHBACK, 0, malloc(buflen)));
		CHECK(*(size_t *)vector(&root, V_SIZE, 0, NULL) == size);

		CHECK(vector(&root, V_RESIZE, size / 2, NULL)); 
		CHECK(*(size_t *)vector(&root, V_SIZE, 0, NULL) == size / 2);
		
		CHECK(vector(&root, V_DESTROY, true, NULL) == NULL);
	}
}

TEST_CASE( "clone", "[vector]" )
{
	void			*root;
	size_t			clone_size;
	const size_t	buflen = 1;
	const size_t	max_size = TEST_SIZE;

	for (size_t size = 2; size < max_size; size++)
	{ 
		REQUIRE(vector(&root, V_CREATE, size, NULL));
		
		/* fill vector */	
		for (size_t i = 0; i < size; i++)
			CHECK(vector(&root, V_PUSHBACK, 0, malloc(buflen)));

		CHECK(*(size_t *)vector(&root, V_SIZE, 0, NULL) == size);

		/* test truncated clones */
		void	*root_clone1;
		clone_size = size / 2;
		CHECK(vector(&root, V_CLONE, size / 2, &root_clone1)); 
		CHECK(*(size_t *)vector(&root_clone1, V_SIZE, 0, NULL) == clone_size);
		CHECK(vector(&root_clone1, V_PEEKAT, clone_size - 1, NULL) == vector(&root, V_PEEKAT, clone_size - 1, NULL));
		CHECK(vector(&root_clone1, V_DESTROY, false, NULL) == NULL);

		/* test equal clones */
		void	*root_clone2;
		clone_size = size;
		CHECK(vector(&root, V_CLONE, clone_size, &root_clone2)); 
		CHECK(*(size_t *)vector(&root_clone2, V_SIZE, 0, NULL) == clone_size);
		CHECK(vector(&root_clone2, V_PEEKAT, clone_size - 1, NULL) == vector(&root, V_PEEKAT, clone_size - 1, NULL));
		CHECK(vector(&root_clone2, V_DESTROY, false, NULL) == NULL);

		/* test bigger clones */
		void	*root_clone3;
		clone_size = size * 2;
		CHECK(vector(&root, V_CLONE, clone_size, &root_clone3)); 
		CHECK(*(size_t *)vector(&root_clone3, V_SIZE, 0, NULL) == size);
		CHECK(vector(&root_clone3, V_PEEKAT, size - 1, NULL) == vector(&root, V_PEEKAT, size - 1, NULL));
		CHECK(vector(&root_clone3, V_DESTROY, false, NULL) == NULL);
		
		CHECK(vector(&root, V_DESTROY, true, NULL) == NULL);
	}
}

TEST_CASE( "push_pop", "[vector]" )
{
	void			*root;
	char			*str = (char *)"Hello Human.";
	const size_t	max_size = TEST_SIZE;

	for (size_t size = 1; size < max_size; size++)
	{
		REQUIRE(vector(&root, V_CREATE, size, NULL));

		/* check push back */
		for (size_t i = 0; i < size; i++)
		{
			CHECK(vector(&root, V_PUSHBACK, 0, str));
			CHECK(memcmp(vector(&root, V_PEEKBACK, 0, NULL), str, strlen(str)) == 0);
			if (memcmp(vector(&root, V_PEEKBACK, 0, NULL), str, strlen(str)) != 0)
				printf("push_pop -> in vector: %s, reference: %s \n", (char *)vector(&root, V_PEEKBACK, 0, NULL), str);
		}

		/* check pop back */
		for (size_t i = 0; i < size; i++)
		{
			CHECK(vector(&root, V_POPBACK, 0, NULL) != NULL);
		}

		CHECK(*(size_t *)vector(&root, V_SIZE, 0, NULL) == 0);
		CHECK(vector(&root, V_DESTROY, false, NULL) == NULL);
	}
}

TEST_CASE( "pushfront", "[vector]" )
{
	void	*root;
	char	*str = (char *)"Hello there, father.";
	size_t	max_size = TEST_SIZE;

	for (size_t size = 1; size < max_size; size++)
	{
		REQUIRE(vector(&root, V_CREATE, size, NULL));

		/* fill up vector to size */
		for (size_t i = 0; i < size; i++)
			CHECK(vector(&root, V_PUSHBACK, 0, str));

		/* push elements at the front */
		for (size_t i = 0; i < size; i++)
			CHECK(vector(&root, V_PUSHFRONT, 0, str));

		/* pop out all elements */
		for (size_t i = 0; i < size; i++)
			CHECK(vector(&root, V_POPFRONT, 0, NULL) != NULL);

		CHECK(*(size_t *)vector(&root, V_SIZE, 0, NULL) == size);
		CHECK(vector(&root, V_DESTROY, false, NULL) == NULL);
	}
}

TEST_CASE( "push_realloc", "[vector]" )
{
	void			*root;
	const size_t	buflen = 1024;
	const size_t	max_size = TEST_SIZE;

	for (size_t size = 1; size < max_size; size++)
	{
		REQUIRE(vector(&root, V_CREATE, size, NULL));

		/* fill vector with nullbyte strings */
		for (size_t i = 0; i < size; i++)
			CHECK(vector(&root, V_PUSHBACK, 0, calloc(buflen, 1)));

		/* compare all elements to test for overflows */
		char *cmpstr = (char *)calloc(buflen, 1);
		for (size_t i = 0; i < size; i++)
		{
			char *str = (char *)vector(&root, V_PEEKBACK, 0, NULL);
			CHECK(str);
			CHECK(memcmp(str, cmpstr, buflen) == 0);
			free(str);
			CHECK(vector(&root, V_POPBACK, 0, NULL) != NULL);
		}
		free(cmpstr);

		CHECK(*(size_t *)vector(&root, V_SIZE, 0, NULL) == 0);
		CHECK(vector(&root, V_DESTROY, 0, NULL) == NULL);
	}
}

TEST_CASE( "clear_realloced", "[vector]" )
{
	void			*root;
	const size_t	buflen = 1024;
	const size_t	max_size = TEST_SIZE;

	for (size_t size = 1; size < max_size; size++)
	{
		REQUIRE(vector(&root, V_CREATE, size, NULL));

		/* fill vector with initialized memory ptrs */
		for (size_t i = 0; i < size; i++)
		{
			char *str = (char *)calloc(buflen, 1);
			CHECK(vector(&root, V_PUSHBACK, 0, str));
		}
		CHECK(*(size_t *)vector(&root, V_SIZE, 0, NULL) == size);

		/* clear out vector and free all elements */
		CHECK(vector(&root, V_CLEAR, true, NULL));
		CHECK(*(size_t *)vector(&root, V_SIZE, 0, NULL) == 0);

		/* refill vector with initialized memory ptrs */
		for (size_t i = 0; i < size; i++)
		{
			char *str = (char *)calloc(buflen, 1);
			CHECK(vector(&root, V_PUSHBACK, 0, str));
		}
		CHECK(*(size_t *)vector(&root, V_SIZE, 0, NULL) == size);
		CHECK(vector(&root, V_DESTROY, true, NULL) == NULL);
	}
}

TEST_CASE( "clear_oversized", "[vector]" )
{
	void			*root;
	const size_t	buflen = 1024;
	const size_t	max_size = TEST_SIZE;
	const size_t	half_size = max_size / 2;

	for (size_t size = 1; size < max_size; size++)
	{
		REQUIRE(vector(&root, V_CREATE, size, NULL));

		/* fill half of vector */
		for (size_t i = 0; i < half_size; i++)
		{
			char *str = (char *)calloc(buflen, 1);
			CHECK(vector(&root, V_PUSHBACK, 0, str));
		}
		CHECK(*(size_t *)vector(&root, V_SIZE, 0, NULL) == half_size);

		/* clear out vector and free all elements */
		CHECK(vector(&root, V_CLEAR, true, NULL));
		CHECK(*(size_t *)vector(&root, V_SIZE, 0, NULL) == 0);

		/* refill half of vector */
		for (size_t i = 0; i < half_size; i++)
		{
			char *str = (char *)calloc(buflen, 1);
			CHECK(vector(&root, V_PUSHBACK, 0, str));
		}
		CHECK(*(size_t *)vector(&root, V_SIZE, 0, NULL) == half_size);
		CHECK(vector(&root, V_DESTROY, true, NULL) == NULL);
	}
}

TEST_CASE( "pop_at", "[vector]" )
{
	void			*root;
	const size_t	buflen = 1024;
	const size_t	max_size = TEST_SIZE;
	const size_t	half_size = max_size / 2;
	
	for (size_t size = 1; size < max_size; size++)
	{
		REQUIRE(vector(&root, V_CREATE, size, NULL));

		/* fill half of vector*/
		for (size_t i = 0; i < half_size; i++)
		{
			char *str = (char *)malloc(buflen);
			snprintf(str, buflen, "%zu", i);
			CHECK(vector(&root, V_PUSHBACK, 0, str));
		}
		CHECK(*(size_t *)vector(&root, V_SIZE, 0, NULL) == half_size);

		/* pop half of vector and check contents */
		for (unsigned int i = 0; i < half_size; i++)
		{
			void *obj = vector(&root, V_POPAT, 0, NULL);
			REQUIRE(obj != NULL);

			char buf[buflen];
			snprintf(buf, buflen, "%i", i);
			CHECK(strcmp((char *)obj, buf) == 0);
			if (strcmp((char *)obj, buf) != 0)
				printf("pop_push_at : V_POPAT returned: \"%s\", should be \"%s\"\n", (char *)obj, buf);
			free(obj);
		}

		CHECK(vector(&root, V_DESTROY, true, NULL) == NULL);
	}
}

TEST_CASE( "push_at", "[vector]" )
{
	char			*str;
	void			*root;
	const size_t	max_size = TEST_SIZE;
	const size_t	buflen = 1024;
	char			buf[buflen]; 

	for (size_t size = 1; size < max_size; size++)
	{
		size_t half_size = (size / 2 > 2) ? size / 2 : 3;
		REQUIRE(vector(&root, V_CREATE, size, NULL));

		/* fill half of vector */
		for (size_t i = 0; i < half_size; i++)
		{
			str = (char *)malloc(buflen);
			snprintf(str, buflen, "%zu", i);
			CHECK(vector(&root, V_PUSHBACK, 0, str));
		}
		CHECK(*(size_t *)vector(&root, V_SIZE, 0, NULL) == half_size);

		/* push some saillant number in */
		str = (char *)malloc(buflen); snprintf(str, buflen, "%i", (int)half_size * 2);
		CHECK(vector(&root, V_PUSHAT, 1, str));
		CHECK(*(size_t *)vector(&root, V_SIZE, 0, NULL) == half_size + 1);

		/* check if it was indeed inserted */
		snprintf(buf, buflen, "%i", (int)half_size * 2);
		CHECK(strcmp((char *)vector(&root, V_PEEKAT, 1, NULL), buf) == 0);

		/* check surrounding values */
		snprintf(buf, buflen, "%i", 0);
		CHECK(strcmp((char *)vector(&root, V_PEEKAT, 0, NULL), buf) == 0);
		snprintf(buf, buflen, "%i", 1);
		CHECK(strcmp((char *)vector(&root, V_PEEKAT, 2, NULL), buf) == 0);

		CHECK(vector(&root, V_DESTROY, true, NULL) == NULL);
	}
}

TEST_CASE( "push_at_index==size", "[vector]" ) {
	char			*str;
	void			*root;
	const size_t	buflen = 1024;
	const size_t	max_size = TEST_SIZE;

	for (size_t size = 1; size < max_size; size++)
	{
		REQUIRE(vector(&root, V_CREATE, size, NULL));
		for (size_t i = 0; i < size; i++)
		{
			str = (char *)malloc(buflen);
			snprintf(str, buflen, "%zu", i);
			CHECK(vector(&root, V_PUSHBACK, 0, str));
		}
		CHECK(*(size_t *)vector(&root, V_SIZE, 0, NULL) == size);
		
		/* check pushat begin */
		str = (char *)malloc(buflen);
		CHECK(vector(&root, V_PUSHAT, 0, str));
		CHECK(*(size_t *)vector(&root, V_SIZE, 0, NULL) == ++size);
		
		/* check pushat middle */
		if (size > 1)
		{
			str = (char *)malloc(buflen);
			CHECK(vector(&root, V_PUSHAT, size / 2, str));
			CHECK(*(size_t *)vector(&root, V_SIZE, 0, NULL) == ++size);
		}
		
		/* check pushat end */
		str = (char *)malloc(buflen);
		CHECK(vector(&root, V_PUSHAT, size, str));
		CHECK(*(size_t *)vector(&root, V_SIZE, 0, NULL) == ++size);

		CHECK(vector(&root, V_DESTROY, true, NULL) == NULL);
	}
}

static size_t	static_number;

static int	test_is_static_number(void *obj)
{
	struct tst {
		size_t a;
	};

	tst *t = (tst *)obj;
	return ((t->a == static_number) ? 1 : 0);
}

TEST_CASE( "find_nth", "[vector]" )
{
	/* this test deserves a whole lot more love */
	struct tst {
		size_t a;
	};
	tst				*t;
	void			*root;
	const size_t	max_size = TEST_SIZE;

	for (size_t size = 1; size < max_size; size++)
	{
		REQUIRE(vector(&root, V_CREATE, size, NULL));
		for (size_t i = 0; i < size; i++)
		{
			t = (tst *)malloc(sizeof(struct tst));
			t->a = i;
			CHECK(vector(&root, V_PUSHBACK, 0, t));
		}

		/* check if function passed bool function returns correct item */
		static_number = size / 2;
		tst *t1 = (tst *)vector(&root, V_FIND_NTH, 0, (void *)test_is_static_number);
		REQUIRE(t1 != NULL);
		CHECK(t1->a == static_number);

		/* check that there was indeed no second occasion of the same static_number */
		t = (tst *)vector(&root, V_FIND_NTH, 1, (void *)test_is_static_number);
		CHECK(t == NULL);

		/* check if calling again returns the same pointer */
		t = (tst *)vector(&root, V_FIND_NTH, 0, (void *)test_is_static_number);
		REQUIRE(t != NULL);
		CHECK(t1->a == static_number);
		CHECK(t1 == t);
		
		/*check that when pushing another element of the same type does return properly when asked for*/
		t = (tst *)malloc(sizeof(struct tst));
		t->a = static_number;
		CHECK(vector(&root, V_PUSHBACK, 0, t));

		t = (tst *)vector(&root, V_FIND_NTH, 1, (void *)test_is_static_number);
		REQUIRE(t != NULL);
		CHECK(t->a == static_number);
		CHECK(t != t1);
		
		CHECK(vector(&root, V_DESTROY, true, NULL) == NULL);
	}
}
