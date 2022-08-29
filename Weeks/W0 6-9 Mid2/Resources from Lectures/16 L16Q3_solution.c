#include <string.h>
#include <stdio.h>

void string_reverse(char str[]);

int main(){

    char test[] = "racecar";
    
    string_reverse(test);
    
    printf("%s\n", test);
    return 0;
}

void string_reverse(char str[]){
    //need to know the length of the string 
    
    int len = strlen(str);
    
    for(int i=0; i<len/2; i++){
        char temp = str[i];
        str[i] = str[len-i-1];
        
        str[len-i-1] = temp;
    }
}