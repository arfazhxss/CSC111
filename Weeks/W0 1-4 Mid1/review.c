#include <stdio.h>

int main() {
    int n = 4;
    for (int i = n; i > 0; i--) {
        for (int s = n-i;(s!=0)&&(s<n);s--) {
            printf(" ");
        }
        for (int num = i; num > 0; num--) {
            printf("%d", num);
        }
        printf("\n");
    }
}
