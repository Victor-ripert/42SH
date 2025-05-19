/*
** EPITECH PROJECT, 2025
** my_strdup
** File description:
** a function to copy a string
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "minishell.h"

int my_strdup(char **dest, char const *send)
{
    int len = my_strlen(send);

    *dest = (char *) malloc(sizeof(char) * (len + 1));
    if (*dest == NULL)
        return FAILURE;
    my_strcpy(*dest, send);
    return SUCCESS;
}
