/*
** EPITECH PROJECT, 2025
** arg_globing
** File description:
** a function to glob the args of a commande
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <glob.h>
#include "minishell.h"

int fill_args(char **argv, glob_t *glob_result)
{
    int flag = GLOB_NOCHECK;

    for (size_t i = 0; argv[i] != NULL; ++i) {
        flag = (i == 0) ? flag : flag | GLOB_APPEND;
        if (glob(argv[i], flag,
            NULL, glob_result) != SUCCESS) {
            free_word_array(argv);
            globfree(glob_result);
            return FAILURE;
        }
    }
    return SUCCESS;
}

glob_t *arg_globing(char *input, env_t *env_cpy)
{
    char **argv = NULL;
    glob_t *glob_result = NULL;

    if (str_to_word_array(input, &argv, " \t") == FAILURE)
        return NULL;
    if (remplace_var(&argv, env_cpy) == FAILURE)
        return NULL;
    glob_result = calloc(1, sizeof(glob_t));
    if (!glob_result)
        return NULL;
    if (fill_args(argv, glob_result) == FAILURE)
        return NULL;
    free_word_array(argv);
    return glob_result;
}
