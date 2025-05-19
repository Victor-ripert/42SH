/*
** EPITECH PROJECT, 2025
** handle_double_ampersand
** File description:
** handle_double_ampersand
*/


#include <stdio.h>
#include "minishell.h"

static int check_error(btree_node_t *cmd1, btree_node_t *cmd2)
{
    if (!cmd1 || !cmd2) {
        fprintf(stderr, "Invalid null command.\n");
        return FAILURE;
    }
    return SUCCESS;
}

int handle_double_ampersand(btree_node_t *node, int input_fd,
    int output_fd, list_t *args)
{
    int reval = check_error(node->left, node->right);

    if (reval == FAILURE)
        return FAILURE;
    reval = execute_node(node->left, input_fd, output_fd, args);
    if (reval != SUCCESS)
        return reval;
    reval = execute_node(node->right, input_fd, output_fd, args);
    return reval;
}
