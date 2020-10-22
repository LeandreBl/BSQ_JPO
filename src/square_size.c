#include "bsq.h"

bool is_empty(const bsq_info_t *infos, size_t x, size_t y, size_t size)
{
    size_t i;
    size_t j;

    for (i = 0; i < size && i + x < lvector_size(infos->map); ++i) {
        for (j = 0; j < size && j + y < lvector_size(infos->map.arr[i]); ++j) {
            if (infos->map.arr[i + x].arr[j + y] == 'o')
                return false;
        }
    }
    return true;
}