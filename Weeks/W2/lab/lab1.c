#include <stdio.h>

void calculate_distances();

int main() {
    printf("\"Welcome to CSC 111\"\n");
    
    int n = 111;
    double divisor = 1000.0;
    double result = n/divisor;
    
    printf("The value of n is \"%d\" and the divisor is \"%.2f\"\nThe result is \"%.3f\"\n", n, divisor, result);
    
    calculate_distances();
    
    return 0;
}

void calculate_distances () {
    double velocity = 3.0;
    double time = 2.0;
    double accelaration = 2.0;
    double distance = ((velocity*time)+((accelaration*time*time)/2));
    
    printf("Using a = %.6f, t = %.6f, v = %.6f, d = %.6f\n", accelaration, time, velocity, distance);
    
    velocity = 17.0;
    time = 10.0;
    accelaration = 6.0;
    distance = ((velocity*time)+((accelaration*time*time)/2));
    
    printf("Using a = %.6f, t = %.6f, v = %.6f, d = %.6f\n", accelaration, time, velocity, distance);
    
    velocity = 11.1;
    time = 1.06;
    accelaration = 0.5;
    distance = ((velocity*time)+((accelaration*time*time)/2));
    
    printf("Using a = %.6f, t = %.6f, v = %.6f, d = %.6f\n", accelaration, time, velocity, distance);
    
}