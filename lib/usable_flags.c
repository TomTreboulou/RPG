/*
** EPITECH PROJECT, 2018
** usable_flags.c
** File description:
** flags for my_printf part1
*/

#include "source_toolbox.h"

void hexadec_maj(va_list args)
{
    my_put_nbr_base_uns(va_arg(args, unsigned long), "0123456789ABCDEF");
}

void hexadec_min(va_list args)
{
    my_put_nbr_base_uns(va_arg(args, unsigned long), "0123456789abcdef");
}

void integer(va_list args)
{
    my_put_nbr(va_arg(args, int));
}

void string(va_list args)
{
    my_putstr(va_arg(args, char *));
}

void character(va_list args)
{
    my_putchar(va_arg(args, int));
}