#include <stdio.h>
#define ENG_PASS 60
#define PASS 50

int pass_class(double mark, int eng_flag);

int main(){
    printf("%d, should be 1\n", pass_class(65, 1)); //should return 1
    printf("%d, should be 1\n", pass_class(80, 0)); //should return 1
    printf("%d, should be 0\n", pass_class(59, 0)); //should return 0
}

/*
 * Write a function that prints out if a student has passed a course/ 
 * Parameters: double mark - the mark the student received; int eng_flag - 1 if the student is in engineering, 0 otherwise
 * Returns: 1 if the student passed the course, 0 otherwise. 
*/
int pass_class(double mark, int eng_flag){
    
    if(eng_flag == 1){
        if(mark >= ENG_PASS){
            return 1;
        }else{
            return 0;
        }
    
    }else{
        if(mark >= PASS){
            return 1;
        }else{
            return 0;
        }
    }
    
    return 0;
} 












// Convert the pass_class function to accept arguments