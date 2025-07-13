#include <stdio.h>
#include "file_ops.h"

void create_sample_file(void) {
    FILE *file = fopen("sample.txt", "w");
    if (file != NULL) {
        fprintf(file, "This file was created by the advanced Makefile demo!\n");
        fprintf(file, "Demonstrating file operations in C.\n");
        fprintf(file, "Build systems are powerful tools.\n");
        fclose(file);
        printf("Created sample.txt\n");
    } else {
        printf("Error creating file\n");
    }
}

void read_sample_file(void) {
    FILE *file = fopen("sample.txt", "r");
    if (file != NULL) {
        printf("Contents of sample.txt:\n");
        char line[256];
        while (fgets(line, sizeof(line), file) != NULL) {
            printf("  %s", line);
        }
        fclose(file);
    } else {
        printf("Error reading file\n");
    }
}

int file_exists(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        fclose(file);
        return 1;
    }
    return 0;
}

