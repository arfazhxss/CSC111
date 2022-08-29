#include <stdio.h>

int square(int n);

/*
 * Program to comput the sum of all the squares passed to it
*/

int main(){

    int result = square(4);
    
    printf("Sum of squares is: %d\n", result);
}

int square(int n){
    int result = 0;
    
    int tracker = 1;
    
    while(tracker < n){
        result = result + (tracker * tracker);
        
        //increase loop counter
        tracker = tracker +1;
    }

    return result;

}