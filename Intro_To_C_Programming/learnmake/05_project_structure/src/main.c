#include <stdio.h>
#include "calculator/calculator.h"
#include "logger/logger.h"
#include "config/config.h"

int main() {
    printf("=== Project Structure Demo ===\n");
    
    // Initialize logger
    init_logger();
    log_info("Application started");
    
    // Load configuration
    Config config = load_config();
    printf("App: %s v%s\n", config.app_name, config.version);
    
    // Perform calculations
    log_info("Performing calculations");
    int a = 12, b = 8;
    
    printf("\nCalculations:\n");
    printf("%d + %d = %d\n", a, b, calc_add(a, b));
    printf("%d - %d = %d\n", a, b, calc_subtract(a, b));
    printf("%d * %d = %d\n", a, b, calc_multiply(a, b));
    printf("%d / %d = %.2f\n", a, b, calc_divide(a, b));
    
    log_info("Calculations completed");
    log_info("Application finished");
    
    return 0;
}

