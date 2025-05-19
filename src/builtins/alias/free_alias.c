/*
** EPITECH PROJECT, 2025
** 42sh -> free_list.c
** File description:
** free the list
*/

#include <stdlib.h>
#include "alias.h"

void free_alias(alias_t **list)
{
    alias_t *tmp = NULL;
    alias_t *previous = NULL;

    if (list == NULL)
        return;
    if ((*list) == NULL)
        return;
    tmp = (*list);
    while (tmp != NULL) {
        previous = tmp;
        tmp = tmp->next;
        free(previous);
    }
}
