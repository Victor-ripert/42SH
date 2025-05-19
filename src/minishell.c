/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** the minishell
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "minishell.h"
#include "history.h"

static void remove_new_line(char *input)
{
    size_t len = strlen(input);

    if (len == 0)
        return;
    if (input[len - 1] == '\n')
        input[len - 1] = '\0';
    return;
}

static void free_data(char *input, list_t *list)
{
    free(input);
    free_history(*(list->head));
    free_list((*list->env_cpy));
    free_alias(list->alias);
    free(list);
}

void balise(void)
{
    if (isatty(0))
        put_char("$> ", 1);
}

void exit_msg(void)
{
    if (isatty(0))
        put_char("exit\n", 1);
}

int check_echo(char *input, int reval)
{
    if (strcmp(input, "echo $?") == EQUALITY) {
        printf("%i\n", reval);
        return SUCCESS;
    }
    return FAILURE;
}

int minishell(list_t *args)
{
    char *input = NULL;
    size_t size = 0;
    ssize_t nread;
    int reval = 0;

    while (1) {
        balise();
        nread = getline(&input, &size, stdin);
        remove_new_line(input);
        if (nread == -1 || !my_strcmp("exit", input))
            break;
        if (check_echo(input, reval) == SUCCESS)
            continue;
        push_to_history(args->head, input);
        input = handle_parentheses(input, &reval, args);
        reval = ll_parsor(input, args);
    }
    exit_msg();
    free_data(input, args);
    return nread == ERROR ? reval : SUCCESS;
}
