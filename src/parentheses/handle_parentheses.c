/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** handle_parentheses
*/

#include <stdio.h>
#include <stdlib.h>
#include "minishell.h"

static char *extract_command(char *str)
{
    char *begin = strchr(str, '(');
    char *end = strchr(str, ')');
    char *new_str = NULL;

    if (!begin || !end)
        return NULL;
    new_str = malloc((end - begin) * sizeof(char));
    if (!new_str)
        return NULL;
    new_str = strncpy(new_str, begin + 1, (end - begin - 1));
    new_str[end - begin - 1] = '\0';
    return new_str;
}

static int check_semicolons(char *str)
{
    if (*str != ' ') {
        if (*str == ';')
        return SUCCESS;
        else
            return FAILURE;
    }
    return NOTHING;
}

void handle_semicolons(char *str, char **begin, char **end)
{
    *begin = strchr(str, '(');
    *end = strchr(str, ')');
    if (!begin || !end)
        return;
    for (char *pos = *begin; pos != str; pos--) {
        if (check_semicolons(pos) == SUCCESS && pos != *begin)
            *begin = pos;
        if (check_semicolons(pos) == FAILURE && pos != *begin)
            break;
    }
    *end = *end + 1;
    for (char *pos = *end; *pos != '\0'; pos++) {
        if (check_semicolons(pos) == SUCCESS)
            *end = pos + 1;
        if (check_semicolons(pos) != NOTHING)
            break;
    }
}

static char *rewrite_str(char *str)
{
    char *begin = NULL;
    char *end = NULL;
    char *begin_part = NULL;

    handle_semicolons(str, &begin, &end);
    if (((begin == str) && (str[strlen(str) - 2] == *end)) || !begin || !end)
        return NULL;
    if ((begin == str))
        begin_part = strdup("");
    else {
        begin_part = malloc((begin - str + 1) * sizeof(char));
        if (begin_part == NULL)
            return NULL;
        begin_part = strncpy(begin_part, str, begin - str);
    }
    if (!begin_part || !end)
        return NULL;
    begin_part[begin - str] = '\0';
    return my_strcat_malloc(begin_part, end);
}

char *create_input(char *command)
{
    char *input = malloc(strlen("echo  | ./42sh")
    + strlen(command) + 1 * sizeof(char));

    if (!command || !input)
        return NULL;
    input = strcpy(input, "echo ");
    if (!input)
        return NULL;
    input = strcat(input, command);
    if (!input)
        return NULL;
    input = strcat(input, " | ./42sh");
    return input;
}

char *handle_parentheses(char *str, int *reval, list_t *args)
{
    char *new_str = NULL;
    char *command = NULL;
    char *input = NULL;

    if (strchr(str, '(') == NULL)
        return str;
    command = extract_command(str);
    new_str = rewrite_str(str);
    input = create_input(command);
    if (!command || !input)
        return NULL;
    *reval = ll_parsor(input, args);
    free(input);
    free(command);
    return new_str;
}
