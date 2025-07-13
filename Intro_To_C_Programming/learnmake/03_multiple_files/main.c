#include <stdio.h>
#include "calculator.h"
#include "utils.h"

int main() {
    printf("=== Calculator Program with Multiple Files ===\n");
    
    int a = 15, b = 4;
    
    printf("Numbers: %d and %d\n", a, b);
    printf("Addition: %d + %d = %d\n", a, b, add(a, b));
    printf("Subtraction: %d - %d = %d\n", a, b, subtract(a, b));
    printf("Multiplication: %d * %d = %d\n", a, b, multiply(a, b));
    printf("Division: %d / %d = %.2f\n", a, b, divide(a, b));
    
    printf("\nUtility functions:\n");
    printf("Maximum: %d\n", max(a, b));
    printf("Minimum: %d\n", min(a, b));
    
    print_separator();
    printf("Program completed successfully!\n");
    
    return 0;
}

