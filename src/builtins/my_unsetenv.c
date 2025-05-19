/*
** EPITECH PROJECT, 2025
** my_unsetenv
** File description:
** a function to unset a variable in the env
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "minishell.h"

static void free_node(env_t *node)
{
    free(node->key);
    free(node->value);
    free(node);
}

static void delet_node(env_t **head, env_t **curr, env_t **prev)
{
    if (*prev == NULL) {
        *head = (*curr)->next;
        free_node(*curr);
        *curr = *head;
    } else {
        (*prev)->next = (*curr)->next;
        free_node(*curr);
        *curr = *prev;
    }
}

static void delete_in_list(env_t **head, char *key)
{
    env_t *prev = NULL;

    for (env_t *curr = *head; curr != NULL; curr = curr->next) {
        if (my_strcmp(key, curr->key) == 0) {
            delet_node(head, &curr, &prev);
        } else {
            prev = curr;
        }
    }
}

int my_unsetenv(char **argv, list_t *args)
{
    int len = array_len((char const **) argv);

    if (!(len == 1 || len == 2))
        return SUCCESS;
    if (len == 1) {
        put_char("unsetenv: Too few arguments.\n", 2);
        return 1;
    }
    delete_in_list(args->env_cpy, argv[1]);
    return SUCCESS;
}
