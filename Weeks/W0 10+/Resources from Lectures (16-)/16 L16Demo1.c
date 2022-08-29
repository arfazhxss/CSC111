#include <stdio.h>

//change the %c to %d... Look what happens? Why is this ?
void print_array(int len, char array[len]){
    
    for(int i=0; i<len; i++){
        printf("%c ", array[i]);
    }
    printf("\n");
}

void print_string(char str[]){
    int i=0;
    
    while(str[i] != '\0'){
        printf("%c ", str[i++]); 
    }
    printf("\n");
}

//Remember that str[] is a pointer, as it is an array.
void print_string_ptr(char str[]){
    while(*str != '\0'){
        printf("%c ", *str++);
    }
    printf("\n");
}

int main(){
    //declare some strings - two ways
    
    char test1[] = {'H', 'e', 'l', 'l', 'o'};
    char test2[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    
    char test3[] = "HelloWorld";
    char test4[10] = "Hi!";
    //is there a difference in the print functions?
    
    //what happens if you forget the null terminator?
    print_array(5, test1);
    
    print_string(test1);
    print_string_ptr(test3);
    
    //why is there a difference between these two?
    print_string(test2);
    print_string(test1);
    
    
    return 0;
}