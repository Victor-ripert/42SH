/*
** EPITECH PROJECT, 2025
** push_to_history
** File description:
** push_to_history
*/
#include <unistd.h>
#include <stdlib.h>
#include "history.h"
#include "utils.h"
#include "list.h"

char *my_strdup2(char *word)
{
    char *ret = malloc((my_strlen(word) + 1) * sizeof(char));
    int i = 0;

    if (!ret)
        return NULL;
    while (word[i] != '\0') {
        ret[i] = word[i];
        i++;
    }
    ret[i] = '\0';
    return ret;
}

void push_to_history(history_t **head, char *command)
{
    history_t *test = malloc(sizeof(history_t));
    char *dest = NULL;

    if (!test)
        return;
    test->next = *head;
    test->prec = NULL;
    my_strdup(&dest, command);
    test->command = dest;
    if (*head)
        (*head)->prec = test;
    if (*head) {
        test->id = (*head)->id + 1;
    } else {
        test->id = 0;
    }
    *head = test;
    return;
}
