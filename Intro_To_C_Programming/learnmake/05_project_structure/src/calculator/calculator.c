#include "calculator.h"
#include "../logger/logger.h"

int calc_add(int a, int b) {
    log_debug("Adding %d + %d", a, b);
    return a + b;
}

int calc_subtract(int a, int b) {
    log_debug("Subtracting %d - %d", a, b);
    return a - b;
}

int calc_multiply(int a, int b) {
    log_debug("Multiplying %d * %d", a, b);
    return a * b;
}

float calc_divide(int a, int b) {
    if (b == 0) {
        log_error("Division by zero attempted!");
        return 0.0;
    }
    log_debug("Dividing %d / %d", a, b);
    return (float)a / b;
}

int calc_power(int base, int exp) {
    log_debug("Calculating %d^%d", base, exp);
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

