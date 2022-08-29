#include <stdio.h>
#include <ctype.h>

int main(){
    
    FILE* file_handle = fopen("input.txt", "r");
    
    if (file_handle != NULL) {
        char val;
        val = fgetc(file_handle);
        
        while (val != EOF){
            printf("%c\n", val);
            val = fgetc(file_handle);
        }
        
        fclose(file_handle);
        printf("done\n");
    }
}