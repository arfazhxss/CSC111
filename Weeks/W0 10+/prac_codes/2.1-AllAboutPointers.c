#include <stdio.h>

int main() {
    printf("\nPOINTER TEST START\n");
    int x = 5;
    int* p = &x;
    *p=6;
    int** q = &p;
    int*** r = &q;
    printf("x = %d\n",x);
    printf("p = %d\n",p);
    printf("*p = %d\n",*p);
    printf("*q = %d\n",*q);
    printf("**q = %d\n",**q);
    printf("**r = %d\n",**r);
    printf("***r = %d\n",***r);


    printf("\nMODIFICATION\n");
    ***r = 10;
    printf("x after (***r = 10) = %d\n",x);
    **q = *p+2;
    printf("x after (**q = *p+2) = %d\n",x);
 } 