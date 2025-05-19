/*
** EPITECH PROJECT, 2025
** remplace_var
** File description:
** a function to remplce the var by its value
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "minishell.h"

static char *remplace_tilde(char *arg, env_t *env_cpy)
{
    char *home_path = NULL;
    char *new_path = NULL;

    if (get_value(&env_cpy, &home_path, "HOME") == FAILURE)
        return NULL;
    new_path = make_path(home_path, arg + 1, NULL);
    return new_path;
}

static char *remplace_dollar(char *arg, env_t *env_cpy)
{
    char *env_value = NULL;
    char *new_value = NULL;

    if (get_value(&env_cpy, &env_value, arg + 1) == FAILURE)
        return NULL;
    if (my_strdup(&new_value, env_value) == FAILURE)
        return NULL;
    return new_value;
}

int remplace_var(char ***argv, env_t *env_cpy)
{
    char *new_arg = NULL;

    for (int i = 0; (*argv)[i] != NULL; ++i) {
        if ((*argv)[i][0] == '~')
            new_arg = remplace_tilde((*argv)[i], env_cpy);
        if ((*argv)[i][0] == '$') {
            new_arg = remplace_dollar((*argv)[i], env_cpy);
        } else {
            continue;
        }
        if (new_arg)
            (*argv)[i] = new_arg;
    }
    return SUCCESS;
}
