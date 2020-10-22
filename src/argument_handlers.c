#include <sys/stat.h>
#include <stdio.h>

#include "bsq.h"

int color_handler(bsq_info_t *infos, const char *args[])
{
    (void)args;
    infos->flags |= COLOR;
    return 0;
}

int spy_handler(bsq_info_t *infos, const char *args[])
{
    (void)args;
    infos->flags |= SPY;
    return 0;
}

int input_handler(bsq_info_t *infos, const char *args[])
{
    if (infos->map_filepath != NULL) {
        fprintf(stderr, "'%s' flag already specified with \"%s\".\n", args[0], infos->map_filepath);
        return -1;
    }
    if (stat(args[1], &infos->file_stats) == -1) {
        fprintf(stderr, "File \"%s\" does not exist.\n", args[1]);
        return -1;
    }
    if (!S_ISREG(infos->file_stats.st_mode)) {
        fprintf(stderr, "File \"%s\" is not a regular file.\n", args[1]);
        return -1;
    }
    infos->map_filepath = args[1];
    return 0;
}