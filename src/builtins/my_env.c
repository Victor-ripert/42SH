/*
** EPITECH PROJECT, 2025
** my_env
** File description:
** a function to display the env
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "minishell.h"

int my_env(char **argv, list_t *args)
{
    env_t *tmp = NULL;

    if (argv == NULL)
        return FAILURE;
    tmp = (*args->env_cpy);
    while (tmp != NULL) {
        put_char(tmp->key, 1);
        write(1, "=", 1);
        put_char(tmp->value, 1);
        write(1, "\n", 1);
        tmp = tmp->next;
    }
    return SUCCESS;
}
