/*
** EPITECH PROJECT, 2018
** my_strcpy.c
** File description:
** copies the string to another
*/

#include "source_toolbox.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}