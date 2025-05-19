/*
** EPITECH PROJECT, 2025
** handle_redirecct
** File description:
** handle_redirect
*/

#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

int handle_signle_pipe(btree_node_t *node, int fds[2],
    int pipefd, list_t *args)
{
    int reval = SUCCESS;
    int pid = fork();

    if (pid == 0) {
        close(pipefd);
        reval = execute_node(node, fds[0], fds[1], args);
        exit(reval);
    }
    return (pid < 0) ? FAILURE : reval;
}

static void close_and_wait_child(int pipefd_in, int pipefd_out)
{
    close(pipefd_in);
    close(pipefd_out);
    wait(NULL);
    wait(NULL);
}

static int check_error(btree_node_t *cmd1, btree_node_t *cmd2)
{
    if (!cmd1 || !cmd2) {
        fprintf(stderr, "Invalid null command.\n");
        return SPECIFIC_ERROR;
    }
    return SUCCESS;
}

int handle_pipe(btree_node_t *node, int input_fd,
    int output_fd, list_t *args)
{
    int reval = check_error(node->left, node->right);
    int pipefd[2] = {0};
    int fds[2] = {0};

    if (reval == FAILURE || pipe(pipefd) == -1)
        return FAILURE;
    if (reval == SPECIFIC_ERROR)
        return SPECIFIC_ERROR;
    fds[0] = input_fd;
    fds[1] = pipefd[1];
    reval = handle_signle_pipe(node->left, fds, pipefd[0], args);
    fds[0] = pipefd[0];
    fds[1] = output_fd;
    reval = handle_signle_pipe(node->right, fds, pipefd[1], args);
    close_and_wait_child(pipefd[0], pipefd[1]);
    return reval;
}
