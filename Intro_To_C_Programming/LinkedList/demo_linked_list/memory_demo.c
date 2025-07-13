#include <stdio.h>
#include <stdlib.h>

// Example program with memory issues for Valgrind demonstration
int main() {
    printf("🧪 Memory Issues Demo for Valgrind\n");
    printf("==================================\n\n");
    
    // 1. Memory Leak - allocated but never freed
    printf("1. Creating memory leak...\n");
    int* leaked_memory = malloc(sizeof(int) * 10);
    *leaked_memory = 42;
    printf("   Allocated 40 bytes, stored value: %d\n", *leaked_memory);
    // Intentionally NOT calling free(leaked_memory);
    
    // 2. Use after free
    printf("\n2. Use after free example...\n");
    int* ptr = malloc(sizeof(int));
    *ptr = 100;
    printf("   Value before free: %d\n", *ptr);
    free(ptr);
    // Commenting out the dangerous line to avoid crash
    // printf("   Value after free: %d\n", *ptr); // DANGEROUS!
    printf("   (Use after free commented out to avoid crash)\n");
    
    // 3. Double free (commented out to avoid crash)
    printf("\n3. Double free example...\n");
    int* ptr2 = malloc(sizeof(int));
    free(ptr2);
    // free(ptr2); // DANGEROUS! Would cause double free
    printf("   (Double free commented out to avoid crash)\n");
    
    // 4. Buffer overflow
    printf("\n4. Buffer overflow example...\n");
    int* array = malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++) {
        array[i] = i * 10;
    }
    // array[5] = 999; // DANGEROUS! Out of bounds write
    printf("   (Buffer overflow commented out to avoid crash)\n");
    free(array);
    
    // 5. Uninitialized memory read
    printf("\n5. Uninitialized memory read...\n");
    int* uninit = malloc(sizeof(int));
    // Reading uninitialized memory (Valgrind would catch this)
    printf("   Uninitialized value: %d (may be garbage)\n", *uninit);
    free(uninit);
    
    printf("\n🎯 Run this with Valgrind to see memory error detection!\n");
    printf("   valgrind --leak-check=full ./memory_demo\n");
    
    return 0;
    // leaked_memory is never freed - Valgrind will report this!
}

