#include <string.h>
#include <stdio.h>

void string_reverse(char str[]);

int main(){

    char test[] = "mymouth";
    
    string_reverse(test);
    
    printf("%s\n", test);
    return 0;
}

void string_reverse(char s[]){
    printf("len:%d\n",len);
    for(int i=0; i<len/2; i++){
        char temp = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = temp;
    }
}