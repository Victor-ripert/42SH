/*
** EPITECH PROJECT, 2025
** my_setenv
** File description:
** a function to set a variable in the env
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "minishell.h"

static int is_valid(char *str)
{
    if (!((str[0] >= 'a' && str[0] <= 'z') ||
        (str[0] >= 'A' && str[0] <= 'Z') ||
        (str[0] == '_'))) {
        put_char("setenv: Variable name must begin with a letter.\n", 2);
        return 1;
    }
    for (int i = 0; str[i] != '\0'; ++i) {
        if (!((str[i] >= '0' && str[i] <= '9') ||
            (str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] == '_'))) {
            put_char("setenv: Variable name must contain ", 2);
            put_char("alphanumeric characters.\n", 2);
            return 1;
        }
    }
    return SUCCESS;
}

static int add_key_value(env_t **env_cpy, char **argv, int len)
{
    if (len == 3) {
        if (push_to_list(env_cpy, argv[1], argv[2]) == FAILURE)
            return FAILURE;
    } else {
        if (push_to_list(env_cpy, argv[1], "") == FAILURE)
            return FAILURE;
    }
    return SUCCESS;
}

static int add_to_env(env_t **env_cpy, char **argv, int len)
{
    for (env_t *curr = *env_cpy; curr != NULL; curr = curr->next) {
        if (!(my_strcmp(argv[1], curr->key) == 0))
            continue;
        if (len == 3)
            return change_value(&curr, argv[2]);
        return SUCCESS;
    }
    if (add_key_value(env_cpy, argv, len) == FAILURE) {
        return FAILURE;
    }
    return SUCCESS;
}

int my_setenv(char **argv, list_t *args)
{
    int len = array_len((char const **) argv);

    if (len > 3) {
        put_char("setenv: Too many arguments.\n", 2);
        return 1;
    }
    if (len == 1)
        return my_env(argv, args);
    if (is_valid(argv[1]) == 1)
        return 1;
    if (add_to_env(args->env_cpy, argv, len) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
