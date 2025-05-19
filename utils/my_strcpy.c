/*
** EPITECH PROJECT, 2025
** my_strcpy
** File description:
** a function to copy a string to an other one
*/

#include <unistd.h>
#include "minishell.h"

void my_strcpy(char *dest, char const *send)
{
    int i = 0;

    while (send[i] != '\0') {
        (dest)[i] = send[i];
        ++i;
    }
    (dest)[i] = '\0';
}
