/*
** EPITECH PROJECT, 2025
** handle_input_read_write
** File description:
** handle_input_read_write
*/

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include "minishell.h"

static int check_error(btree_node_t *cmd1, btree_node_t *cmd2)
{
    if (!cmd1 || !cmd2) {
        fprintf(stderr, "Invalid null command.\n");
        return FAILURE;
    }
    return SUCCESS;
}

int handle_input_read_write(btree_node_t *node, int input_fd,
    int output_fd, list_t *args)
{
    int reval = check_error(node->left, node->right);
    int fd = 0;

    if (reval == FAILURE)
        return FAILURE;
    fd = open(trim_spaces(node->right->string),
        O_RDWR | O_CREAT, 0644);
    if (fd == -1)
        return FAILURE;
    (void)input_fd;
    reval = execute_node(node->left, fd, output_fd, args);
    close(fd);
    return reval;
}
