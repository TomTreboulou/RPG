/*
** EPITECH PROJECT, 2018
** my_revstr.c
** File description:
** Reverses a string
*/

#include "source_toolbox.h"

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (str[j] != '\0') {
        j++;
    }
    j--;
    while (i < j) {
        k = str[i];
        str[i] = str[j];
        str[j] = k;
        i++;
        j--;
    }
    return (str);
}