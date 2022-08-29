#include <stdio.h>
int main() {
    printf("IMPORTANT FORMULA\n1\t(B+i) = &B[i]\n2\t*(B+i) = B[i] = &B[i][0]\n3\tB[i][j] = *(B[i]+j) = *(*(B+i)+j)\n");
    int B[2][3] = {{2,3,6},{4,5,6}};
    
    printf("\nMAIN\n");
    for(int i=0;i<3;i++) {
        printf("i=%d\n",i);
        printf("(B+%d)=%d\t\t&B[%d]=%d\n",i,(B+i),i,&(B[i]));
        printf("*(B+%d)=%d\t\tB[%d]=%d\t\t&B[%d][0]=%d\n\nB[%d][0]=%d\n",i,*(B+i),i,B[i],i,&B[i][0],i,B[i][0]);
        printf("**(B+%d)=%d\n",i,**(B+i));
        printf("\n");
    }

 } 