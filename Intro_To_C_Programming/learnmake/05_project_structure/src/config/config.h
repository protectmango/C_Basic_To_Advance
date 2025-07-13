#ifndef CONFIG_H
#define CONFIG_H

typedef struct {
    char app_name[64];
    char version[16];
    int debug_mode;
    int max_operations;
} Config;

Config load_config(void);
void save_config(const Config *config);
void print_config(const Config *config);

#endif // CONFIG_H

