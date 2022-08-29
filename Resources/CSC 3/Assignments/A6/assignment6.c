

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN        50
#define CHAR_ARRAY_WIDTH    MAX_WORD_LEN+1 // allow for null terminator character

int is_word_character(char ch);
void to_lowercase(char dest[], char word[]);
int is_word_in_terms(char word[CHAR_ARRAY_WIDTH], char terms[][CHAR_ARRAY_WIDTH], int len_terms);
void censor(char infilename[], char outfilename[], char terms[][CHAR_ARRAY_WIDTH], int len_terms);


int main() {
    // one test case to get you started, uncomment once censor is defined
    
    /*
    char filename_in[] = "happy_small.txt";
    char terms2[][CHAR_ARRAY_WIDTH] = {"air", "with"};
    censor(filename_in, "happy_small_out_terms2.txt", terms2, 2);
    */
    

    return 0;
}
void censor(char infilename[], char outfilename[], char terms[][CHAR_ARRAY_WIDTH], int len_terms){

}

/*
 * Purpose: determines whether ch is valid word character as defined in Assignment 6 PDF
 * Parameters: char ch
 * Returns: int, 1 if ch is a word character, 0 otherwise
 */
int is_word_character(char ch) {
    return (isalpha(ch) || ch=='-' || ch=='\'');
}
