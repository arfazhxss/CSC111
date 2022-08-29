//I have introduced some of the erros we dealt with yesterday in this file - if you want extra practice for the debugging skills we discussed. I also introduced some other erros...  

#include <stdio.h>
int get_max_min();

int main( void ) {
    int min=0 , max=0;
    int c = get_max_min();
    printf("Min: %d, Max: %d, count: %d\n", min, max, c);
    return 0;
}

/*
 * Purpose: Gets values that are entered by the user. -1 to stop entering values (this value should not be saved or counted)
 * Parameters: pointer to store the max; pointer to store the min value
 * Returns the total number of numbers entered.
*/

int get_max_min(int* max, int* min){

    int scanned;
    int n_val = 0;
    int count = 0;

    printf("Please enter a positive integer or -1 to exit\n");
    scanned = scanf("%d", &n_val);
    count++;
    *max = n_val;
    *min = n_val;
    

    while(scanned == 1 || n_val !=-1){

        //printf("Curr min: %d curr max: %d\n", *min, *max);
        printf("Please enter a positive integer or -1 to exit\n");
        scanned = scanf("%d", &n_val);
        
        if(*min>n_val){
            *min = n_val;
        }else if(*max>n_val){
            *max = n_val;
        }
        count++;
        
    }
    
    return count;
}