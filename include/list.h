/*
** EPITECH PROJECT, 2025
** minishell.h
** File description:
** a .h for 42sh
*/

#ifndef LIST_H
    #define LIST_H
    #include "env.h"
    #include "alias.h"
    #include "history.h"

typedef struct list_t {
    env_t **env_cpy;
    alias_t **alias;
    history_t **head;
} list_t;

#endif /* LIST_H */
