/*
** EPITECH PROJECT, 2025
** env_uitls
** File description:
** a set of function for the env
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "minishell.h"

int change_value(env_t **curr, char *str)
{
    int len = my_strlen(str);

    free((*curr)->value);
    (*curr)->value = (char *) malloc(sizeof(char) * (len + 1));
    if ((*curr)->value == NULL)
        return FAILURE;
    my_strcpy((*curr)->value, str);
    return SUCCESS;
}

static int cat_value(env_t **curr, char *path)
{
    char *cwd = NULL;
    int len = 0;

    my_strdup(&cwd, (*curr)->value);
    if (cwd == NULL)
        return FAILURE;
    len = my_strlen(cwd) + 1 + my_strlen(path);
    (*curr)->value = (char *) malloc(sizeof(char) * (len + 1));
    if ((*curr)->value == NULL) {
        free(cwd);
        return FAILURE;
    }
    my_strcpy((*curr)->value, cwd);
    my_strcat((*curr)->value, "/");
    my_strcat((*curr)->value, path);
    ((*curr)->value)[len] = '\0';
    free(cwd);
    return SUCCESS;
}

int update_value(env_t **curr, char *value)
{
    int reval = 0;

    if (value[0] != '/') {
        reval = cat_value(curr, value);
    } else {
        reval = change_value(curr, value);
    }
    return reval;
}

int set_value(env_t **env_cpy, char *value, char *key)
{
    for (env_t *curr = *env_cpy; curr != NULL; curr = curr->next) {
        if (!(my_strcmp(key, curr->key) == 0))
            continue;
        if (update_value(&curr, value) == FAILURE)
            return FAILURE;
        return SUCCESS;
    }
    return FAILURE;
}

int get_value(env_t **env_cpy, char **value, char *key)
{
    for (env_t *curr = *env_cpy; curr != NULL; curr = curr->next) {
        if (!(my_strcmp(key, curr->key) == 0))
            continue;
        (*value) = curr->value;
        return SUCCESS;
    }
    return FAILURE;
}
