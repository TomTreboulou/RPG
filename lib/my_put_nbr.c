/*
** EPITECH PROJECT, 2018
** my_put_nbr_base.c
** File description:
** Task07
*/

#include "source_toolbox.h"

void my_putchar(char c);

int my_put_nbr(long nb)
{
    int x = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        x = nb % 10;
        my_putchar(x + 48);
    }
    else
        my_putchar(48 + nb);
    return (0);
}
