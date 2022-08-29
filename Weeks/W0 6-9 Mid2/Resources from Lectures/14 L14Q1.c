#include <stdio.h>
#define INPUTFILE "input.dat"

int count_above();

int main( void ) {
    printf("Found %d values above the threshold entered\n", count_above());
    return 0;
}

/*
 * Purpose: prompts user for a threshold value and counts the number of entries 
 *    in INPUTFILE that are greater than the given threshold value
 * Parameters: None
 * Returns: int, the count, -1 if error opening INPUTFILE or reading from user
 */

int count_above() {
    FILE* in_file;
    double next_val;
    double threshold_val;
    int count_above = 0;

    in_file = fopen( INPUTFILE, "r" );
    if( in_file == NULL ) {
        printf( "Error opening input file\n" );
        return -1;
    } else {
        //your code here
    
    }
}
