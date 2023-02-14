/*
** EPITECH PROJECT, 2023
** read_input
** File description:
** reads the input from the user
*/

#include "navy.h"

char *get_input(void)
{
    char *lineptr = NULL;
    size_t n = 0;
    ssize_t size = 0;

    while ((size = getline(&lineptr, &n, stdin)) == 0) {}
    if (size == -1)
        return (NULL);
    if (size != 3) {
        lineptr[0] = 'I';
        lineptr[1] = '9';
    }
    return (lineptr);
}
