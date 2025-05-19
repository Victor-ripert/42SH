/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** my_which
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include "list.h"
#include "minishell.h"

static int check_path(char **array, char **path,
    char const *command)
{
    for (int i = 0; array[i] != NULL; ++i) {
        *path = make_path(array[i], command, "/");
        if (!(*path))
            return FAILURE;
        if (!access(*path, X_OK)) {
            printf("%s\n", *path);
            free(*path);
            return SUCCESS;
        }
        free(*path);
        *path = NULL;
    }
    fprintf(stderr, "%s: Command not found.\n", command);
    return FAILURE;
}

int my_which(char **argv, list_t *args)
{
    char *path = NULL;
    char **array = NULL;

    if (array_len((char const **) argv) != 2)
        return FAILURE;
    array = get_path_array(*args->env_cpy);
    if (!array)
        return FAILURE;
    if (check_path(array, &path, argv[1]) == FAILURE) {
        free_word_array(array);
        return FAILURE;
    }
    return SUCCESS;
}
