/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** handle_inhibitors
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "minishell.h"

static char *extract_in_inhibitors(char *str)
{
    char *begin = strchr(str, INHIBITORS);
    char *end = strchr(begin + 1, INHIBITORS);
    char *new_str = NULL;

    if (!begin || !end)
        return NULL;
    new_str = malloc((end - begin) * sizeof(char));
    if (!new_str)
        return NULL;
    new_str = strncpy(new_str, begin + 1, (end - begin - 1));
    new_str[end - begin - 1] = '\0';
    return new_str;
}

static char *read_from_fd(int fd)
{
    char *buffer = NULL;
    size_t total_size = 0;
    ssize_t bytes_read;
    char *new_buf = NULL;
    char temp[CHUNK_SIZE];

    bytes_read = read(fd, temp, sizeof(temp));
    while ((bytes_read) > 0) {
        new_buf = realloc(buffer, total_size + bytes_read + 1);
        if (!new_buf) {
            free(buffer);
            return NULL;
        }
        buffer = new_buf;
        memcpy(buffer + total_size, temp, bytes_read);
        total_size += bytes_read;
        buffer[total_size] = '\0';
        bytes_read = read(fd, temp, sizeof(temp));
    }
    return buffer;
}

static char *execute_commmand_in_inhibitors(char *command, list_t *args)
{
    FILE *tempfile = tmpfile();
    char *answer = NULL;
    int stdout_cpy = dup(STDOUT_FILENO);
    int fd = 0;

    if (!tempfile || stdout_cpy == ERROR)
        return NULL;
    fd = fileno(tempfile);
    if (fd == ERROR)
        return NULL;
    dup2(fd, STDOUT_FILENO);
    ll_parsor(command, args);
    dup2(stdout_cpy, STDOUT_FILENO);
    close(stdout_cpy);
    fseek(tempfile, 0, SEEK_SET);
    answer = read_from_fd(fd);
    fclose(tempfile);
    return answer;
}

static char *fill_input(char **argv, char *new_str, int position)
{
    char *copy = NULL;

    for (int i = 0; i < position && new_str != NULL; i++) {
        copy = new_str;
        new_str = my_strcat_malloc(new_str, argv[i]);
        free(copy);
        if (new_str == NULL)
            return NULL;
        copy = new_str;
        new_str = my_strcat_malloc(new_str, " ");
        free(copy);
    }
    return new_str;
}

static char *create_new_input(char **argv, char *answer, int position)
{
    char *new_str = strdup(" ");
    char *copy = NULL;

    new_str = fill_input(argv, new_str, position);
    new_str = my_strcat_malloc(new_str, answer);
    if (new_str == NULL)
        return NULL;
    free(answer);
    for (int i = position + 1; argv[i] != NULL && new_str != NULL; i++) {
        copy = new_str;
        new_str = my_strcat_malloc(new_str, argv[i]);
        free(copy);
        if (new_str == NULL)
            return NULL;
        copy = new_str;
        new_str = my_strcat_malloc(new_str, " ");
        free(copy);
    }
    return new_str;
}

static char **remplace_inhibitors(char **argv, list_t *args, int position)
{
    char *command = extract_in_inhibitors(argv[position]);
    char *answer = NULL;
    char **new_array = NULL;

    if (command == NULL)
        return NULL;
    answer = execute_commmand_in_inhibitors(command, args);
    if (answer == NULL)
        return NULL;
    answer = create_new_input(argv, answer, position);
    str_to_word_array(answer, &new_array, "\n ");
    free(command);
    free_word_array(argv);
    free(answer);
    return new_array;
}

char **handle_inhibitors(char ***argv, list_t *args)
{
    for (int i = 0; (*argv)[i] != NULL; i++) {
        if (strchr((*argv)[i], INHIBITORS))
            *argv = remplace_inhibitors(*argv, args, i);
        else
            continue;
        if (*argv == NULL)
            return NULL;
    }
    return *argv;
}
