# Libvector
## A vector library for C.
[![build](https://github.com/s-t-a-n/libvector/workflows/Unittests/badge.svg)](https://github.com/s-t-a-n/libvector/actions?workflow=Unittests)
[![linux](https://github.com/s-t-a-n/libvector/workflows/Linux/badge.svg)](https://github.com/s-t-a-n/libvector/actions?workflow=Linux)
[![macos](https://github.com/s-t-a-n/libvector/workflows/MacOS/badge.svg)](https://github.com/s-t-a-n/libvector/actions?workflow=MacOS)

I wrote this vector library for learning purposes during my studies @ Codam Coding College (42). This library doesn't necessarily follow best practices in terms of architecture, optimization or cleanliness, but it does work very well for the intended purposes. Understand that the 42 network of schools enforce simplicity for the sake of education over best practices. 

void	*vector(void **root, t_ops op, size_t n, void *obj);

See includes/vector.h for further specications of the public facing API.

### Specifications

- all objects in the vector are of 'void *' type. This allows fast (re)allocation and polymorphic access.
- it is guaranteed that all memory in the memory is consecutive, meaning at any point there will be no unitialized memory within the range of active elements
- vector() is state aware -> all calls either return an object or a NULL-ptr

### Compilation

I wrote a Cmake wrapper 'minimake.sh' for the 42-project [minishell](http://github.com/harou24/minishell/). Run it as follows:

    ./minimake.sh

or to compile and run unittests and enable debugging flags:

    ./minimake.sh test

For the ancients (and 42 hehe) a classical Makefile is present:

    make
    make re
    make clean
    make fclean

### Example

Common stack objects:

    void			*root;
    const size_t	vec_default_size = 128;
    
    size_t			index;
    void			*obj;
    
Intialize vector:

    /* handle malloc() failure at your discretion! */
    vector(&root, V_CREATE, vec_default_size, NULL);

Push functions:

    obj = malloc(1024);
    vector(&root, V_PUSHBACK, 0, obj)
    
    obj = malloc(1024);
    vector(&root, V_PUSHFRONT, 0, obj)
    
    obj = malloc(1024);
    index = 0;
    vector(&root, V_PUSHAT, index, obj)
    
Peek functions (returns element):

    void *peekback_obj = vector(&root, V_PEEKBACK, 0, NULL);
    void *peekfront_obj = vector(&root, V_PEEKFRONT, 0, NULL);
    
    index = 0;
    void *peekat_obj = vector(&root, V_PEEKAT, index, NULL);
    
Pop functions (removes element from vector, returns element):

    void *popback_obj = vector(&root, V_POPBACK, 0, NULL);
    void *popfront_obj = vector(&root, V_POPBACK, 0, NULL);
    
    index = 0;
    void *popat_obj = vector(&root, V_POPAT, index, NULL);

Replace function (returns new element):

	void *new_obj = malloc(1024);
	index = 0;
    void *new_obj_returned = vector(&root, V_REPLACE, index, new_obj);
 
Get size of vector:
   
    size_t vec_size = *(size_t *)vector(&root, V_SIZE, 0, NULL);

Resize the vector:

	/* resize vector -> surplus elements will be freed by free() or by custom free() set by V_SETFREEFUNC */
	size_t new_size = 128;
	vector(&root, V_RESIZE, new_size, NULL);

Set custom free() function of vector:

	void (*custom_free)(void*) = free;
    vector(&root, V_SETFREEFUNC, vec_default_size, custom_free);
    
Destroy the vector:
    
    /* 'true' as passed as argument 'n' guarantees memory will be freed (by free() or custom free() set by V_SETFREEFUNC*/
    vector(&root, V_DESTROY, true, NULL);

Find object in vector:

    int my_lookup(void *obj)
    {
    	if (obj == what i want)
    		return (1);
    	return (0);
    }
	void *find_obj = vector(&root, V_FIND_NTH, 0, (void *)my_lookup);
	void *find_rev_obj = vector(&root, V_FIND_NTH_REV, 0, (void *)my_lookup);

	/* to find the second object */
	void *find_obj = vector(&root, V_FIND_NTH, 1, (void *)my_lookup);

Transform a vector:

	int my_transform(void **obj)
	{
		if (some_operation(*obj) == SUCCESS)
			return (1);
		return (0);
	}
	void *obj;
    if ((obj = vector(&root, V_TRANSFORM, 0, (void *) my_transform)) == NULL)
		/* all elements were succesfully transformed */
	else
		/* obj will hold failed object */

Clone vector:

	void *newroot;
    vector(&root, V_CLONE, 0, &newroot);

    /* or if you only want the first 5 elements */
    vector(&root, V_CLONE, 5, &newroot);

Adopt existing memory into vector:

    size_t strbuflen = 128;
    char **strbuf = malloc(sizeof(char **) * strbuflen;
    
    vector(&root, V_ADOPT, 0, (void *)strbuf);
    strbuf = NULL; /* don't be tempted to use this ptr again */

Abandon memory in vector:

    char **strbuf = (char **)vector(&root, V_ABANDON, 0, NULL);

Retreive backing memory in vector:

	size_t starting_index = 0;
    char **strbuf = (char **)vector(&root, V_MEM, starting_index, NULL);

### API specfications

I've tried to follow the STL vector API as much as feasible/possible.

- V_CREATE
- V_ADOPT -> adopt (void **) memory block
- V_ABANDON -> destroy vector, returns (void **) memory block
- V_MEM -> returns (void **) memory block
- V_RESIZE
- V_DESTROY
- V_CLEAR
- V_CLONE
- V_PUSHFRONT
- V_PUSHBACK
- V_PUSHAT
- V_PEEKFRONT
- V_PEEKBACK
- V_PEEKAT
- V_POPFRONT
- V_POPBACK
- V_POPAT
- V_FIND_NTH -> find the nth object in the vector using a lookup lambda
- V_FIND_NTH_REV -> same as V_FIND_NTH, but start from the back
- V_SIZE

### API Notes

- V_FIND_NTH / V_FIND_NTH_REV expect as 'void *obj' a function pointer of
  the type 'int (*f)(void *obj)' which returns above zero if the object
  is a match.

- V_TRANSFORM expect as 'void *obj' a function pointer of                    
  the type 'int (*f)(void **obj)' which will be a ran on all vector elements.
  If f() returns zero, vector() will return the object on which the          
  transformation was attempted.

- V_DESTROY takes the 'n' argument as boolean whether or not to call free()
  on it's members. Passing a function pointer as 'void (*f)(void *)' to 'obj'
  will use that function to free the variables. If NULL is passed as 'obj'
  free() will be used.

- V_ADOPT takes as 'obj' an array of pointers, takes as 'n', the number
  of current elements. V_ADOPT will realloc on the first next insertion.

- V_ABANDON destroys itself with the exception of the backing memory store,
  which it returns.

- V_CLONE takes as 'obj' a void ** to where the vector will be cloned. 
  it also takes as optional 'n' argument a size of the elements to clone. If
  bigger than the current vector's size, aditional space  will be allocated.
  If smaller than the current vector's size, only 'n' elements will be copied

- V_RESIZE takes as 'n' the new size. If smaller than the current size, the
  objects will be freed by the void (*f)(void *) function pass to 'obj' or
  by free() if 'obj' is NULL

### Notes

- using V_FIND_NTH, V_FIND_NTH_REV or V_DESTROY with a (void *) casted function pointer as 'obj' could have undefined consequences since a void ptr is casted to a function pointer, which on some systems do not have the same size. All should work fine on modern x86 systems.

### References

- [Single function API inspiration](https://stackoverflow.com/a/3463498)
