#include <stdio.h>
#include <math.h>

#define OUTPUT_FILE "sine_table.dat"
//acos(-1) returns the value of pi
#define PI acos(-1.0)

void write_sine_table(int n);

int main( void ) {
    write_sine_table(5);

    return 0;
}

/*
 * Purpose: write a table of sine values with n rows to OUTPUT_FILE
 * Parameters: int n - number of rows in the table
 */
void write_sine_table(int n) {
    
}
