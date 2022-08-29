#include <stdio.h>
void mystery(int row, int col, int ar[row][col] );

int main(){
    static int row=2;
    static int col=4;
    int a[2][4] = {{10, 20, 30, 40},{60, 70, 80, 90}};

    mystery(row, col, a);
    
}
void mystery(int row, int col, int ar[row][col] ) {
    int sum =0; 
    int total=0;
    for(int i=0; i<row; i++){
        for(int j=col-1; j>=0; j--){
            printf("%d ", ar[i][j]);
            if(j%2 ==1){
                sum = sum + ar[i][j];
            }
        }
        total = total+sum;
        printf("Row sum is: %d\n", sum);
        sum = 0;  
    }
    printf("Total Sum is: %d\n", total);
} 