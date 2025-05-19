/*
** EPITECH PROJECT, 2025
** 42SH -> alias.h
** File description:
** a .h for alias
*/

#ifndef ALIAS_H
    #define ALIAS_H

typedef struct alias_s {
    char *alias_name;
    char *alias_command;
    struct alias_s *next;
    struct alias_s *previous;
} alias_t;

int add_alias(alias_t **head, char *alias_name, char **alias_command);
int remove_alias(alias_t **head, char *node_name);
int replace_word(char **word, alias_t **head);
alias_t *search_alias(alias_t **head, char *alias_name);
int replace_by_alias(char ***argv, alias_t **head);
void free_alias(alias_t **list);

// A BOUGER DANS UTILS
char *reconcat_args(char **array, char delim);

#endif /* ALIAS_H */
