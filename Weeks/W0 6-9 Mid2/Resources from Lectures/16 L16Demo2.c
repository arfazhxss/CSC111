#include <stdio.h>
#include <string.h>
void print_array(int len, char array[len]);
void print_string(char str[]);
int main(){
    //declare some strings - two ways
    //use strcpy, strlen, strcmp
    
    char test1[] = {'H', 'e', 'l', 'l', 'o'};
    char test2[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    
    char test3[] = "HelloWorld";
    char test4[] = "Hi!";
    
    //printf("Result of strlen: %ld\n",strlen(test2));
    //printf("Result of strlen with a string with no null terminator %ld\n", strlen(test1));
    
    if(strcmp(test2, test1) == 0){
        printf("They are the same\n");
    }else{
        printf("they are not the same\n");
    }
    strcpy(test3, test4);
    
    print_string(test3);
    
    return 0;
    
}

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


