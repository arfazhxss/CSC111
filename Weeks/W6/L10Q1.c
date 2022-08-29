#include <stdio.h>
int main( void ) {
    double a = 0;
    double b = 0;
    int ret_val;
    
    printf("enter two numbers separated by a space: ");
    ret_val = scanf("%lf %lf", &a, &b);
    
    printf("a: %.1f, b: %.1f, returned value: %d\n", a, b, ret_val);
    
    return 0;
}
//Try the following values - are the results as you expect?
// 5 7 
// 5.4 7.25
//abc 5.7
//abc efg
//3.8 82ef