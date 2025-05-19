/*
** EPITECH PROJECT, 2025
** 42sh -> my_unalias
** File description:
** remove an alias from thes aliases list
*/

#include "minishell.h"
#include "alias.h"

int my_unalias(char **argv, list_t *args)
{
    size_t len = array_len((char const **) argv);

    if (argv == NULL || args == NULL || len != 2)
        return FAILURE;
    for (size_t i = 1; argv[i] != NULL; i++) {
        if (remove_alias(args->alias, argv[i]) == FAILURE)
            return FAILURE;
    }
    return SUCCESS;
}
