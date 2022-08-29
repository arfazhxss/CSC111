#include <stdio.h>

/* count_less(n, T, v)
Given an n x n integer array T, along with a value v,
count and return the number of entries of T which are less
than or equal to v. */
/* (your code from below would be placed here) */

int count_less (int n, int T[n][n], int v) {
    int i=0, j=0,count=0;

    for (i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            if (T[i][j]<=v) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int T1[3][3] = { { 10, 14, 2021},
    { 11, 8, 2021},
    {111, 116, 445} };

    int T2[4][4] = { { 9,10,11,12 },
    { 5, 6, 7, 8 },
    { 1, 2, 3, 4 },
    {13,14,15,16 } };

    printf("Elements less than 6 in T1: %d\n", count_less(3, T1, 6) );
    printf("Elements less than 17 in T1: %d\n", count_less(3, T1, 17) );
    printf("Elements less than 6 in T2: %d\n", count_less(4, T2, 6) );
    printf("Elements less than 17 in T2: %d\n", count_less(4, T2, 17) );

    return 0;
}