#include <stdio.h>
//#include <strings.h>

/* strings_equal(str1, str2)
Given two strings, return 1 if they are equal (have the same length and
contain the same sequence of characters) and 0 otherwise.
*/
/* (your code from below would be placed here) */

int strings_equal(char S1[],char S2[]) {

    int i=0;
    int l1=0;
    int l2=0;

    while (S1[i]!='\0') {
        l1++;
        i++;
    } printf("\"%s\" has %d letters\n",S1,l1);

    i=0;
    while (S2[i]!='\0') {
        l2++;
        i++;
    } printf("\"%s\" has %d letters\n",S2,l2);


    if(l1==l2) {
        int i=0;
        for(i=0;i<l1;i++) {
            if(S1[i]!=S2[i]) {
                return 0;
            } else {
                return 1;
            }
        }
    } return 0;
}

int main(){
    char S1[] = "Hello World";
    char S2[] = "Hello World";
    char S3[] = "Hello";
    char S4[] = "Raspberry Jam";
    char S5[] = "Blueberry Pie";

    printf("strings_equal(S1, S2): %d\n", strings_equal(S1, S2) );
    printf("strings_equal(S1, S3): %d\n", strings_equal(S1, S3) );
    printf("strings_equal(S4, S5): %d\n", strings_equal(S4, S5) );
    return 0;
}