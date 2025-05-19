/*
** EPITECH PROJECT, 2025
** execute.h
** File description:
** a .h for execute
*/

#ifndef EXECUTE_H
    #define EXECUTE_H
    #include "list.h"

int execute(const char *path, char **argv, env_t *env_cpy);
int execute_builtin(char **argv, list_t *args, int index);
int execute_commande(char **argv, env_t *env_cpy);
int handle_execute(char *input, list_t *args);
int execute_binary(char **argv, env_t *env_cpy);
int remplace_var(char ***argv, env_t *env_cpy);
int handle_signal(int status);

#endif
