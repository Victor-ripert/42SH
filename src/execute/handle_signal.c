/*
** EPITECH PROJECT, 2025
** execute_commande
** File description:
** executes a comande
*/

#include <stdio.h>
#include <sys/wait.h>
#include "minishell.h"

int handle_signal(int const status)
{
    int signal = 0;

    if (WIFSIGNALED(status)) {
        signal = WTERMSIG(status);
        switch (signal) {
            case SIGFPE:
                fprintf(stderr, "Floating exception");
                break;
            case SIGSEGV:
                fprintf(stderr, "Segmentation fault");
                break;
            default:
                fprintf(stderr, "%s", strsignal(signal));
        }
        if (WCOREDUMP(status)) {
            fprintf(stderr, " (core dumped)\n");
        }
        return 128 + signal;
    }
    return WEXITSTATUS(status);
}
