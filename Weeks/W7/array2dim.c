#include <stdio.h>

void print_table_ptrs(int* table[], int nrows, int ncols) {
    int row, col;

    for(row=0; row<nrows;row++) {
        for(col=0; col<ncols; col++) {
            printf("%d ", table[row][col]);
        }
        printf("\n");
    }
}

int main() {

    int a1[3] = {1, 2, 3};
    int a2[3] = {4, 5, 6};
    int* table1[2] = {a1, a2};

    int b1[4] = {10, 20, 30, 40};
    int b2[4] = {50, 60, 70, 80};
    int b3[4] = {90, 100, 110, 120};
    int* table2[3] = {b1, b2, b3};

    print_table_ptrs(table1, 2, 3);
    print_table_ptrs(table2, 3, 4);

    return 0;
}