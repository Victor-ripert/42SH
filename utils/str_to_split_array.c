/*
** EPITECH PROJECT, 2025
** str_to_split_array
** File description:
** a function to cut a string betwen delimiters
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "minishell.h"

static bool str_cmp_part(const char *str, const char *sep,
    size_t const start, size_t const len)
{
    for (size_t i = 0; i < len; i++) {
        if (str[i + start] != sep[i])
            return false;
    }
    return true;
}

static int is_sep(const char *str, const char **seps, int start)
{
    size_t len = 0;

    for (size_t i = 0; seps[i]; i++) {
        len = my_strlen(seps[i]);
        if (str_cmp_part(str, seps[i], start, len)) {
            return len;
        }
    }
    return 0;
}

static void get_word_nbr(char const *str, int *word_nbr, const char **seps)
{
    int in_word = 0;
    int i = 0;

    while (str[i]) {
        if ((!is_sep(str, seps, i)) && !in_word) {
            in_word = 1;
            (*word_nbr)++;
        }
        if (is_sep(str, seps, i)) {
            in_word = 0;
            (*word_nbr)++;
            i += is_sep(str, seps, i) - 1;
        }
        i++;
    }
}

static int fill_sep(char **arr, const char *str,
    int **indexes, char const **seps)
{
    while (is_sep(str, seps, *indexes[1])) {
        arr[*indexes[0]] = malloc(sizeof(char) *
            (is_sep(str, seps, *indexes[1]) + 1));
        if (!arr[*indexes[0]])
            return FAILURE;
        str_cpy_part(arr[*indexes[0]], (char *)str, *indexes[1],
            is_sep(str, seps, *indexes[1]) + *indexes[1]);
        (*indexes[0])++;
        *indexes[1] += is_sep(str, seps, *indexes[1]);
    }
    return SUCCESS;
}

static int fill_array(char **arr, const char *str,
    int const word_nbr, char const **seps)
{
    int i = 0;
    int index = 0;
    int *indexes[2] = {&index, &i};
    int word_delim[2] = {0};

    while (*indexes[0] < word_nbr) {
        if (fill_sep(arr, str, indexes, seps) == FAILURE)
            return FAILURE;
        word_delim[0] = i;
        while (!is_sep(str, seps, i) && str[i] != '\0')
            i++;
        word_delim[1] = i;
        arr[index] = malloc(sizeof(char) *
            (word_delim[1] - word_delim[0] + 1));
        if (!arr[index])
            return FAILURE;
        str_cpy_part(arr[index], (char *)str, word_delim[0], word_delim[1]);
        index++;
    }
    return SUCCESS;
}

char **str_to_split_array(char const *str, const char **seps)
{
    int word_nbr = 0;
    char **array = NULL;

    get_word_nbr(str, &word_nbr, seps);
    array = malloc(sizeof(char *) * (word_nbr + 1));
    if (!array)
        return NULL;
    if (fill_array(array, str, word_nbr, seps) == FAILURE) {
        free_word_array(array);
        return NULL;
    }
    array[word_nbr] = NULL;
    return array;
}
