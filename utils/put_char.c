/*
** EPITECH PROJECT, 2025
** my_strcpy
** File description:
** a function to copy a string to an other one
*/

#include <unistd.h>
#include "minishell.h"

int put_char(char const *str, int const mode)
{
    int len = my_strlen(str);

    write(mode, str, len);
    return (mode == 2) ? FAILURE : SUCCESS;
}
