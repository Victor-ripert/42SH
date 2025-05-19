/*
** EPITECH PROJECT, 2025
** free_history
** File description:
** free_history
*/

#include <stdlib.h>
#include "list.h"

void free_history(history_t *head)
{
    history_t *temp = head;

    if (temp == NULL)
        return;
    if (temp->next != NULL)
        free_history((temp->next));
    free(temp->command);
    free(temp);
    return;
}
