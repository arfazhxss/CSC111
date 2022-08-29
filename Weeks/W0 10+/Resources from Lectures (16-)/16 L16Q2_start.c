#include <stdio.h>
#include <string.h>
#include <ctype.h>

int string_length(char str[]);

int main() {
    char str_mt[] = "";
    char str_not_full[10] = "Hello!!";
    char str_full[6] = {'H','e','l','l','o','\0'};
    int len = 0;
    int m, t;

    // test empty string:
    len = string_length(str_mt);
    printf("length should be 0: %d\n", len);
    

    // test not full array:
    m = string_length(str_not_full);
    printf("length should be 7: %d\n", m);
    

    // test full array:
    t = string_length(str_full);
    printf("length should be 5: %d\n", t);
}

/* 
 * Purpose: count characters in src upto but not including
 *      the null terminator.
 * Parameters: char src[], a null terminated string
 * Returns: int, the count of characters
 */
int string_length(char s[]) {
    int i;
    for (i = 0; s[i] != '\0'; ++i);
    return i;
}
