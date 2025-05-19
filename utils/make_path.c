/*
** EPITECH PROJECT, 2025
** make_path
** File description:
** create a path
*/

#include <stdlib.h>
#include "minishell.h"

char *make_path(char const *path1, char const *path2, char const *sep)
{
    int len = my_strlen(path1) + my_strlen(path2);
    char *filepath = (char *) malloc(sizeof(char) * (len + 1));

    if (!filepath)
        return NULL;
    my_strcpy(filepath, path1);
    if (sep)
        my_strcat(filepath, sep);
    my_strcat(filepath, path2);
    return filepath;
}
