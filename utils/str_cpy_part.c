/*
** EPITECH PROJECT, 2025
** str_cpy_part
** File description:
** a function to copy a part of a string
*/

void str_cpy_part(char *dest, const char *src, int start, int end)
{
    int index = 0;

    for (int i = start; i < end; ++i) {
        dest[index] = src[i];
        index++;
    }
    dest[index] = '\0';
}
