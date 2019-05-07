/*
** EPITECH PROJECT, 2018
** my_compute_power_it.c
** File description:
** Task03
*/

#include "source_toolbox.h"

int function1(int nb, int p, int i, int nb_old)
{
    while (p > i) {
        nb = nb * nb_old;
        p--;
    }
    return (nb);
}

int my_compute_power_it(int nb, int p)
{
    int i = 1;
    int nb_old = nb;

    if (nb == 0 || p < 0)
        return (0);
    else if (p == 0)
        return (1);
    else {
        nb = function1(nb, p, i, nb_old);
        return (nb);
    }
}