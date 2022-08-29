#include <stdio.h>

double median(double a, double b, double c);
int is_multiple_of(int a, int b);
int permitted_to_register(double a, int b);
void print_multiples(int a, int b);
void factorial_sum(int a);
void print_number_triangle(int max, int rep);

int main() {
    printf("%.4f\n", median(3.2, 20.22, 3.2));
    printf("%d\n", is_multiple_of(12, 3));
    printf("%d\n", permitted_to_register(1.9, 0));
    print_multiples(4, 4);
    factorial_sum(12);
    print_number_triangle(8,2);

    return 0;
}


  /* Purpose: The function takes three double values
   *   and finds the median of those values
   * Parameters: a (First Number), b (Second Number),
   *    c (Third Number).
   * Returns: The function returns a double median value of the numbers.
   */


double median(double a, double b, double c) {
    double median_number;
   if ((a >= b) && (b >= c)) {
      median_number = b;
   } else if ((c >= a) && (a >= b)) {
      median_number = a;
   } else if ((b >= c) && (c >= a)) {
      median_number = c;
   } else if ((b >= a) && (a >= c)) {
      median_number = a;
   } else if ((a >= c) && (c >= b)) {
      median_number = c;
   } else if ((c >= b) && (b >= a)) {
      median_number = b;
   } else {
      printf("Unexpected Error\n");
   }
   return median_number;
}

  /* Purpose: The function takes two integer values and gives
   *   a truth or false value to whether the second value is a 
   *   multiple of the first one.
   * Parameters: a (The possible multiple), b (The multiplier)
   * Returns: The function returns a boolean Yes (1) or No (0).
   */

int is_multiple_of(int a, int b) {
   if ((b%a) == 0) {
      return 0;
   } else {
      return 1;
   }
}

  /* Purpose: The function takes one double floating value - the GPA of a student
   *   and one ineger value, the academic standing of the student, and gives a
   *   truth or false value to whether they are permitted to get registered.
   * Parameters: a (The Sessional GPA of a student), b (The boolean answer to 
   *   the academic standing of the student, Yes or No), c (The boolean return value (0, 1)
   *   when the student can register and the error (-1) when a student can not register)
   * Returns: The function returns an boolean Yes (1), No (0) or an error (-1).
   */

int permitted_to_register(double a, int b) {
    
    int val;

    if ((a>=2.0) && (a<=9.0)) {
        if ((a>=2.0)&&(b==1)) {
            val = 1;
        } else if ((a<2.0)&&(b==1)) {
            val = 0;
        } 
    } else if ((a<2.0)&&(b==0)) {
        val = -1;
    } else {
        printf("Error\n");
    }

    return val;
}

  /* Purpose: The function takes two integer values and prints 
   *   the increasing number of multiples.
   * Parameters: a (The first number), b (The number of multiples), 
   *   i (increasing reiteration of the added multiple value to a),
   *   c (The multiples to a after each iteration).
   * Returns: The function does not return any value.
   */

void print_multiples(int a, int b) {
    
    int i = 0; 
    int c = 0;

    if ((a!=0)&&(a>0)&&(b>=0)) {
        while (i<=(a+2)) {
            printf("%d", b+c);
            i++, 
            c=(b*i);
            if (i==(a+2)) {
                break;
            } else {
                printf(", ");
            }
        }
    } else if ((a!=0)&&(a>0)&&(b<0)) {
        while (i<=(a+2)) {
                printf("%d", b-c);
                i++; 
                c=(b*i);
                if (i==(a+2)) {
                    break;
                } else {
                    printf(", ");
                }
            }
    } else if (a==0) {
            printf(" ");
    } else {
        printf("Error\n");
    }
    printf("\n");
}

  /* Purpose: The function takes one integer value and prints the 
   *   factorial multiplication of the given value.
   * Parameters: a (The number whose factorial is needed to be find out),
   *   i (increasing iteration that needs to be subtracted after each loop),
   *   b (subtracted expressions after each loop),
   *   c (accumulated multiplied values after each loop).
   * Returns: The function does not return any value.
   */

void factorial_sum(int a) {
    
    int i = 0;
    int b; int c = 1;

    printf("%d! = ", a);

    while (i<a) {
        b = (a-i);
        i++;
        c = c * b;
        printf("%d", b);
        if (i==(a)) {
            break;
        } else {
            printf(" * ");
        }
    }

    printf(" = %d\n", c);
}

  /* Purpose: The function takes two integer values and prints 
   *   repeated triangles with the highest numbers reiterated in each line.
   * Parameters: max (number of times the iteration from 0 needs to take place),
   *   rep (number of repeated triangles of numbers)
   *   tri_n (number of triangles in each outer loop),
   *   a (Number of times in each line, the reiteration from 0 takes place),
   *   i (increasing reiterated values of a, until a reaches the maximum max value).
   * Returns: The function does not return any value.
   */

void print_number_triangle(int max, int rep) {
    int tri_n = 1;
    while (tri_n <= rep) {
        for (int a=0; a<=max; a++) {
            for (int i=0; i<=a; i++) {
                printf("%d ", i);
            }
            printf("\n");
        }
        tri_n++;
    }
}