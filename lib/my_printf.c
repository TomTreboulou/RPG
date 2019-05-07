/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** function to print according to given args
*/

#include "source_toolbox.h"

const flags_t flags[13] = {
    {'d', &integer},
    {'i', &integer},
    {'x', &hexadec_min},
    {'X', &hexadec_maj},
    {'s', &string},
    {'c', &character},
    {'%', &percent},
    {'u', &uns_int},
    {'S', &non_printable},
    {'b', &binary},
    {'o', &octal},
    {'p', &pointer},
    {0, NULL}
};

int testing_char(char str, va_list args)
{
    int i = 0;
    while (flags[i].to_print != 0) {
        if (str == flags[i].to_print) {
            flags[i].functionptr(args);
            return (0);
        }
        i++;
    }
    if (i = 20) {
        my_putchar('%');
        my_putchar(str);
    }
}

int my_printf(char *str, ...)
{
    va_list args;
    int i = 0;
    va_start(args, *str);
    while (str[i] != '\0') {
        if (str[i] == '%' && str[i+1] == '%' && \
        (i+2 != my_strlen(str)) && str[i+2] != '%') {
            my_putchar('%');
            i += 2;
            my_putchar(str[i]);
            i--;
        } else if (str[i] == '%') {
            i++;
            testing_char(str[i], args);
        } if (str[i - 1] != '%')
            my_putchar(str[i]);
        i++;
    }
    va_end(args);
}