/*
** EPITECH PROJECT, 2025
** execute_commande
** File description:
** executes a comande
*/

#include <stddef.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "minishell.h"

static int count_nodes(env_t const *head)
{
    if (head == NULL) {
        return 0;
    }
    return 1 + count_nodes(head->next);
}

static int get_env_array(env_t *env_cpy, char ***env_cpy_array)
{
    int height = count_nodes(env_cpy);
    int width = 0;

    (*env_cpy_array) = (char **) malloc(sizeof(char *) * (height + 1));
    if ((*env_cpy_array) == NULL)
        return FAILURE;
    for (int i = 0; env_cpy != NULL; ++i) {
        width = my_strlen(env_cpy->key) + 1 + my_strlen(env_cpy->value);
        (*env_cpy_array)[i] = (char *) malloc(sizeof(char) * (width + 1));
        if ((*env_cpy_array)[i] == NULL) {
            free_word_array(*env_cpy_array);
            return FAILURE;
        }
        my_strcpy((*env_cpy_array)[i], env_cpy->key);
        my_strcat((*env_cpy_array)[i], "=");
        my_strcat((*env_cpy_array)[i], env_cpy->value);
        env_cpy = env_cpy->next;
    }
    (*env_cpy_array)[height] = NULL;
    return SUCCESS;
}

int execute(char const *path, char **argv, env_t *env_cpy)
{
    char **env_cpy_array = NULL;

    if (get_env_array(env_cpy, &env_cpy_array) == FAILURE)
        return FAILURE;
    execve(path, argv, env_cpy_array);
    exit(1);
}
