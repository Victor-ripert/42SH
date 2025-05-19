/*
** EPITECH PROJECT, 2025
** utils.h
** File description:
** a .h for utils
*/

#ifndef UTILS_H
    #define UTILS_H
    #include "list.h"
    #include <stddef.h>

char **str_to_split_array(const char *str, const char **split_chara);
int str_to_word_array(const char *str, char ***array, const char *split_chara);
void free_word_array(char **array);
int array_len(const char **array);
int my_strcmp(const char *s1, const char *s2);
void my_strcpy(char *dest, const char *src);
void str_cpy_part(char *dest, char *src, size_t start, size_t end);
int my_strlen(const char *str);
int my_strdup(char **dest, const char *send);
void my_strcat(char *dest, const char *src);
int put_char(char const *str, int const mode);
char *trim_spaces(char *str);
char *my_strcat_malloc(char *str1, char *str2);
char **get_path_array(env_t const *env_cpy);
char *make_path(char const *path, char const *command, char const *sep);

#endif
