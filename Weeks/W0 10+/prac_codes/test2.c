#include <stdio.h>

int main() {
    int a = 6;
    int b = 10;
    int c = 17;
    int* p = &a;
    int* q = &b;
    int* r = &c;
    int** X = &p;
    int** Y = &q;
    int** Z = &r;
    printf("%d",**(&q));
}