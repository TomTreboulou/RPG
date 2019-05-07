/*
** EPITECH PROJECT, 2018
** my_tablen.c
** File description:
** length of a tab
*/

#include "source_toolbox.h"

int my_tablen(char const **tab)
{
    int i = 0;

    while (tab[i] != '\0') {
        i = i + 1;
    }
    return (i);
}