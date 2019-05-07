/*
** EPITECH PROJECT, 2018
** my_strlen_delim.c
** File description:
** length of a string with delimiter
*/

#include "source_toolbox.h"

int my_strlen_delim(char const *str, char delimiter)
{
    int i = 0;

    while (str[i] != delimiter) {
        i = i + 1;
    }
    return (i);
}
