/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** length of a string
*/

#include "source_toolbox.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}
