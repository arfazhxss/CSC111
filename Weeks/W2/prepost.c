#include <stdio.h>

void prefix_i();
void postfix_i();

int main() {
    prefix_i();
    postfix_i();

    return 0;
}

void prefix_i() {
    int global_i = 1;
    printf("\nPrefix Function\nThe value of \"I\" as stated: %d", global_i);
    printf("\nThe value of \"I\" with prefix line 1: %d", ++global_i);
    printf("\nThe value of \"I\" with prefix line 2: %d\n", global_i);
}

void postfix_i() {
    int global_i = 1;
    printf("\nPostfix Function\nThe value of \"I\" as stated: %d", global_i);
    printf("\nThe value of \"I\" with postfix line 1: %d", global_i++);
    printf("\nThe value of \"I\" with postfix line 2: %d\n\n", global_i);
}