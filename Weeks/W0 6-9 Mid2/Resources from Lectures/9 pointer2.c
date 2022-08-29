#include <stdio.h>

void add1( int* num_ptr);

int main ( ) {
    
    int a = 7;
    int* b = &a;
    int** c = &b;
    
    **c = a + *b;

    printf("%d\n", **c);
    a = 25;
    printf("%d\n", **c);
    *b = 22;
    printf("%d\n", **c);
    
    return 0;
}