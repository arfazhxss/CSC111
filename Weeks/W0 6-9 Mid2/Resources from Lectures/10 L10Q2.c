#include <stdio.h>
int count_odd_positive();

int main( void ) {
    int num_odd_pos = count_odd_positive(); printf("%d\n", num_odd_pos);
    return 0;
}


int count_odd_positive() {
    int scanned, next_val, count = 0;
    printf("enter an integer, -1 to stop\n"); 
    scanned = scanf("%d", &next_val);
    
    while(scanned == 1 && next_val != -1) { 
        if(next_val>0 && next_val%2 ==1){
            count++;
        }
        //Check to see if the number is odd and positive
            //add one to count
        //prompt for new number (integer) or -1 to stop
        printf("enter an integer, -1 to stop\n");
        scanned = scanf("%d", &next_val);
        
    }
    //error messaage printed if an invalid value is entered
    
    if(scanned == 0 || next_val==-1){
        printf("Done entering values\n");
    }
    
    return count;
}