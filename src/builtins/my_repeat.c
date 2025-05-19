/*
** EPITECH PROJECT, 2025
** my_history
** File description:
** a function that repeats a function call a set amount of times
*/

#include <ctype.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include "list.h"
#include "minishell.h"
#include "utils.h"

static bool is_number(char *str)
{
    size_t size = strlen(str);

    for (size_t i = 0; i < size; ++i) {
        if (!isdigit(str[i]))
        return false;
    }
    return true;
}

int my_repeat(char **argv, list_t *args)
{
    int reval = SUCCESS;
    int len = array_len((char const **) argv);
    size_t nbr = 0;

    if (len < 3) {
        put_char("repeat: Too few arguments.\n", 2);
        return 1;
    }
    if (!is_number(argv[1])) {
        put_char("repeat: Badly formed number.\n", 2);
        return 1;
    }
    nbr = atoi(argv[1]);
    for (size_t i = 0; i < nbr; ++i) {
        reval = handle_execute(argv[2], args);
    }
    return reval;
}
