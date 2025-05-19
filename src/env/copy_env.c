/*
** EPITECH PROJECT, 2025
** copy_env
** File description:
** a function to copy the env
*/

#include <stdlib.h>
#include "minishell.h"
#include <stdio.h>

static int get_len_key(char const *str)
{
    int len_key = 0;

    while (str[len_key] != '=')
        ++len_key;
    return len_key;
}

static int get_strings(char **key, char **value, char const *str)
{
    int len_key = get_len_key(str);
    int len_value = my_strlen(str) - len_key - 1;

    *key = (char *) malloc(sizeof(char) * (len_key + 1));
    if (*key == NULL)
        return FAILURE;
    for (int i = 0; i < len_key; ++i)
        (*key)[i] = str[i];
    (*key)[len_key] = '\0';
    *value = (char *) malloc(sizeof(char) * (len_value + 1));
    if (*value == NULL) {
        free(key);
        return FAILURE;
    }
    for (int i = 0; i < len_value; ++i)
        (*value)[i] = str[i + len_key + 1];
    (*value)[len_value] = '\0';
    return SUCCESS;
}

int copy_env(char const **env, env_t **env_cpy)
{
    char *key = NULL;
    char *value = NULL;

    for (int i = 0; env[i] != NULL; ++i) {
        if (get_strings(&key, &value, env[i]) == FAILURE)
            return FAILURE;
        if (push_to_list(env_cpy, key, value) == FAILURE) {
            free(key);
            free(value);
            return FAILURE;
        }
        free(key);
        free(value);
    }
    return SUCCESS;
}
