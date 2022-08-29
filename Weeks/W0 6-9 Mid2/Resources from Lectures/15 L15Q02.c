#include <stdio.h>
#include <ctype.h>

void count_case(){
    
    int upper =0;
    int lower =0;
    int total =0;
    
    char curr;
    //promt the user for input
    printf("Please enter some characters\n");
    
    //read in the input from keyboard one char at a time - getchar()
    curr=getchar();
    
    //Reaed in input until # - in while loop
    while(curr != '#'){

        //add one to toal
        total++;
        //check to see if uppercase
         //check to see if the input is lowercase

        if(isupper(curr)){
            upper++;
        }else if(islower(curr)){
            lower++;
        }
        
        curr = getchar();
    }
    
    printf("There were %.1f Uppercase and %.1f lowercase letters entered", (upper/(float) total*100.0), (lower/(float) total *100));
}

int main(){

    count_case();
    return 0;
    
}

