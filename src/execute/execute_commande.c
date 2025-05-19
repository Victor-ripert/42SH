/*
** EPITECH PROJECT, 2025
** execute_commande
** File description:
** executes a comande
*/

#include <stddef.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "minishell.h"

static int check_path(char **array, char **path, char const *command)
{
    for (int i = 0; array[i] != NULL; ++i) {
        *path = make_path(array[i], command, "/");
        if (!(*path))
            return FAILURE;
        if (!access(*path, X_OK)) {
            return SUCCESS;
        }
        free(*path);
        *path = NULL;
    }
    fprintf(stderr, "%s: Command not found.\n", command);
    return SPECIFIC_ERROR;
}

int execute_commande(char **argv, env_t *env_cpy)
{
    pid_t pid = 0;
    char *path = NULL;
    int status = 0;
    int reval = SUCCESS;
    char **array = get_path_array(env_cpy);

    if (!array)
        return FAILURE;
    if (check_path(array, &path, argv[0]) == FAILURE) {
        free_word_array(array);
        return FAILURE;
    }
    pid = fork();
    if (pid == 0)
        reval = execute(path, argv, env_cpy);
    waitpid(pid, &status, 0);
    free(path);
    free_word_array(array);
    return (pid == -1 || reval) ? FAILURE : handle_signal(status);
}
