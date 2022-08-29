#include <stdio.h>
#include <string.h>
/*
void a_function(char S1[], char S2[], char output[]) {
    int j = 0;
    int k = 0;
    output[k] = S1[k];
    k++;
    while(S1[j] != '\0' && S2[j] != '\0'){
        printf("k:%d j:%d\n",k,j);
        output[k] = S2[j];
        k++;
        j++;
    }
    output[k] = '\0';
}
*/
int main()
{
    /*
    int k = 7;
    int* p3 = &k;
    int** p2 = &p3;
    int*** p1 = &p2;
    *p3=19;
    **p2 = 18;
    ***p1=17;
    printf("k %d\np1 %d\np2 %d\np3 %d\n",k,***p1,**p2,*p3);

    printf("\n2\n");
    int x;
    int y;
    int* p;
    int* q;
    int** t;
    x=44;
    p=&x;
    q=p;
    y=19;
    t=&q;
    printf("x %d\ny %d\np %d\nq %d\nt %d\n",x,y,*p,*q,**t);

    printf("\n3\n");
    char a = 'a';
    char b = (int)'a';
    char c = "a";
    char S1[] = "Hi";
    printf("%c %lu\n%d %lu\n%d %lu\n",a,sizeof(a),b,sizeof(b),c,sizeof(c));
    */
    printf("QUESTION 1 TEST\n");
    int a = 17;
    int b = 10;
    float x = 11.1;
    float y = 11.6;
    float* F[2] = {&x,&y};

    printf("F[0]:%.2f F[1]:%.2f\n",*F[0],*F[1]);
    printf("1:6? Actual:%d\n",(a+b)%(a-b));
    printf("2:12.8? Actual:%.4f\n",x+(a/b));
    printf("3:2.81? Actual:%.2f\n",(x+a)/b);
    printf("4:28.1? Actual:%.2f\n",(a++)+x);
    printf("5:20.6? Actual:%.2f",y+(--b));

    
    printf("\nQUESTION 2 TEST\n");
    typedef struct {
       int x;
       int* z;
   } MysteryStruct;
   int A[5] = {6,10,17,187,111};
   int B[3] = {3,14,15};
   int* p = &A[1];
   MysteryStruct M1, M2;
   M1.x = -1;
   M1.z = &B[0];
   M2.x = 100;
   M2.z = &A[0];
   MysteryStruct* q = &M1;
   //printf("1 %d\n",*q);
   //printf("2 %d\n",M1+M2);
   printf("3 %d\n",(*q->z));
   printf("4 %d\n",*((*q).z));
   printf("5 %d\n",*p+q->x);
   printf("6 %d\n",*p+1);
   for (int i=0; i<5; i++) {
       printf("A[%d]=%d ",i,A[i]);
   } printf("\n");
      for (int i=0; i<3; i++) {
       printf("B[%d]=%d ",i,B[i]);
   } printf("\n");
   printf("%d\n",M1.x);
   printf("11\t%d\n",*(p+1));
   printf("11.1\t%d\n",p[1]);
   printf("12\t%d\n",*M1.z);
   //printf("13\t%d\n",q.x);
   //printf("14\t%d\n",*q.z);
   printf("15\t%d\n",*q->z);
   printf("16\t%d\n",(*q).x);
   printf("17\t%d\n",*(&M1)->z++);
   printf("18\t%d\n",*(M1=M2).z);
    /*
    printf("\nQUESTION 3 TEST\n");
    int n=15;
    for (int i=0;i<n;i++) {
        if(i%2==0){
            printf("%d ",i);
        } if (i%5==1) {
            printf("%d ",i);
        }
        n--;
    }
    printf("\n");

    
    
    char str[] = "raspberry";
    char c = str[1];
    printf("strlen:%lu",strlen(str));
    int i=0;
    for (int i=0;i<8;i++) {
        printf("str[%d]:%c\n",i,str[i]);
    }
    while(i<strlen(str)) {
        printf("%c ", c);
        c=str[i];
        i++;
        printf("char:%c i:%d arg:%d\n",c,i,(c!='r')||(c!='a'));
        if ((c!='r')||(c!='a')) {
            i++;
        }
    }
    printf("\n");
    
    printf("\nQUESTION 6 TEST\n");
    char string1[] = "foe";
    char string2[] = "old";
    char string3[] = "shoe";
    char string4[] = "cold";
    char string5[] = "boot";
    char string6[] = "locked";
    char output[100];
    a_function(string1, string2, output);
    printf("%s %s: %s\n",string1, string2, output);
    a_function(string3, string4, output);
    printf("%s %s: %s\n",string3, string4, output);
    a_function(string5, string6, output);
    printf("%s %s: %s\n",string5, string6, output);
    */
    return 0;
}
