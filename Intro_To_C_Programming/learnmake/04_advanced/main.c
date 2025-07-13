#include <stdio.h>
#include "math_ops.h"
#include "string_ops.h"
#include "file_ops.h"

int main() {
    printf("=== Advanced Makefile Demo ===\n");
    
    // Math operations
    printf("\nMath Operations:\n");
    printf("Power: 2^8 = %d\n", power(2, 8));
    printf("Factorial: 5! = %d\n", factorial(5));
    
    // String operations
    printf("\nString Operations:\n");
    char str[] = "Advanced Makefile";
    printf("Original: %s\n", str);
    printf("Length: %d\n", string_length(str));
    reverse_string(str);
    printf("Reversed: %s\n", str);
    
    // File operations
    printf("\nFile Operations:\n");
    create_sample_file();
    read_sample_file();
    
    printf("\nDemo completed!\n");
    return 0;
}

