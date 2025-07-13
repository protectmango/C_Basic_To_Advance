#ifndef LOGGER_H
#define LOGGER_H

// Logger levels
typedef enum {
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR
} LogLevel;

// Logger functions
void init_logger(void);
void set_log_level(LogLevel level);
void log_debug(const char *format, ...);
void log_info(const char *format, ...);
void log_warning(const char *format, ...);
void log_error(const char *format, ...);

#endif // LOGGER_H

