/*
** EPITECH PROJECT, 2025
** my_strcat
** File description:
** a function to concatenate two string
*/

#include <unistd.h>
#include "minishell.h"

void my_strcat(char *dest, char const *src)
{
    int index = 0;
    int len_str = my_strlen(dest);

    while (src[index] != '\0') {
        dest[index + len_str] = src[index];
        ++index;
    }
    dest[index + len_str] = '\0';
}
