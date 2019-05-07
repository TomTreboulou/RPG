/*
** EPITECH PROJECT, 2018
** my_atoi.c
** File description:
** Converts pointer character into integer
*/

#include "source_toolbox.h"

int my_atoi(char *str)
{
    int sum = 0;
    int stock = 0;
    int i = my_strlen_delim(str, '\0') - 1;
    while (i >= 0) {
        sum = sum + (str[i] - 48) * my_compute_power_it(10, stock);
        stock++;
        i--;
    }
    return (sum);
}
