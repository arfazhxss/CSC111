#include <stdio.h>

void add2( int* num_ptr, int* num_ptr1);

int main ( ) {
	int x = 12;
    int y = 3;

	int* ptr = &x;
	add2(ptr, &y); 
    printf("%d\n", x);

	return 0;
}
/* Purpose: adds 2 numbers together pointed to by num_ptr and num_ptr1
 * Parameters: int* num_ptr – address of an int, int* num_ptr1 – address of an int
 */
void add2 (int* num_ptr, int* num_ptr1) {
    
    *num_ptr = *num_ptr + *num_ptr1;

}

