/*
** EPITECH PROJECT, 2018
** my_puttab.c
** File description:
** prints a tab
*/

#include "source_toolbox.h"

void my_putchar(char c);

int my_putstr(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
    return (0);
}

int my_puttab(char const **tab)
{
    for (int x = 0; tab[x]; x++) {
        my_putstr(tab[x]);
        my_putchar('\n');
    }
    return (0);
}