#include <stdio.h>

#include "bsq.h"
#include "arguments.h"

static const arg_handler(bsq_info_t) ARG_HANDLERS[] = {
    {
        "-c",
        "--color",
        &color_handler,
        "display the obstacles and the square in color",
        NULL,
        false
    },
    {
        "-s",
        "--spy",
        &spy_handler,
        "display each iteration of the program",
        NULL,
        false
    },
    {
        "-i",
        "--input",
        &input_handler,
        "the path of the file that contains the map",
        "FILEPATH",
        true
    },
    {
        "-h",
        "--help",
        NULL,
        "display this help",
        NULL,
        false
    }
};

int main(int ac, const char *av[])
{
    bsq_info_t infos = {0};
    opts_handler_t handler;

    opts_create(&handler, av[0], &ARG_HANDLERS, sizeof(ARG_HANDLERS) / sizeof(*ARG_HANDLERS));
    if (opts_get(&handler, ac, av, &infos) == -1)
        return -1;
    if (infos.map_filepath == NULL) {
        fprintf(stderr, "Invalid use, use '%s --help' to show usage.\n", av[0]);
        return -1;
    }
    if (load_map(&infos) == -1) {
        fprintf(stderr, "Failed to load '%s' map.\n", infos.map_filepath);
        return -1;
    }
    run_through(&infos);
    lvector_destroy(infos.map);
    return 0;
}