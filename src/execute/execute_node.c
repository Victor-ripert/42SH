/*
** EPITECH PROJECT, 2025
** handle_redirecct
** File description:
** handle_redirect
*/

#include <sys/wait.h>
#include <unistd.h>
#include "minishell.h"

static void dup_fd(int cur_fd, int cmp_fd)
{
    if (cur_fd != cmp_fd) {
        dup2(cur_fd, cmp_fd);
        close(cur_fd);
    }
}

static int handle_input(btree_node_t *node, int input_fd,
    int output_fd, list_t *args)
{
    int reval = SUCCESS;
    int stdin_copy = dup(STDIN);
    int stdout_copy = dup(STDOUT);

    if (stdin_copy == -1 || stdout_copy == -1)
        return FAILURE;
    dup_fd(input_fd, STDIN);
    dup_fd(output_fd, STDOUT);
    reval = handle_execute(node->string, args);
    dup_fd(stdin_copy, STDIN);
    dup_fd(stdout_copy, STDOUT);
    return reval;
}

int execute_node(btree_node_t *node, int input_fd,
    int output_fd, list_t *args)
{
    if (!node)
        return SUCCESS;
    for (int i = 0; DB_redir_func[i].redir_func; i++) {
        if (my_strcmp(node->string, DB_redir_func[i].redir) == 0) {
            return DB_redir_func[i]
                .redir_func(node, input_fd, output_fd, args);
        }
    }
    return handle_input(node, input_fd, output_fd, args);
}
