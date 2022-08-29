#include <stdio.h>
#include <ctype.h>

int count_not_space(){
    
    int count =0;
    
    char curr;
    //promt the user for input
    printf("Please enter some characters\n");
    
    //read in the input from keyboard one char at a time - getchar()
    curr =getchar();
    
    //Reaed in input until # - in while loop
    while(curr != '#'){
        // count numbers that are not spaces
        if(isspace(curr) == 0){
            count = count +1;
        }
        curr = getchar();
    }
    
    return count;
    
}

int main(){

    printf("There were %d char in your input\n", count_not_space());
    return 0;
    
}

