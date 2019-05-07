/*
** EPITECH PROJECT, 2018
** my_put_nbr_uint.c
** File description:
** prints unsigned int
*/

#include "source_toolbox.h"

void my_putchar(char c);

int my_put_nbr(long nb);

int my_put_nbr_uint(long nb)
{
    int x = 0;
    long nbl = nb;

    if (nbl < 0) {
        nbl = (4294967296 - (nb));
        my_put_nbr_uint(nbl);
    }
    if (nbl > 9) {
        my_put_nbr(nbl / 10);
        x = nbl % 10;
        my_putchar(x + 48);
    }
    else
        my_putchar(48 + nbl);
    return (0);
}