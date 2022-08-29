#include <stdio.h>


//This demonstrates that a while loop and a for loop can produce the same output. 
//what happens if you change < to <=?

int main(){
    
    int index = 0;
    
    while(index <=10){
        printf("Index is: %d\n", index);
        index++;
    }
    
    for(int i =0; i<10; i++){
        printf("I is is: %d\n", i);
    
    }
    

}

