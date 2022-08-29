#include <stdio.h>

void print_qualification_status(float time_event, float time_trial);
void print_median(float num_a, float num_b, float num_c);
void print_triangle_type(float side_a, float side_b, float side_c);
void is_multiple_of(int n1, int n2);
void process_breathalyzer_results(double blood_alcohol_content, int n_warned);

int main() {
   print_qualification_status(4, 2);
   print_median(20.22, 3.2, 3.2);
   print_triangle_type(2, 2, 2);
   is_multiple_of(6, 12);
   process_breathalyzer_results(0.01, 0);
   return 0;
}

  /* Purpose: Finding out the time by how much a racer got qualified or 
   *   missed qualification for the Olympics.
   * Parameters: Two floating Numbers, event (time needed to qualify for the Olympics),
   *   trial (time needed during the trial event).
   * Returns: The function does not return any value.
   */

void print_qualification_status(float event, float trial) {
      if (event > trial) {
         printf("You qualified at %.2f seconds below the qualifying time\n", event-trial);
      } else {
         printf("You missed qualifying by %.2f seconds\n", trial-event);
      }
}

  /* Purpose: Finding the median number (middle set number) of three floating numbers.
   * Parameters: Three floating numbers, a (Number 1), b (Number 2), c (Number 3). 
   * Returns: The function does not return any value.
   */

void print_median(float a, float b, float c) {
   if ((a >= b) && (b >= c)) {
      printf("%.4f\n", b);
   } else if ((c >= a) && (a >= b)) {
      printf("%.4f\n", a);
   } else if ((b >= c) && (c >= a)) {
      printf("%.4f\n", c);
   } else if ((b >= a) && (a >= c)) {
      printf("%.4f\n", a);
   } else if ((a >= c) && (c >= b)) {
      printf("%.4f\n", c);
   } else if ((c >= b) && (b >= a)) {
      printf("%.4f\n", b);
   } else {
      printf("Unexpected Error\n");
   }
   
}

  /* Purpose: Finding the type of the triangle (Equilateral, Isosceles or Scalene)
   *   from the length of the sides.
   * Parameters: Three floating numbers, representing each side of the triangle,
   *   a (Side 1), b (Side 2), c (Side 3).
   * Returns: The function does not return any value.
   */

void print_triangle_type(float a, float b, float c) {
   if ((a == b) && (b == c) && (c == a)) {
      printf("Equilateral Triangle\n");
   } else if ((a <= 0) || (b <= 0) || (c <= 0)) {
      printf("Error in finding triangle type\n");
   } else {
      if ((a == b) || (b == c) || (c == a)) {
         printf("Isosceles Triangle\n");
      } else {
         if ((a != b) || (b != c) || (c != a)) {
            printf("Scalene Triangle\n");
         }
      }
   }
}

  /* Purpose: Finding whether a number (Number 2) is a multiple of 
   *   another number (Number 1). 
   * Parameters: Two integers, a (Number 1) and b (Number 2).
   * Returns: The function does not return any value.
   */

void is_multiple_of(int a, int b) {
   if ((b%a) == 0) {
      printf("The value of %d is a multiple of the value of %d\n", b, a);
   } else {
      printf("The value of %d is not a multiple of the value of %d\n", b, a);
   }
}

  /* Purpose: Finding whether an individual passed, failed or being warned 
   *   for intoxicated driving from a breathalyzer test.
   * Parameters: One double - the result of the breathalyzer test, 
   *   One integer - number of times previously warned.
   * Returns: The function does not return any value.
   */

void process_breathalyzer_results(double cont, int warn) {
   if ((cont >= 0) && (cont <= 0.049)) {
      printf("PASS\n");
   } else if (cont >= 0.08) {
      printf("FAIL penalty: $500, driving suspension: 90 days\n");
   } else {
      if ((cont >= 0.05) && (cont < 0.08) && (warn == 0)) {
         printf("WARNING penalty: $200, driving suspension: 3 days\n");
      } else if ((cont >= 0.05) && (cont < 0.08) && (warn == 1)) {
         printf("WARNING penalty: $300, driving suspension: 7 days\n");
      } else if ((cont >= 0.05) && (cont < 0.08) && (warn >= 2)) {
         printf("WARNING penalty: $400, driving suspension: 30 days\n");
      } else {
         printf("Error\n");
      }
   }
}