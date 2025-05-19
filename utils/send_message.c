/*
** EPITECH PROJECT, 2025
** send_message
** File description:
** a function to send a message
*/

#include <unistd.h>
#include <stddef.h>
#include "minishell.h"

int str_len(char const *message)
{
    size_t size = 0;

    while (message[size] != '\0') {
        size++;
    }
    return size;
}

int send_message(char const *message, int const mode)
{
    size_t size = str_len(message);

    if (mode == SUCCESS) {
        write(1, message, size);
    } else {
        write(2, message, size);
    }
    return mode;
}
