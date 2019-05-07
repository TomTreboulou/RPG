/*
** EPITECH PROJECT, 2018
** my_put_nbr_base.c
** File description:
** makes a new base
*/

#include "source_toolbox.h"

void my_putchar(char c);

int my_strlen(char const *str);

int my_put_nbr_base(long nb, char *base)
{
    int len = my_strlen(base);
    if (nb < -2147483648 || nb > 2147483647)
        return (84);
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    } else if (nb == 0)
        return (0);
    else
        my_put_nbr_base(nb / len, base);
    my_putchar(base[nb % len]);
    return (0);
}

int my_put_nbr_base_uns(long nb, char *base)
{
    int len = my_strlen(base);
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    } else if (nb == 0)
        return (0);
    else
        my_put_nbr_base_uns(nb / len, base);
    my_putchar(base[nb % len]);
    return (0);
}