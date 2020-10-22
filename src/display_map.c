#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

#include "bsq.h"
#include "colors.h"

static const char *MAT[] = {
    ['.'] = WHITE "." RESET,
    ['o'] = RED "o" RESET,
    ['x'] = BOLDCYAN "x" RESET
};

static bool match_position(size_t i, size_t j, size_t x, size_t y, size_t size)
{
    return i >= x && i < x + size && j >= y && j < y + size;
}

void display_map(const bsq_info_t *infos, size_t x, size_t y, size_t size)
{
    int idx;

    lvector_for(i, infos->map) {
        if (infos->flags & COLOR) {
            lvector_for(j, infos->map.arr[i]) {
                idx = (infos->flags & SPY && match_position(i, j, x, y, size)) ? 'x' : infos->map.arr[i].arr[j];
                printf("%s", MAT[idx]);
            }
            printf("\n");
        }
        else if (infos->flags & SPY) {
            lvector_for(j, infos->map.arr[i]) {
                printf("%c", match_position(i, j, x, y, size) ? 'x' : infos->map.arr[i].arr[j]);
            }
            printf("\n");
        }
        else {
            printf("%.*s\n", (int)lvector_size(infos->map.arr[i]), lvector_data(infos->map.arr[i]));
        }
    }
}