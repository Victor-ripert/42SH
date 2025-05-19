/*
** EPITECH PROJECT, 2025
** redirections.h
** File description:
** a .h for redirections
*/

#ifndef REDIRECTIONS_H
    #define REDIRECTIONS_H
    #include <string.h>

    #define __maybe_unused __attribute__((unused))

typedef struct btree_node_s {
    char *string;
    struct btree_node_s* left;
    struct btree_node_s* right;
} btree_node_t;

int ll_parsor(char *input, list_t *args);
int execute_node(btree_node_t *node, int input_fd,
    int output_fd, list_t *args);
int handle_output_append(btree_node_t *node, int in,
    int out, list_t *args);
int handle_output_redir(btree_node_t *node, int in,
    int out, list_t *args);
int handle_input_read_write(btree_node_t *node, int in,
    int out, list_t *args);
int handle_input_redir(btree_node_t *node, int in,
    int out, list_t *args);
int handle_pipe(btree_node_t *node, int in,
    int out, list_t *args);
int handle_semicolon(btree_node_t *node, int in,
    int out, list_t *args);
int handle_double_pipe(btree_node_t *node, int input_fd,
    int output_fd, list_t *args);
int handle_double_ampersand(btree_node_t *node, int input_fd,
    int output_fd, list_t *args);

typedef struct redir_func_s {
    char *redir;
    int (*redir_func)(btree_node_t *tree, int in, int out, list_t *args);
} redir_func_t;

static const redir_func_t DB_redir_func[] __maybe_unused = {
    {">>", handle_output_append},
    {"<>", handle_input_read_write},
    {">", handle_output_redir},
    {"<", handle_input_redir},
    {"||", handle_double_pipe},
    {"|", handle_pipe},
    {"&&", handle_double_ampersand},
    {";", handle_semicolon},
    {NULL, NULL}
};

static const char *const redirectors[] = {
    ">>", ">", "<<", "<>", "<", "||", "|", "&&", ";", NULL
};

#endif
