/*
** EPITECH PROJECT, 2025
** 42Sh -> remove_alias.c
** File description:
** remove aliases from the alias_t linked list
*/

#include <stdlib.h>
#include "minishell.h"
#include "alias.h"

void free_node(alias_t *node)
{
    free(node->alias_name);
    free(node->alias_command);
    free(node);
}

int remove_alias(alias_t **head, char *alias_name)
{
    alias_t *node = search_alias(head, alias_name);

    if (head == NULL || alias_name == NULL)
        return FAILURE;
    if (node == NULL)
        return SUCCESS;
    if (node->previous == NULL) {
        (*head) = node->next;
        free_node(node);
        return SUCCESS;
    }
    node->previous->next = node->next;
    node->next->previous = node->previous;
    free_node(node);
    return SUCCESS;
}
