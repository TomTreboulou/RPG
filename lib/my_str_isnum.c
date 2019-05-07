/*
** EPITECH PROJECT, 2018
** my_str_isnum.c
** File description:
** tells if the string is full of int or not
*/

#include "source_toolbox.h"

int my_isnum(char *str)
{
    int n = my_strlen(str);
    for (int i = 0; i < n; i++) {
        if (str[i] >= '0' && str[i] <= '9');
        else
            return (0);
    }
    return (1);
}

int my_str_isnum(int ac, char **str)
{
    int x;
    for (int i = 1; i < ac; i++) {
        x = my_isnum(str[i]);
        if (x == 0)
            return (0);
    }
    return (1);
}