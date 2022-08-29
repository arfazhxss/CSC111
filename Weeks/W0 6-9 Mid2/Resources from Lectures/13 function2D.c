#include <stdio.h>
void print_table(int num_rows, int num_cols, int table[num_rows][num_cols]);

void print_table_ptrs(int* table[], int num_rows, int num_cols);

int main(){
    
    int a[3] = {0,9,8};
    int b[3] = {7,6,5};
    
    int* ab[2] = {a, b};
    
    ab [1][1] = 5;

    print_table_ptrs(ab, 2,3);
    
    int bc [2][3] = {{1,2,3}, {4,5,6}};
    print_table(2, 3, bc);


}
//2D ARRAY
void print_table(int num_rows, int num_cols, int table[num_rows][num_cols]) {
    int row, col;
    for(row=0; row<num_rows; row++) { 
        for(col=0; col<num_cols; col++) {
            printf("%d ", table[row][col]);
        }
        printf("\n");
     } 
}

//Array of pointers to arrays
void print_table_ptrs(int* table[], int num_rows, int num_cols) {
    int row, col;
    for(row=0; row<num_rows; row++) { 
        for(col=0; col<num_cols; col++) {
            printf("%d ", table[row][col]);
        }
        printf("\n");
     } 
}