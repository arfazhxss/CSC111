#include <stdio.h>
#include <string.h>
/* (your code from below would be placed here) */

void shift_string_right(char S1[]) {
    int len = strlen(S1)-1;
    //printf("len:%d\n",len);
    char S2[len+1];
    int i=0;
    for (int i=0;i<=len;i++) {
        S2[i] = S1[i];
    }
    for(i=0;i<=len;i++) {
        S1[i] = S2[i-1];
        //printf("test S1[%d]:%c S2[%d]:%c\n",i,S1[i],i,S2[i]);
    }
    S1[0]=S2[len];
    S1[len+1] = '\0';
}

int main(){
    char s1[] = "earth";
    char s2[] = "electives";
    printf("First example: %s ", s1);
    shift_string_right(s1);
    printf("\"%s\"\n", s1);
    printf("Second example: %s ", s2);
    shift_string_right(s2);
    printf("\"%s\"\n", s2);
    return 0;
}