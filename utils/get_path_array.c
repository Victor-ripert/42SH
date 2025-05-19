/*
** EPITECH PROJECT, 2025
** get_path_array
** File description:
** get_path_array
*/

#include "minishell.h"

char **get_path_array(env_t const *env_cpy)
{
    char *key = NULL;
    char *value = NULL;
    char **array = NULL;

    while (env_cpy != NULL) {
        key = env_cpy->key;
        value = env_cpy->value;
        if (my_strcmp(key, "PATH")) {
            env_cpy = env_cpy->next;
            continue;
        }
        if (str_to_word_array(value, &array, ":'") == FAILURE)
            return NULL;
        return array;
    }
    return NULL;
}
