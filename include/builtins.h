/*
** EPITECH PROJECT, 2025
** builtin.h
** File description:
** a .h for builtin
*/

#ifndef BUILTINS_H
    #define BUILTINS_H
    #include "list.h"
    #include <stddef.h>

int my_history(char **argv, list_t *args);
int my_which(char **argv, list_t *args);
int my_where(char **argv, list_t *args);
int my_echo(char **argv, list_t *args);
int my_env(char **argv, list_t *args);
int my_setenv(char **argv, list_t *args);
int my_unsetenv(char **argv, list_t *args);
int my_cd(char **argv, list_t *args);
int my_alias(char **argv, list_t *args);
int my_unalias(char **argv, list_t *args);
int my_repeat(char **argv, list_t *args);
char **handle_inhibitors(char ***argv, list_t *args);

typedef struct func_point_s {
    char *key;
    int (*func)(char **argv, list_t *args);
} func_point_t;

static const func_point_t DB_exec_func[] = {
    {"history", my_history},
    {"env", my_env},
    {"which", my_which},
    {"where", my_where},
    {"setenv", my_setenv},
    {"unsetenv", my_unsetenv},
    {"cd", my_cd},
    {"alias", my_alias},
    {"unalias", my_unalias},
    {"repeat", my_repeat},
    {"\0", NULL}
};

#endif
