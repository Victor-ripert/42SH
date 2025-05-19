/*
** EPITECH PROJECT, 2025
** history.h
** File description:
** history.h
*/

#ifndef HISTORY_H_
    #define HISTORY_H_

typedef struct history_s {
    struct history_s *next;
    struct history_s *prec;
    int id;
    char *command;
} history_t;

void push_to_history(history_t **head, char *command);
void free_history(history_t *head);

#endif //HISTORY_H
