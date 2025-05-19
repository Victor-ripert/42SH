/*
** EPITECH PROJECT, 2025
** 42SH -> my_alias.c
** File description:
** reproduce the alias function from tcsh
*/

#include "minishell.h"
#include "alias.h"

int my_alias(char **argv, list_t *args)
{
    size_t len = array_len((char const **) argv);

    if (argv == NULL || args == NULL || len < 2)
        return FAILURE;
    return add_alias(args->alias, argv[1], argv);
}
