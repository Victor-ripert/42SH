/*
** EPITECH PROJECT, 2025
** my_history
** File description:
** my_history
*/

#include <unistd.h>
#include <stdio.h>
#include "list.h"
#include "minishell.h"

int my_history(char **argv, list_t *args)
{
    history_t *temp = *(args->head);

    (void)(argv);
    while (temp->next != NULL)
        temp = temp->next;
    while (temp != NULL) {
        printf("%d  %s\n", temp->id, temp->command);
        temp = temp->prec;
    }
    return SUCCESS;
}
