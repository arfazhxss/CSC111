#include <stdio.h>
typedef int Table[100][100];
/* print_diagonal(T, n)
Given a Table T, which will have n rows and n columns, print all of the
entries on the main diagonal of T (that is, entries whose row number and
column number are equal). Remember to print a newline at the end. */
/* (your code from below would be placed here) */

void print_diagonal (Table T, int n) {
    int i=0, j=0; 
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            if(i==j) {
                printf("%d ",T[i][j]);
            }
        } 
    } printf("\n");
}

int main() {
    Table T1 = { { 10, 10, 2019},
    { 11, 14, 2019},
    {111,116, 225} };
    Table T2 = { { 1, 2, 3, 4 },
    { 5, 6, 7, 8 },
    { 9,10,11,12 },
    {13,14,15,16 } };
    print_diagonal(T1, 3);
    print_diagonal(T2, 4);
    return 0;
}