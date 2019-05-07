/*
** EPITECH PROJECT, 2018
** my_strcat.c
** File description:
** concatenates a string
*/

#include "source_toolbox.h"

char *my_strcat(char *dest, char const *src)
{
    int f = 0, i = 0;
    char *new = NULL;

    new = malloc(sizeof(char *) * (my_strlen(dest) + my_strlen(src) + 1));
    for (; dest[i] != '\0' ; i++) {
        new[i] = dest[i];
    }
    for (; src[f] != '\0'; f++) {
        new[i + f] = src[f];
    }
    new[i + f] = '\0';
    return (new);
}