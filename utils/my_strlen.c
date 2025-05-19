/*
** EPITECH PROJECT, 2025
** my_strlen
** File description:
** a function to get the leght of a string
*/

#include <unistd.h>
#include "minishell.h"

int my_strlen(char const *str)
{
    int len = 0;

    if (str == NULL)
        return 0;
    while (str[len] != '\0') {
        ++len;
    }
    return len;
}
