/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** lib_tab.c
*/

// A LA NORME

#include "project.h"
#include "source_toolbox.h"

char **my_double_malloc(int a, int b)
{
    char **stock = malloc(sizeof(char *) * a);
    int i = 0;

    for (i = 0; i < a; i++) {
        stock[i] = malloc(sizeof(char) * b);
        for (int n = 0; n < b; n++)
            stock[i][n] = '\0';
    }
    return (stock);
}

char **tab_filler(char *str)
{
    char **tab = NULL;
    int y = 0;

    tab = my_double_malloc(10, 17);
    for (int i = 0, j = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            y += 1;
            j = 0;
        } else {
            tab[y][j] = str[i];
            j += 1;
        }
    }
    tab[y + 1] = NULL;
    return (tab);
}

void my_usleep(float sec)
{
    sfClock *clock = sfClock_create();
    sfTime time = sfClock_getElapsedTime(clock);
    float second = time.microseconds / 1000000.0;

    while (second < sec) {
        time = sfClock_getElapsedTime(clock);
        second = time.microseconds / 1000000.0;
    }
    sfClock_destroy(clock);
}
