#include <stdio.h>
#include <ctype.h>

int main(){
    
    char val;
    
    val = getchar();
    
    while(val != '#'){
        
        if(isupper(val) != 0){
            printf("Val is uppercase\n");
        }else
            val = toupper(val);
        printf("%c\n", val);
        val = getchar();
    }
    
    printf("%c\n", val);
    
    return 0;
}
