#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include "logger.h"

static LogLevel current_log_level = LOG_INFO;

void init_logger(void) {
    printf("[LOGGER] Logger initialized\n");
}

void set_log_level(LogLevel level) {
    current_log_level = level;
}

static void log_message(LogLevel level, const char *level_str, const char *format, va_list args) {
    if (level < current_log_level) {
        return;
    }
    
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    
    printf("[%02d:%02d:%02d] [%s] ", 
           tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec, level_str);
    vprintf(format, args);
    printf("\n");
}

void log_debug(const char *format, ...) {
    va_list args;
    va_start(args, format);
    log_message(LOG_DEBUG, "DEBUG", format, args);
    va_end(args);
}

void log_info(const char *format, ...) {
    va_list args;
    va_start(args, format);
    log_message(LOG_INFO, "INFO", format, args);
    va_end(args);
}

void log_warning(const char *format, ...) {
    va_list args;
    va_start(args, format);
    log_message(LOG_WARNING, "WARN", format, args);
    va_end(args);
}

void log_error(const char *format, ...) {
    va_list args;
    va_start(args, format);
    log_message(LOG_ERROR, "ERROR", format, args);
    va_end(args);
}

