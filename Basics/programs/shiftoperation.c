#include <stdio.h>

int deleteBitAtPosition(int n, int position) {
    if (position < 0 || position >= sizeof(int) * 8) {
        printf("Error: Invalid bit position.\n");
        return n; // Return original number if position is invalid
    }

    int mask = (1 << position) - 1;
    int lower_bits = n & mask;
    int higher_bits = n >> (position + 1);
    int higher_bits_shifted = higher_bits << position;
    int result = higher_bits_shifted | lower_bits;

    return result;
}

int main() {
    int n = 199;
    int position = 7;
    int result = deleteBitAtPosition(n, position);
    printf("Input: %d, Position: %d\n", n, position);
    printf("Output (After deleting bit at position %d): %d\n", position, result);

    position = 0;
    result = deleteBitAtPosition(n, position);
    printf("Input: %d, Position: %d\n", n, position);
    printf("Output (After deleting bit at position %d): %d\n", position, result);

    position = 5;
    result = deleteBitAtPosition(n, position);
    printf("Input: %d, Position: %d\n", n, position);
    printf("Output (After deleting bit at position %d): %d\n", position, result);

    return 0;
}

