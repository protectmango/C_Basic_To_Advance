#include <stdio.h>
#include <string.h>
#include "config.h"
#include "../logger/logger.h"

Config load_config(void) {
    Config config;
    
    // Set default values
    strcpy(config.app_name, "Advanced Calculator");
    strcpy(config.version, "1.0.0");
    config.debug_mode = 0;
    config.max_operations = 1000;
    
    log_info("Configuration loaded");
    return config;
}

void save_config(const Config *config) {
    FILE *file = fopen("config.cfg", "w");
    if (file != NULL) {
        fprintf(file, "app_name=%s\n", config->app_name);
        fprintf(file, "version=%s\n", config->version);
        fprintf(file, "debug_mode=%d\n", config->debug_mode);
        fprintf(file, "max_operations=%d\n", config->max_operations);
        fclose(file);
        log_info("Configuration saved to config.cfg");
    } else {
        log_error("Failed to save configuration");
    }
}

void print_config(const Config *config) {
    printf("Configuration:\n");
    printf("  App Name: %s\n", config->app_name);
    printf("  Version: %s\n", config->version);
    printf("  Debug Mode: %s\n", config->debug_mode ? "ON" : "OFF");
    printf("  Max Operations: %d\n", config->max_operations);
}

