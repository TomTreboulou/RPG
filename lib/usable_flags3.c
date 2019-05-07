/*
** EPITECH PROJECT, 2018
** usable_flags3.c
** File description:
** flags for my_printf part3
*/

#include "source_toolbox.h"

void non_printable_bis(int i, char *str)
{
    if (str[i] < 32  || str[i] >= 127) {
        my_putstr("\\");
        if (str[i] < 7)
            my_putstr("00");
        else if (str[i] > 7 && str[i] < 32)
            my_putstr("0");
        my_put_nbr_base(str[i], "01234567");
    } else
        my_putchar(str[i]);
}

void non_printable(va_list args)
{
    char *str = va_arg(args, char *);

    for (int i = 0; str[i] != '\0'; i++) {
        non_printable_bis(i, str);
    }
}