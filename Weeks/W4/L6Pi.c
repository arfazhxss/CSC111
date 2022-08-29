#include <stdio.h>

int main( void ) {
   /*
    * We will create 2 variables sum, d (denominator)
    * Initialize sum = 0, Initialize d = 1
    * Create a loop
    *   Loop to 1000000 ( bigger number = more precision )
    *   Check if loop index is even then sum=sum+4/d, else sum=sum-4/d
    *   Increment d by 2 every at every iteration
    * Print sum
*/
    
    double sum = 0;
    double d = 1;
    
    for(int counter =0; counter<100000000; counter++){
        if(counter%2 == 0){
            sum = sum +4/d;
        }else{
            sum = sum - 4/d;
        }
        
        d = d+2;
        
    }
    
    printf("Pi is: %f\n", sum);

}
