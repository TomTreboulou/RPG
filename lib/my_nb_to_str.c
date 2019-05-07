/*
** EPITECH PROJECT, 2018
** my_nb_to_str.c
** File description:
** Converts int into a pointer character
*/

#include "source_toolbox.h"

char *my_nb_to_str(long nb)
{
    long save;
    long i = -1;
    char *arr = malloc(sizeof(char) * 50);
    for (int n = nb; n >= 1; i++)
    	n = n / 10;
    save = i;
    while (nb >= 1) {
        arr[i] = nb % 10 + '0';
        nb = nb / 10;
        i--;
    }
    arr[save + 1] = '\0';
    if (arr[0] == '\0') {
        arr[0] = '0';
        arr[1] = '\0';
    }
    return (arr);
}