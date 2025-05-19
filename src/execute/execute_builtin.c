/*
** EPITECH PROJECT, 2025
** execute_builtin
** File description:
** executes a bultin
*/

#include <sys/wait.h>
#include <unistd.h>
#include "minishell.h"

int execute_builtin(char **argv, list_t *args, int index)
{
    return DB_exec_func[index].func(argv, args);
}
