/*
** EPITECH PROJECT, 2025
** free_list
** File description:
** a function to free a list
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

void free_list(env_t *env_cpy)
{
    if (env_cpy == NULL)
        return;
    free_list(env_cpy->next);
    free(env_cpy->key);
    free(env_cpy->value);
    free(env_cpy);
}
