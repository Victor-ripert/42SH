/*
** EPITECH PROJECT, 2025
** ll_parsor
** File description:
** ll_parsor
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minishell.h"

static btree_node_t *create_btree_node(char *value)
{
    btree_node_t *new_btree_node = malloc(sizeof(btree_node_t));

    if (!new_btree_node)
        return NULL;
    new_btree_node->string = value;
    new_btree_node->left = NULL;
    new_btree_node->right = NULL;
    return new_btree_node;
}

static bool is_redirector(char *value)
{
    for (int i = 0; DB_redir_func[i].redir != NULL; i++) {
        if (strcmp(DB_redir_func[i].redir, value) == 0)
            return true;
    }
    return false;
}

static btree_node_t *create_btree(char **values, int index)
{
    btree_node_t *newBTree = NULL;

    if (index < 0)
        return NULL;
    if (is_redirector(values[index])) {
        newBTree = create_btree_node(values[index]);
        newBTree->right = (values[index + 1]) ?
        create_btree_node(values[index + 1]) :
        NULL;
        newBTree->left = create_btree(values, index - 1);
    } else {
        newBTree = (index == 0) ?
        create_btree_node(values[index]) :
        create_btree(values, index - 1);
    }
    return newBTree;
}

int len_array(char **array)
{
    int len = 0;

    if (*array == NULL)
        return 0;
    while (array[len] != NULL) {
        ++len;
    }
    return len;
}

void free_btree(btree_node_t *tree)
{
    if (tree != NULL) {
        free_btree(tree->left);
        free_btree(tree->right);
        free(tree);
    }
}

int ll_parsor(char *input, list_t *args)
{
    char **array = NULL;
    btree_node_t *tree = NULL;
    int reval = SUCCESS;

    if (input[0] == '\0')
        return SUCCESS;
    array = str_to_split_array(input, (const char **)redirectors);
    if (!array)
        return FAILURE;
    if (replace_by_alias(&array, args->alias) == FAILURE)
        return FAILURE;
    tree = create_btree(array, len_array(array) - 1);
    if (!tree)
        return FAILURE;
    reval = execute_node(tree, STDIN, STDOUT, args);
    free_btree(tree);
    free_word_array(array);
    return reval;
}
