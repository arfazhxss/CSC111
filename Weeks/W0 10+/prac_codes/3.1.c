#include <stdio.h>
#include <ctype.h>

int main() {
    FILE* inputFile = fopen("/Users/arfazhussain/Downloads/foldier/smth.txt","r");
    char word[10];
    int inputSize;
    while (fscanf(inputFile, "%s" "%d", word, &inputSize) != -1) { 
        printf("%s(%d)\n", word, inputSize);
        for (int i=0;i<(inputSize*2);i++) {
            printf("%d ",i);
            char c = fgetc(inputFile);
                if (isspace(c)==0) {
                    printf("char is :%c %d %d", c,inputSize, i);
                    printf("\n");
                }
                else {
                    printf("Null\n");
                }
        }
    }
}