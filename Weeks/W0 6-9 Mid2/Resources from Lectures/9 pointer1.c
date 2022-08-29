#include <stdio.h>

void add1( int* num_ptr);

int main ( ) {
	int x = 12;

	int* ptr = &x;
	add1(ptr); 
	add1(&x); 
    printf("%d\n", x);

	return 0;
}
/* Purpose: adds 1 to number pointed to by num_ptr
 * Parameters: int* num_ptr – address of an int
 */
void add1 ( int* num_ptr) {
	*num_ptr = *num_ptr + 1; 
}
