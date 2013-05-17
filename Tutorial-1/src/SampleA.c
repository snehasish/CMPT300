#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MyStruct
{
	/* Long Integer */
	long int				a,b;
	/* Character Array */
	char 			   name[10];
	/* 	Integer Bitfield 
		For a description of bitfields and where they are useful check:
		[Wikipedia](http://en.wikipedia.org/wiki/Bit_field)
		propertyA can only take values 0,1 - i.e it is composed of 1 bit
		propertyB can take values from 0,2^(n)-1 where n = 3 - i.e it is composed of 3 bits
	*/
	unsigned int propertyA 	: 1; 
	unsigned int propertyB 	: 3;
	/* Pad upto 8 bits */
	unsigned int 			: 4;
};


int main(int argc, char const *argv[])
{
	/* Integer variable and integer pointer */ 
	int x, *ptrX = NULL;

	/* Set the pointer to point to x */

	ptrX = &x;

	/* Set data by dereferencing x */

	*ptrX = 25;

	/* Print out the value of x */

	printf("Print using variable: %d\n", x);
	printf("Print using pointer:  %d\n", *ptrX);

	/* Declare a pointer to MyStruct */
	struct MyStruct *ptr = NULL;

	/* Allocate memory for a couple of structures -- Remember to free */

	ptr = (struct MyStruct*)malloc(sizeof(struct MyStruct)*2);

	/* Initialize the memory to zero so that we don't pick up any garbage values */

	memset(ptr, 0, sizeof(struct MyStruct)*2);

	/* Fill some data into the stucts */

	/* 	Equivalent to (*(ptr + 0)).a = 721; 
		Read [Pointer Arithmetic](http://www.cs.umd.edu/class/sum2003/cmsc311/Notes/BitOp/pointer.html)
		In depth pointer tutorial - [Link](http://home.earthlink.net/~momotuk/pointers.pdf)
	*/
    ptr[0].a        = 721;
    (*(ptr + 1)).a  = 234;

    /* Bit field set */

    ptr[0].propertyA = 0;
	ptr[0].propertyB = 2;

    /* 	This truncates the value and gives a warning - Be careful */

    ptr[1].propertyA = 3;

    /* Print out structure data */

    printf("Structure data\n \
    		ptr->a: %lu\n \
    		ptr[1].a: %lu\n \
    		ptr[0].propertyA: %u\n \
    		ptr[1].propertyA: %u\n", ptr->a, ptr[1].a, ptr[0].propertyA, ptr[1].propertyA );

	/* Free allocated memory */

	free(ptr);

	return 0;
}