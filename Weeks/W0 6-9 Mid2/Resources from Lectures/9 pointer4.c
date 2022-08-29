#include <stdio.h>
void swap(int x, int y);
void swap_ptrs(int* x, int* y);
   
int main( void ) {
    int a = 10;
    int b = 20;
    
    printf("before swap – a: %d, b: %d\n", a, b);
    swap(a, b);
    
    printf("after swap – a: %d, b: %d\n", a, b);
    printf("before swap_ptrs – a: %d, b: %d\n", a, b); 
    
    swap_ptrs(&a, &b);
    printf("after swap_ptrs – a: %d, b: %d\n", a, b); 
    return 0;
}

void swap(int x, int y) {
    int tmp = x;
    x = y;
    y = tmp;
    printf("in swap – x: %d, y: %d\n", x, y);
}

void swap_ptrs(int* x, int* y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
    printf("in swap_ptrs – *x: %d, *y: %d\n", *x, *y);
}