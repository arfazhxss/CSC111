#include <stdio.h>
#include <string.h>
/* last_word(input_string, output_array)
Given a null terminated C string input_string and an output output_array,
set output_array to contain a null-terminated C string containing the last
word in input_string. You may assume that the input string contains only
letters (uppercase/lowercase) and spaces. No newlines, tabs, punctuation
or other characters will appear. The last word is defined to be the last
sequence of one or more contiguous non-space characters in the string.
See the examples below for various special cases.

Note that the output string should be empty if the input string is empty
or if the input string contains no word characters.
Don't forget the null terminator.
You may assume that output_array will always have enough space to store the
desired output (so no bounds checking is needed).
*/
/* (your code would be placed here) */

void last_word (char in[], char out[]) {
    int i;
    int count=0;
    int total = strlen(in)-1;
    for (i=total;i>=0;i--) {
        if ((in[i]==' ') && (i!=total)) {
            break;
        } count++;
    } 

    int left = total - count;

    for (i=0;i<count+1;i++) {
        if (in[left+i+1]==' ') {
            break;
        }
        out[i]=in[left+i+1];
    }
    out[i] = '\0';
}

int main(){
char S1[] = "Hello World";
char S2[] = " Raspberry";
char S3[] = "Programming";
char S4[] = " This string starts and ends with spaces ";

char output[100];
last_word(S1, output);
printf("Result for S1: \"%s\"\n", output );
last_word(S2, output);
printf("Result for S2: \"%s\"\n", output );
last_word(S3, output);
printf("Result for S3: \"%s\"\n", output );
last_word(S4, output);
printf("Result for S4: \"%s\"\n", output );
return 0;
}