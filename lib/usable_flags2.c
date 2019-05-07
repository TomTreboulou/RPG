/*
** EPITECH PROJECT, 2018
** usable_flags2.c
** File description:
** flags for my_printf part2
*/

#include "source_toolbox.h"

void uns_int(va_list args)
{
    my_put_nbr_uint(va_arg(args, long));
}

void percent(va_list args)
{
    my_putchar('%');
}

void binary(va_list args)
{
    my_put_nbr_base_uns(va_arg(args, unsigned long), "01");
}

void octal(va_list args)
{
    my_put_nbr_base_uns(va_arg(args, unsigned long), "01234567");
}

void pointer(va_list args)
{
    long adress = va_arg(args, long);

    if (adress == 0) {
        my_putstr("null pointer");
    }
    my_putstr("0x");
    my_put_nbr_base_uns(adress, "0123456789abcdef");
}
