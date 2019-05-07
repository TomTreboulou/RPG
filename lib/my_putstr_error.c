/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** prints a string
*/

#include "source_toolbox.h"

void my_putchar_error(char c)
{
    write(2, &c, 1);
}

int my_putstr_error(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        my_putchar_error(str[i]);
        i = i + 1;
    }
    return (0);
}