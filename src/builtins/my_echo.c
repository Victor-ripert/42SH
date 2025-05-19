/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** my_echo
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
#include "minishell.h"

static char *find_variable(env_t const *env_cpy,
    char const *variable_name)
{
    while (env_cpy != NULL) {
        if (strcmp(variable_name, env_cpy->key) == EQUALITY)
            return env_cpy->value;
        env_cpy = env_cpy->next;
    }
    return NULL;
}

int my_echo(char **argv, list_t *args)
{
    char *value = NULL;

    if (argv[FIRST_ARG] == NULL)
        return execute_commande(argv, *args->env_cpy);
    if (argv[FIRST_ARG][0] != '$')
        return execute_commande(argv, *args->env_cpy);
    value = find_variable(*args->env_cpy, argv[FIRST_ARG] + 1);
    if (value == NULL) {
        put_char(argv[FIRST_ARG], FAILURE);
        put_char(": Undefined variable.\n", FAILURE);
        return FAILURE;
    }
    free(argv[FIRST_ARG]);
    argv[FIRST_ARG] = strdup(value);
    if (argv[FIRST_ARG] == NULL)
        return FAILURE;
    return execute_commande(argv, *args->env_cpy);
}
