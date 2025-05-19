/*
** EPITECH PROJECT, 2025
** my_env
** File description:
** a function to display the env
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "minishell.h"
#include <dirent.h>

static int check_file(char *file_path)
{
    DIR *dir = opendir(file_path);

    if (access(file_path, F_OK)) {
        put_char(file_path, 2);
        put_char(": No such file or directory.\n", 2);
        return 1;
    }
    if (dir == NULL) {
        put_char(file_path, 2);
        put_char(": Not a directory.\n", 2);
        return 1;
    } else {
        closedir(dir);
    }
    if (access(file_path, X_OK)) {
        put_char(file_path, 2);
        put_char(": Permission denied.\n", 2);
        return 1;
    }
    return SUCCESS;
}

static int change_back(env_t **env_cpy, char **old_pwd)
{
    char *pwd = NULL;
    char *path = NULL;

    if (get_value(env_cpy, &pwd, "PWD") == FAILURE)
        return FAILURE;
    if (check_file(*old_pwd) == 1)
        return 1;
    if (chdir(*old_pwd) == -1)
        return 1;
    my_strdup(&path, *old_pwd);
    my_strdup(old_pwd, pwd);
    if (!path || !old_pwd)
        return FAILURE;
    if (set_value(env_cpy, path, "PWD") == FAILURE)
        return FAILURE;
    free(path);
    return SUCCESS;
}

static int change_forward(env_t **env_cpy, char *path, char **old_pwd)
{
    char *pwd = NULL;

    if (get_value(env_cpy, &pwd, "PWD") == FAILURE)
        return FAILURE;
    if (check_file(path) == 1)
        return 1;
    if (chdir(path) == -1)
        return 1;
    my_strdup(old_pwd, pwd);
    if (!old_pwd)
        return FAILURE;
    if (set_value(env_cpy, path, "PWD") == FAILURE) {
        return FAILURE;
    }
    return SUCCESS;
}

static int change_path(env_t **env_cpy, char *path, char **old_pwd)
{
    int reval = 0;

    if (my_strcmp("-", path) == 0) {
        reval = change_back(env_cpy, old_pwd);
    } else {
        reval = change_forward(env_cpy, path, old_pwd);
    }
    return reval;
}

static int change_home(env_t **env_cpy, char **old_pwd)
{
    char *home_path = NULL;
    int reval = 0;

    if (get_value(env_cpy, &home_path, "HOME") == FAILURE)
        return FAILURE;
    reval = change_forward(env_cpy, home_path, old_pwd);
    return reval;
}

int my_cd(char **argv, list_t *args)
{
    int len = array_len((char const **) argv);
    int reval = 0;
    static char *old_pwd = NULL;

    if (len > 2) {
        write(2, "cd: Too many arguments.\n", 24);
        return 1;
    }
    if (len == 1) {
        reval = change_home(args->env_cpy, &old_pwd);
    } else {
        reval = change_path(args->env_cpy, argv[1], &old_pwd);
    }
    return reval;
}
