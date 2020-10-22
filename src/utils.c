#include <stddef.h>

size_t strlenk(const char *str, char k)
{
    size_t i;

    for (i = 0; str[i] != '\0' && str[i] != k; ++i);
    return i;
}

size_t countk(const char *buffer, size_t size, char k)
{
    size_t count = 0;

    for (size_t i = 0; i < size; ++i) {
        if (buffer[i] == k)
            ++count;
    }
    return count;
}