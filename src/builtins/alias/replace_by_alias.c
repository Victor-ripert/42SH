/*
** EPITECH PROJECT, 2025
** 42sh -> replace_by_alias.c
** File description:
** Search in the list for an alias and replace the alias by its command
*/

#include <stdlib.h>
#include "minishell.h"
#include "alias.h"

int replace_word(char **word, alias_t **head)
{
    char *new_word = NULL;
    alias_t *word_node = NULL;

    word_node = search_alias(head, (*word));
    if (word_node == NULL)
        return FAILURE;
    if (my_strdup(&new_word, word_node->alias_command) == FAILURE)
        return FAILURE;
    free((*word));
    (*word) = new_word;
    return SUCCESS;
}

int replace_by_alias(char ***argv, alias_t **head)
{
    if (!argv)
        return FAILURE;
    for (size_t i = 0; (*argv)[i] != NULL; i++) {
        replace_word(&(*argv)[i], head);
    }
    return SUCCESS;
}
