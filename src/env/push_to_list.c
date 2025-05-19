/*
** EPITECH PROJECT, 2024
** add
** File description:
** a function to add an object to the top of a linked list
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "minishell.h"

static int create_node(env_t **new_node, char const *key, char const *value)
{
    *new_node = (env_t *) malloc(sizeof(env_t));
    if (new_node == NULL)
        return FAILURE;
    if (my_strdup(&((*new_node)->key), key) == FAILURE) {
        free(new_node);
        return FAILURE;
    }
    if (my_strdup(&((*new_node)->value), value) == FAILURE) {
        free((*new_node)->key);
        free(new_node);
        return FAILURE;
    }
    (*new_node)->next = NULL;
    return SUCCESS;
}

int push_to_list(env_t **head, char const *key, char const *value)
{
    env_t *new_node = NULL;
    env_t *last_node = *head;

    if (create_node(&new_node, key, value) == FAILURE)
        return FAILURE;
    if (*head == NULL) {
        *head = new_node;
        return SUCCESS;
    }
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node->next = new_node;
    return SUCCESS;
}
