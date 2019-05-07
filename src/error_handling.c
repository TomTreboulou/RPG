/*
** EPITECH PROJECT, 2018
** error_handling.c
** File description:
** function to handle errors
*/

// A LA NORME

#include "project.h"

void error_fps(win_t *win)
{
    if (win->fps > 0)
        sfRenderWindow_setFramerateLimit(win->window, win->fps);
    else
        sfRenderWindow_setFramerateLimit(win->window, 60);
}

void my_print(int num)
{
    if (num == 1) {
        my_printf("USAGE\n");
    } else if (num == 2) {
        my_printf("Bad input\n");
        my_printf("Try using './my_rpg -h' to get the usage\n");
    }
}

int error(int ac, char **av, win_t *win)
{
    if (ac == 2) {
        char *str_h = "-h";
        if (my_compare_str(av[1], str_h) == 1) {
            my_print(1);
            return (0);
        } else if (my_isnum(av[1]) == 1) {
            win->fps = my_atoi(av[1]);
            return (1);
        } else {
            my_print(2);
            return (84);
        }
    } else if (ac > 2) {
        my_printf("Bad input\n");
        my_printf("Try using './my_rpg -h' to get the usage\n");
        return (84);
    }
    win->fps = 60;
    return (1);
}