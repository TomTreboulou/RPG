/*
** EPITECH PROJECT, 2018
** Visual Studio Live Share (Workspace)
** File description:
** quest_check.c
*/

#include "project.h"

void select_boss(as_t *as)
{
    int x = 0;
    int y = 0;
    for (int i = 0; i < 1000; i++) {
        x = rand() % as->set->size_max;
        y = rand() % as->set->size_max;
        if ((x != as->set->size_max / 2 || y != as->set->size_max / 2)
        && (x != as->x || y != as->y) && as->gen[y][x].pass == 1) {
            as->gen[y][x].type = 2;
            break;
        }
    }
}

int check_quest(as_t *as)
{
    int check = 0;

    for (int i = 0; i < as->set->size_max && check == 0; i++) {
        for (int j = 0; j < as->set->size_max && check == 0; j++) {
            check += (as->gen[i][j].pass == 1 && as->gen[i][j].type == 0)
            ? 1 : 0;
        }
    }
    return (check);
}