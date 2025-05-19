/*
** EPITECH PROJECT, 2025
** execute_binary
** File description:
** executes a binary file
*/

#include <sys/wait.h>
#include <unistd.h>
#include "minishell.h"

int execute_binary(char **argv, env_t *env_cpy)
{
    pid_t pid = 0;
    int status = 0;
    int reval = SUCCESS;

    if (access(argv[0], F_OK)) {
        put_char(argv[0], 2);
        put_char(": Command not found.\n", 2);
        return FAILURE;
    }
    if (access(argv[0], X_OK)) {
        put_char(argv[0], 2);
        put_char(": Permission denied.\n", 2);
        return FAILURE;
    }
    pid = fork();
    if (pid == 0)
        reval = execute(argv[0], argv, env_cpy);
    waitpid(pid, &status, 0);
    return (pid == -1 || reval) ? FAILURE : handle_signal(status);
}
