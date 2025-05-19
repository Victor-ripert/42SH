/*
** EPITECH PROJECT, 2025
** env.h
** File description:
** a .h for env
*/

#ifndef ENV_H
    #define ENV_H

typedef struct env_s {
    char *key;
    char *value;
    struct env_s *next;
} env_t;

int copy_env(const char **env, env_t **env_cpy);
int push_to_list(env_t **head, const char *key, const char *value);
void free_list(env_t *env_cpy);
int change_value(env_t **curr, char *str);
int get_value(env_t **env_cpy, char **value, char *key);
int set_value(env_t **env_cpy, char *value, char *key);

#endif
