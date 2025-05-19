/*
** EPITECH PROJECT, 2025
** free_word_array
** File description:
** a function to free a word array
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

void free_word_array(char **array)
{
    for (int i = 0; array[i] != NULL; ++i) {
        free(array[i]);
    }
    free(array);
}
