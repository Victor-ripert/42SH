/*
** EPITECH PROJECT, 2025
** strcat_malloc
** File description:
** strcat
*/

#include <stdlib.h>
#include "minishell.h"

char *my_strcat_malloc(char *str1, char *str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    char *result = malloc((len1 + len2 + 1) * sizeof(char));

    if (result == NULL)
        return NULL;
    for (int i = 0; i < len1; i++) {
        result[i] = str1[i];
    }
    for (int j = 0; j < len2; j++) {
        result[len1 + j] = str2[j];
    }
    result[len1 + len2] = '\0';
    return result;
}
