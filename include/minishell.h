/*
** EPITECH PROJECT, 2025
** minishell.h
** File description:
** a .h for 42sh
*/

#ifndef MINISHELL1_H_
    #define MINISHELL1_H_
    #include <glob.h>
    #define SUCCESS 0
    #define FAILURE 2
    #define UNUSED __attribute__((unused))
    #define STDIN 0
    #define NOTHING 30
    #define EQUALITY 0
    #define SPECIFIC_ERROR 1
    #define INHIBITORS '`'
    #define CHUNK_SIZE 250
    #define ERROR -1
    #define STDOUT 1
    #define FIRST_ARG 1
    #include <string.h>
    #include "env.h"
    #include "builtins.h"
    #include "redirections.h"
    #include "jobs.h"
    #include "execute.h"
    #include "utils.h"
    #include "alias.h"
    #include "list.h"

char *handle_parentheses(char *str, int *reval, list_t *args);
glob_t *arg_globing(char *input, env_t *env_cpy);
int minishell(list_t *args);

#endif
