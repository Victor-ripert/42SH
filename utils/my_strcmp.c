/*
** EPITECH PROJECT, 2025
** my_strcmp
** File description:
** a function to compare two string
*/

#include <unistd.h>
#include "minishell.h"

int my_cmp(char const *str1, char const *str2)
{
    for (int i = 0; str1[i] != '\0'; i++) {
        if ((int) str1[i] != (int) str2[i]) {
            return (int) str1[i] - (int) str2[i];
        }
    }
    return 0;
}

int my_strcmp(char const *str1, char const *str2)
{
    int len_str1 = my_strlen(str1);
    int len_str2 = my_strlen(str2);

    if (len_str1 > len_str2)
        return 1;
    if (len_str2 > len_str1)
        return -1;
    return my_cmp(str1, str2);
}
