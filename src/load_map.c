#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "bsq.h"

static int load_file(char **pbuffer, const bsq_info_t *infos)
{
    int fd;

    fd = open(infos->map_filepath, O_RDONLY);
    if (fd == -1) {
        return -1;
    }
    *pbuffer = malloc(sizeof(char) * (infos->file_stats.st_size + 1));
    if (*pbuffer == NULL
        || read(fd, *pbuffer, infos->file_stats.st_size) != infos->file_stats.st_size) {
        close(fd);
        return -1;
    }
    (*pbuffer)[infos->file_stats.st_size] = 0;
    close(fd);
    return 0;
}

static int emplace_string(lvector(char) *v, const char *buffer, size_t len)
{
    lvector_create(*v, len, NULL);
    memcpy(lvector_data(*v), buffer, len);
    v->len = len;
    return 0;
}

static int add_each_lines(bsq_info_t *infos, const char *buffer, size_t lines)
{
    size_t i = 0;
    size_t len;

    for (; lines > 0; --lines) {
        len = strlenk(buffer + i, '\n');
        lvector_emplace_back(infos->map, emplace_string, buffer + i, len);
        i += len + 1;
    }
    return 0;
}

static void destroy_vector(void *vector)
{
    lvector(char) *v = vector;
    lvector_destroy(*v);
}

int load_map(bsq_info_t *infos)
{
    char *buffer;
    size_t lines;

    if (load_file(&buffer, infos) == -1) {
        return -1;
    }
    lines = countk(buffer, infos->file_stats.st_size, '\n');
    if (buffer[infos->file_stats.st_size - 1] != '\n')
        ++lines;
    lvector_create(infos->map, lines, destroy_vector);
    if (add_each_lines(infos, buffer, lines) == -1) {
        free(buffer);
        return -1;
    }
    lvector_erase(infos->map, 0);
    free(buffer);
    return 0;
}