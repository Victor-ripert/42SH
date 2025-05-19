/*
** EPITECH PROJECT, 2025
** trim_spaces
** File description:
** a function to remove the spaces at the exetemites of a string
*/

#include <string.h>

char *trim_spaces(char *str)
{
    char *end = str + strlen(str) - 1;

    while (*str == ' ')
        str++;
    while (*end == ' ')
        end--;
    *(end + 1) = '\0';
    return str;
}
