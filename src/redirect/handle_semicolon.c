/*
** EPITECH PROJECT, 2025
** handle_redirecct
** File description:
** handle_redirect
*/

#include "minishell.h"

int handle_semicolon(btree_node_t *node, int input_fd,
    int output_fd, list_t *args)
{
    int reval = SUCCESS;

    reval = execute_node(node->left, input_fd, output_fd, args);
    reval = execute_node(node->right, input_fd, output_fd, args);
    return reval;
}
