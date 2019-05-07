/*
** EPITECH PROJECT, 2018
** my_putchar.c
** File description:
** puts a char
*/

#include "source_toolbox.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
