#include "bsq.h"
#include "colors.h"

void run_through(const bsq_info_t *infos)
{
    size_t max_size = 0;
    size_t max_i;
    size_t max_j;

    lvector_for(i, infos->map) {
        lvector_for(j, infos->map.arr[i]) {
            for (size_t s = 0; s < lvector_size(infos->map) - i && s < lvector_size(infos->map.arr[i]) - j; ++s) {
                if (is_empty(infos, i, j, s) == true) {
                    if (s > max_size) {
                        max_size = s;
                        max_i = i;
                        max_j = j;
                    }
                } else {
                    break;
                }
                usleep(50000);
                printf("%s\n", CLEARTOP);
                display_map(infos, i, j, s);
            }
        }
    }
    display_map(infos, max_i, max_j, max_size);
}