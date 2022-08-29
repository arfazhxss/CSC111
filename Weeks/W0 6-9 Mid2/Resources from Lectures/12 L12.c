#include <stdio.h>
void copy_non_neg( int data[], int size, int non_neg[]);

int main(){
    int data[7] = { 4, -3, 2, 7, 0, -1, 9 };
    int non_neg[7] = {-1, -1, -1, -1, -1, -1, -1};
    
    copy_non_neg(data, 7, non_neg);
    
    //code to print resulting array
    printf("Result is: [");
    printf("%d", non_neg[0]);
    for(int i=1; i<7; i++){
        printf(" ,%d", non_neg[i]);
    }
    printf("]\n");

}
/*
 * Purpose:  copies values in data to non_neg,replacing all negative values 
 *     with zero.
 * Params: int data[] – the input array, 
 *         int size – the number of elements in data and capacity of non_neg,
 * 	     int non_neg[] – the result array 
 */

void copy_non_neg(int data[], int size, int non_neg[]){   
    //iterate through our arrray for every element:
        //check to see if the value is negative or postive
            //if positive - copy to same index non_neg
            //else copy 0 to same index in non_neg
    int count_of_neg =0;
    for(int i=0; i<size; i++){
        if(data[i] > 0){
            non_neg[i] = data[i];
        }else{
            non_neg[i] = 0;
            count_of_neg++;
        }
    }
    
}