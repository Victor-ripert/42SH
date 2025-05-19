/*
** EPITECH PROJECT, 2025
** main
** File description:
** a main function
*/

#include <signal.h>
#include <stddef.h>
#include <stdlib.h>
#include "minishell.h"
#include "history.h"

int main(int const argc, UNUSED char const **argv,
    char const **env)
{
    env_t *env_cpy = NULL;
    alias_t *alias = NULL;
    history_t *head = NULL;
    list_t *args = NULL;

    signal(SIGINT, SIG_IGN);
    if (argc != 1)
        return FAILURE;
    if (!*env)
        return FAILURE;
    if (copy_env(env, &env_cpy) == FAILURE)
        return FAILURE;
    args = malloc(sizeof(list_t));
    if (args == NULL)
        return FAILURE;
    args->head = &head;
    args->alias = &alias;
    args->env_cpy = &env_cpy;
    return minishell(args);
}
