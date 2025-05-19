/*
** EPITECH PROJECT, 2025
** 42SH -> search_alias.c
** File description:
** search for a alias in the linked_list
*/

#include <string.h>
#include "minishell.h"
#include "alias.h"

alias_t *search_alias(alias_t **head, char *alias_name)
{
    alias_t *tmp = NULL;

    if (head == NULL || alias_name == NULL)
        return NULL;
    tmp = (*head);
    while (tmp != NULL) {
        if (strcmp(alias_name, tmp->alias_name) == SUCCESS)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}
