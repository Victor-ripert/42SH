/*
** EPITECH PROJECT, 2025
** 42SH -> add_alias.c
** File description:
** add an alias to the linked_list
*/

#include <string.h>
#include <stdlib.h>
#include "minishell.h"
#include "alias.h"

int fill_node(alias_t *node, char *alias_name, char **alias_command)
{
    char *command_str = NULL;

    command_str = reconcat_args(alias_command, ' ');
    if (command_str == NULL)
        return FAILURE;
    if (my_strdup(&node->alias_name, alias_name) == FAILURE
        || my_strdup(&node->alias_command, command_str) == FAILURE)
        return FAILURE;
    free(command_str);
    node->previous = NULL;
    return SUCCESS;
}

int add_alias(alias_t **head, char *alias_name, char **alias_command)
{
    alias_t *new_node = NULL;

    if (alias_name == NULL || alias_command == NULL || head == NULL)
        return FAILURE;
    new_node = malloc(sizeof(alias_t));
    if (fill_node(new_node, alias_name, alias_command) == FAILURE)
        return FAILURE;
    if (new_node == NULL)
        return FAILURE;
    if ((*head) == NULL) {
        new_node->next = NULL;
        (*head) = new_node;
        return SUCCESS;
    }
    new_node->next = (*head);
    (*head)->previous = new_node;
    (*head) = new_node;
    return SUCCESS;
}
