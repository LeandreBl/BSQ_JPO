#ifndef BSQ_H_
#define BSQ_H_

#include <sys/stat.h>
#include <stdbool.h>

#include "lvector.h"

enum BSQ_FLAGS {
    DEFAULT = 0,
    COLOR = 1 << 0,
    SPY = 1 << 1,
};

typedef struct bsq_info_s {
    const char *map_filepath;
    struct stat file_stats;
    lvector(lvector(char)) map;
    int flags;
} bsq_info_t;

int color_handler(bsq_info_t *infos, const char *args[]);
int spy_handler(bsq_info_t *infos, const char *args[]);
int input_handler(bsq_info_t *infos, const char *args[]);

int load_map(bsq_info_t *infos);
void display_map(const bsq_info_t *infos, size_t x, size_t y, size_t size);
bool is_empty(const bsq_info_t *infos, size_t x, size_t y, size_t size);
void run_through(const bsq_info_t *infos);

size_t strlenk(const char *str, char k);
size_t countk(const char *buffer, size_t size, char k);

#endif /* !BSQ_H_ */