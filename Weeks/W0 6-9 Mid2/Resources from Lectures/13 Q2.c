#include <stdio.h>
#include <string.h>

void sum_matrices(int row, int col, int a[row][col], int b[row][col], int c[row][col]);

int main(){
    
    int a[2][2] = {{2, -3},
                  {-7, 5}};
    
    int b[2][2] = {{1, 4},
                  {0, 2}};
    
    int c[2][2] ={{0},{0}};
    
    sum_matrices(2,2, a, b, c);
    memset(c,0,row*sizeof(c[0]));

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

}

void sum_matrices(int row, int col, int a[row][col], int b[row][col], int c[row][col]){
    
    //iterate through the rows of a, b and c
        //iterate throught the individual values
            //assign c[i][j] = a[i][j] + b[i][j];
    
    
    for(int r=0; r<row; r++){
        for(int j=0; j<col; j++){
            c[r][j] = a[r][j] + b[r][j];
        }
    }

}