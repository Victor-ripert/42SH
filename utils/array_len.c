/*
** EPITECH PROJECT, 2025
** array len
** File description:
** a function to get the len of an array
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

int array_len(char const **array)
{
    int len = 0;

    while (array[len] != NULL) {
        ++len;
    }
    return len;
}
