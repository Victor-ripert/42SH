/*
** EPITECH PROJECT, 2025
** str_to_word_array
** File description:
** a function to cut a string into an array of words
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "minishell.h"

static bool check_spliters(char const chara, char const *spliters)
{
    bool is_spliter = false;
    int len = my_strlen(spliters) + 1;

    for (int i = 0; i < len; ++i) {
        if (spliters[i] == chara) {
            is_spliter = true;
            break;
        }
    }
    return is_spliter;
}

void get_word_nbr(char const *str, int *word_nbr, char const *split_chara)
{
    int state = 0;
    int len = my_strlen(str) + 1;

    for (int i = 0; i < len; i++) {
        if (!check_spliters(str[i], split_chara) && state == 0)
            state = 1;
        if (check_spliters(str[i], split_chara) && state == 1) {
            state = 0;
            (*word_nbr)++;
        }
    }
}

int malloc_array(int const word_nbr, char ***array)
{
    (*array) = (char **) malloc(sizeof(char *) * (word_nbr + 1));
    if (*array == NULL)
        return FAILURE;
    (*array)[word_nbr] = NULL;
    return SUCCESS;
}

int fill_word(char **array, char const *start_ptr,
    char const *end_ptr, int index)
{
    int word_length = end_ptr - start_ptr;

    array[index] = malloc(sizeof(char) * (word_length + 1));
    if (array[index] == NULL)
        return FAILURE;
    for (int i = 0; i < word_length; i++) {
        array[index][i] = start_ptr[i];
    }
    array[index][word_length] = '\0';
    return SUCCESS;
}

static int fill_array(char **array, char const *str,
    int const word_nbr, char const *split_chara)
{
    int state = 0;
    char const *start_ptr = 0;
    char const *end_ptr = str;
    int index = 0;

    while (index < word_nbr) {
        if (!check_spliters(*end_ptr, split_chara) && !state) {
            state = 1;
            start_ptr = end_ptr;
        }
        end_ptr++;
        if (!(check_spliters(*end_ptr, split_chara) && state))
            continue;
        state = 0;
        if (fill_word(array, start_ptr, end_ptr, index) == FAILURE)
            return FAILURE;
        index++;
    }
    return SUCCESS;
}

int str_to_word_array(char const *str, char ***array, char const *split_chara)
{
    int word_nbr = 0;

    get_word_nbr(str, &word_nbr, split_chara);
    if (malloc_array(word_nbr, array) == FAILURE)
        return FAILURE;
    if (fill_array(*array, str, word_nbr, split_chara) == FAILURE) {
        free_word_array(*array);
        return FAILURE;
    }
    return SUCCESS;
}
