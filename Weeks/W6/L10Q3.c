#include <stdio.h>
void stats(int* smallest, int* largest);


int main( void ) {
    int min, max;
    stats(&min, &max);
    printf("smallest: %d, largest: %d\n", min, max);
    return 0; 
}

/*
 * Purpose: collects numbers from standard input until -1 is entered,
 *   and tracks the smallest and largest numbers entered.
 *  Prints an message if no positive values entered.
 *  The function assumes user is only entering valid integers >= -1.
 * Parameters: int* smallest - pointer to the smallest number entered
 *             int* largest - pointer to the largest number entered
 */

//NOTE The function assumes user is only entering valid integers >= -1.

void stats(int* smallest, int* largest) {
    int next_val, min, max;

    printf("enter an integer, -1 to stop\n");
    scanf("%d", &next_val);
  
    min = next_val;
    max = next_val;

    while(next_val != -1) {
        if (next_val<min)
            min = next_val;
        else if (next_val>max)
            max = next_val;
    
        printf("enter an integer, -1 to stop\n");
        scanf("%d", &next_val);
    }

    if(max == -1)
        printf("Error - no positive numbers entered\n");
        
    *smallest = min;
    *largest  = max;
}
