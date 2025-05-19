/*
** EPITECH PROJECT, 2025
** 42sh -> reconcat_args.c
** File description:
** transform an array of word to a string
*/

#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

ssize_t find_array_global_size(char **array)
{
    ssize_t size = 0;

    if (array == NULL)
        return -1;
    for (size_t i = 0; array[i] != NULL; i++) {
        size += strlen(array[i]) + 1;
    }
    return size;
}

char *reconcat_args(char **array, char delim)
{
    char *str = NULL;
    ssize_t size = find_array_global_size(array);
    size_t pos = 0;

    if (array == NULL)
        return NULL;
    str = malloc(sizeof(char) * size + 1);
    for (size_t i = 2; array[i] != NULL; i++) {
        for (size_t j = 0; array[i][j] != '\0'; j++) {
            str[pos] = array[i][j];
            pos++;
        }
        str[pos] = delim;
        pos++;
    }
    str[pos] = '\0';
    return str;
}
