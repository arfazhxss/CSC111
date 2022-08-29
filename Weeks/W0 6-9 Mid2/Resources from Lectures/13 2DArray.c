#include <stdio.h>

int main(){
    
    static int row = 3;
    static int col = 4;
   
    int arr2D [3][4] = {{3,4},
                        {22, 32, 42, 45},
                        {1, 2, 3, 4}};
    
    int sum = 0;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%d ", arr2D[i][j]);
            sum = sum + arr2D[i][j];
        }
        printf("\n");
    }
    printf("The sum of the array is: %d\n", sum);
}