#include <stdio.h>


int add1 (int num);

int average(double a, double b, double c);

int main(){
    
    int x = 12;
    x = add1(x);
    
    printf("the result is: %d\n", x);
    

    
}


int add1(int num){

    int result;
    
    result = num + 1;
    
    return result;
    
}

//when done change L6Demo1.c to use return values.