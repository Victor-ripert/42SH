/*
** EPITECH PROJECT, 2025
** RobotFactory
** File description:
** my_strchr
*/

#include <stddef.h>

char *my_strchr(const char *str, int c)
{
    if (str == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return (char *)&str[i];
    }
    return NULL;
}
