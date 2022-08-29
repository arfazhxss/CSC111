int string_length(char str[]);

int main() {
    char str_mt[] = "";
    char str_not_full[10] = "Hello!!";
    char str_full[6] = "Hello";
    int len = 0;

    // test empty string:
    len = string_length(str_mt);
    printf("length should be 0: %d\n", len);
    

    // test not full array:
    len = string_length(str_not_full);
    printf("length should be 7: %d\n", len);
    

    // test full array:
    len = string_length(str_full);
    printf("length should be 5: %d\n", len);
}

/* 
 * Purpose: count characters in src upto but not including
 *      the null terminator.
 * Parameters: char src[], a null terminated string
 * Returns: int, the count of characters
 */
int string_length(char src[]) {








}
