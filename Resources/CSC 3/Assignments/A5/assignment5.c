#include <stdio.h>
#include <string.h>

int size = 10;

void print_array (int array[], int len);
int sum_cubes (int array[], int len);
void multiply_all (double array[], int len, double multiplier);
int sum_below (int iarray[], int ilen, int oarray[], int olen, int thres);
int does_contain_multiples (int array[],int len,int multiple);
int count_if_contains_multiples (int arr1[], int len1, int arr2[], int len2);
int find_min (int nrow, int ncol, int array[][ncol]);
int keep_even (int nrow, int ncol, int array[][ncol]);

int main() {
/*
    int a0[] = {0,0,0,0,0,0,0,0,0,0};
    int a1[10] = {1,2,3,4,5,6,7,8,9,10};
    int a2[10] = {2,4,6,8,10,12,14,16,18,20};
    double a3[10] = {1.98,2.98,3.98,4.98,5.98,6.98,7.98,8.98,9.98,10.98};
    //int a4[10] = {1,3,4,5,6,7,2,8,9,10};
    int a8[6] = {5,7,6,2,1,3};
    int a5[] = {9,7,18,12,21};
    int a6[] = {12,5,14,3}; 


    printf("test1:a1\n"); 
    print_array (a1,10);
    printf("test2:a1\n%d\n",sum_cubes(a1,10));
    printf("test3:a3\n");
    multiply_all(a3,10,2);
    tprint_array (a3,10);
    multiply_all(a3,10,0.5);
    tprint_array (a3,10);

    printf("\\\\//before test4:a8,a0\n");
    print_array (a8,6);
    print_array (a0,6);
    printf("\\\\//after test4:a8,a0\n%d\n",sum_below(a8,6,a0,6,5));
    print_array (a8,6);
    print_array (a0,6);

    printf("test5:a2\n%d\n",does_contain_multiples(a2,10,11));
    printf("test6:a6,a5\n%d\n",count_if_contains_multiples(a6,4,a5,5));
    
    int table1[6][5] =  {{37, -122,   75,  23,   71},
                        {30,  14,   15,   100,    20},
                        {65,  30,   58,  79,    30},
                        {20,  0,   86,  26,    40},
                        {30,   30,    80,   30,    20},
                        {88, 100000,   36,  11,    60}};

    printf("test7:table1\n%d\n",find_min(6,5,table1));
    tprint_table_2d(6,5,table1);

    printf("test8:table1\n%d\n",keep_even(6,5,table1));
    tprint_table_2d(6,5,table1);
*/
    return 0;
}

/* Purpose: prints the elements in array separated by commas
 * Parameters: int array[] - the array of integers
 *             int len - the number of elements in the array
 * Returns: Null.
 */

void print_array (int array[], int len) {
    int i = 0;
    if (len>=1) {
        for (i = 0; i < len; i++) {
            printf("%d", array[i]);
            if (i!=len-1) {
                printf(",");
            }
        }
    printf("\n");
    }
}

/* Purpose: sums the cubes of each othe elements in the 1D array
 * Parameters: int array[] - the array of integers
 *             int len - the number of elements in the array
 * Returns: integer sum of the cubes of each othe elements in the 1D array
 */

int sum_cubes (int array[], int len) {
    int i = 0, cube_sum = 0, cube;
    for (i = 0; i < len; i++){
        cube = array[i]*array[i]*array[i];
        cube_sum += cube;
    }
    return cube_sum;
}

/* Purpose: multiply each elements of the array with a given parameter: multiplier
 * Parameters: double array[] - the array of double elements
 *             int len - the number of elements in the array
 *             double multiplier - double parameter used for multiplying each elements in the 1D array
 * Returns: Null
 */

void multiply_all (double array[], int len, double multiplier) {
    int i = 0;
    for (i = 0; i < len; i++){
        array[i] *= multiplier;
    }
}

/* Purpose: multiply each elements of the array with a given parameter: multiplier
 * Parameters: int iarray - the array of integer elements in the input 1D array
 *             int ilen - the number of elements in the input array
 *             int oarray - the array of integer elements in the output 1D array
 *             int olen - the number of elements in the output array
 *             int thres - the threshold number/ limit integer, larger than which, elements in the array will be -111
 * Returns: the integer sum of each of the integer elements under the given threshold parameter.
 */

int sum_below (int iarray[], int ilen, int oarray[], int olen, int thres) {
    int i = 0, sum_io = 0;
    int cons = 0, temp = 0;
    int tem[size];
    int temrev[size];

    memset(oarray, 0, olen*sizeof(oarray[0]));
    memset(tem, 0, size*sizeof(tem[0]));
    memset(temrev, 0, size*sizeof(temrev[0]));

    for (i = 0; i < ilen; i++) {
        if (iarray[i]<thres) {
            temp=iarray[i];
            sum_io += temp;
            tem[cons]=temp;
            cons++;
        }
    }

    --cons;
    for (i=0;i<=cons;i++) {
        temrev[cons-i]=tem[i];
    }

    for (i=0;i<=cons;i++) {
        oarray[i] =temrev[i]; 
    }

    for (i=olen;i>cons;i--) {
        oarray[i]=-111;
    }

    return sum_io;
}

/* Purpose: checks if a given 1D array has a multiple parameter (multiple) as given
 * Parameters: int array[] - the array of integers
 *             int len - the number of elements in the array
 *             int multiple - the multiple integer
 * Returns: 1, if there exists a multple;
 *          0, if not.
 */

int does_contain_multiples (int array[], int len, int multiple) {
    int val=0;
    for (int i=0; i<(len); i++) {
        if ((array[i]%multiple)==0) {
            val = 1;
        }
    }
    return val;
}

/* Purpose: checks if a given 1D array has a multiple parameter (multiple) in a second 1D array
 * Parameters: int arr1[] - the first array of integers
 *             int len1 - the number of elements in the first array
 *             int arr2[] - the second array of integers
 *             int len2 - the number of elements in the second array
 * Returns:    An integer which is the total number of elements which is found to be a multiple of the first array elements
 */

int count_if_contains_multiples (int arr1[], int len1, int arr2[], int len2) {
    int val = 0;
    for (int i = 0; i<len2; i++) {
        val += does_contain_multiples(arr1,len1,arr2[i]);
    }

    return val;
}

/* Purpose: checks and returns the minimum integer element of a 2D array
 * Parameters: int nrow - number of rows in the 2D array
 *             int ncol -  number of columns in the 2D array  
 *             int array[][ncol] - the 2D array which is to be checked for a minimum
 * Returns:    integer value of the minimum value in the array
 */

int find_min (int nrow, int ncol, int array[][ncol]) {
    int minval = 1000;
    for (int i=0; i<nrow; i++) {
        for (int j=0; j<ncol; j++) {
            if (array[i][j]<minval) {
                minval = array[i][j];
            }
        }
    }
    return minval;
}

/* Purpose: takes a 2D array, update the odd integer elements in the array to -111 and returns the number of odd integers
 * Parameters: int nrow - number of rows in the 2D array
 *             int ncol -  number of columns in the 2D array  
 *             int array[][ncol] - the 2D array which is to be checked for a minimum
 * Returns:    number of updated (odd) elements in the array
 */

int keep_even (int nrow, int ncol, int array[][ncol]) {
    int con=0;
    for (int i=0; i<nrow; i++) {
        for (int j=0; j<ncol; j++) {
            if ((array[i][j]%2)!=0) {
                array[i][j] = -111;
                ++con;
            }
        }
    }
    return con;
}
