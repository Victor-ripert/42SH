/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** the minishell
*/

#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "minishell.h"

static int is_builtin(char const *str, int *index)
{
    for (int i = 0; DB_exec_func[i].key[0] != '\0'; ++i) {
        if (my_strcmp(DB_exec_func[i].key, str) == 0) {
            *index = i;
            return 1;
        }
    }
    return 0;
}

static bool is_binary(char const *str)
{
    int len = my_strlen(str);

    if (len < 3)
        return false;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '/')
            return true;
    }
    return false;
}

int handle_execute(char *input, list_t *args)
{
    int reval = SUCCESS;
    int index = 0;
    glob_t *glob_result = arg_globing(input, (*args->env_cpy));

    if (!glob_result)
        return FAILURE;
    if (handle_inhibitors(&glob_result->gl_pathv, args) == NULL)
        return FAILURE;
    if (is_builtin(glob_result->gl_pathv[0], &index)) {
        reval = execute_builtin(glob_result->gl_pathv, args, index);
    } else if (is_binary(glob_result->gl_pathv[0])) {
        reval = execute_binary(glob_result->gl_pathv, (*args->env_cpy));
    } else {
        reval = execute_commande(glob_result->gl_pathv, (*args->env_cpy));
    }
    globfree(glob_result);
    return reval;
}
