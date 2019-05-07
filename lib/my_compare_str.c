/*
** EPITECH PROJECT, 2018
** my_compare_str.c
** File description:
** compares 2 strings
*/

#include "source_toolbox.h"

int my_compare_str(char *str1, char *str2)
{
    int len_str1 = my_strlen(str1);
    int len_str2 = my_strlen(str2);
    int len = len_str1 > len_str2 ? len_str1 : len_str2;
    for (int i = 0; i < len; i++) {
        if (str1[i] != str2[i])
            return (0);
    }
    return (1);
}