#include <stdio.h>

int count_above (int data[], int sz, int threshold);

int main( void ) {
    int data_empty[0] = {};
    int data_10[10] = {-5, -7, 3, 1, 0, 23, -14, 35, 12, 16 };
    printf("Returned: %d\n", count_above(data_10, 10, 3));
    printf("Returned: %d\n", count_above(data_empty, 0, 5));
    return 0;
}
           
/*
 * Purpose:  counts and returns the number of values in data with sz elements
 *     that are above threshold
 * Params: int data[]
 *         int sz – number of elements in data
 *         int threshold – values should be above threshold if counted
 * Returns: int – the count 
 */
           
int count_above (int data[], int sz, int threshold) {
    int count = 0;
    if(sz >0){
        for(int i=0; i<sz;i++){
            if(data[i]>threshold){
                count++;
            }
        }
    }
    return count;
}
