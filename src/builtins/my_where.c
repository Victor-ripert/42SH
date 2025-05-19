/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** my_which
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"
#include "minishell.h"

static int check_path(char **array,
    char **path, char const *command)
{
    bool is_found = false;

    for (int i = 0; array[i] != NULL; ++i) {
        *path = make_path(array[i], command, "/");
        if (!(*path))
            return FAILURE;
        if (!access(*path, X_OK)) {
            printf("%s\n", *path);
            is_found = true;
        }
        free(*path);
        *path = NULL;
    }
    if (!is_found) {
        fprintf(stderr, "%s: Command not found.\n", command);
        return FAILURE;
    }
    return SUCCESS;
}

int my_where(char **argv, list_t *args)
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
