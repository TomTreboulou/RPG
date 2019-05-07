/*
** EPITECH PROJECT, 2018
** my_str_to_word_array.c
** File description:
** makes a str to an array
*/

#include "source_toolbox.h"

int my_strlen_word(char const *str, char delimiter)
{
    int i = 0;

    while (str[i] != delimiter && str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

int my_strlen_size(char const *str, char delimiter)
{
    int i = 0;
    int x = 1;

    while (str[i]) {
        if (str[i] == '\0' || str[i] == delimiter || \
        str[i] == '\n' || str[i] == '\t')
            x++;
        i++;
    }
    return (x);
}

char **my_str_to_word_array(char const *str, char delimiter)
{
    char **ar = malloc(sizeof(char *) * (my_strlen_size(str, delimiter) + 1));
    int i = 0, x = 0, y = 0;
    while (str[i] == delimiter)
        i++;
    while (str[i] != '\0') {
        ar[x] = malloc(sizeof(char) * (my_strlen_word(&str[i], delimiter) \
        + 1));
        y = 0;
        while (str[i] != delimiter && str[i] != '\0' && str[i] != '\t') {
            ar[x][y] = str[i];
            i++, y++;
        }
        ar[x][y] = '\0';
        while ((str[i] == delimiter || str[i] == '\t') && str[i])
            i++;
        x++;
    }
    ar[x] = NULL;
    return (ar);
}