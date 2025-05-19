/*
** EPITECH PROJECT, 2025
** handle_output_append
** File description:
** handle_output_append
*/

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include "minishell.h"

static int check_error(btree_node_t *cmd1, btree_node_t *cmd2)
{
    if (!cmd1 || !cmd2) {
        fprintf(stderr, "Missing name for redirect.\n");
        return FAILURE;
    }
    return SUCCESS;
}

int handle_output_append(btree_node_t *node, int input_fd,
    int output_fd, list_t *args)
{
    int reval = check_error(node->left, node->right);
    int fd = 0;

    if (reval == FAILURE)
        return FAILURE;
    fd = open(trim_spaces(node->right->string),
        O_WRONLY | O_APPEND | O_CREAT, 0644);
    if (fd == -1)
        return FAILURE;
    (void)output_fd;
    reval = execute_node(node->left, input_fd, fd, args);
    close(fd);
    return reval;
}
