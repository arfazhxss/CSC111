#include <stdio.h>

int get_max(int data[], int sz);

int main( void ) {

    // add test calls to get_max using the following data
    int data1[1] = { 5 };
    int data7[7] = { 5, 3, 12, 34, 2, -17, 6 };
    return 0;
}

/*
 * Purpose:  finds and returns the largest value found in data with sz elements
 * Params: int data[]
 *         int sz – number of elements in data, >0
 * Returns: int – the largest value in data
 */
int get_max (int data[], int sz) {
        if(sz > 0){
        int max_index = 0;
        
        for(int i = 1; i<sz; i++){
            if(data[max_index] < data[i]) max_index = i;
        }
        
        return max_index;
        
    }else{
        return 0;
    }
}