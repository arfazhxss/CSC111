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
        
    FILE* out_file;
    out_file = fopen(OUTPUT_FILE, "w");
    double sin_x; 
    double x;
    
    if(out_file == NULL){
        printf("Error opening out file\n");
    }else{
        //print heading to the file 
        fprintf(out_file, "x    sin(x)\n");
        
        //calc and print values to file
        for(int i=1; i<=n; i++){
            x = (PI * i) / n;
            sin_x = sin(x);
            fprintf(out_file, "%.3f    %.3f\n", x, sin_x);
        }
        
        //close the file
        fclose(out_file);
    }
    
    
}
