/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** rng_path.c
*/

// A LA NORME

#include "project.h"

void path1(as_t *as, int y, int x)
{
    if (as->room < as->set->level_max && y < as->set->size_max - 1 &&
    as->gen[y + 1][x].type == 1 && as->gen[y + 1][x].pass == 0)
        path_creator(as, y + 1, x);
    if (as->room < as->set->level_max && y > 0 && as->gen[y - 1][x].type ==
    1 && as->gen[y - 1][x].pass == 0)
        path_creator(as, y - 1, x);
    if (as->room < as->set->level_max && x < as->set->size_max - 1 &&
    as->gen[y][x + 1].type == 1 && as->gen[y][x + 1].pass == 0)
        path_creator(as, y, x + 1);
    if (as->room < as->set->level_max && x > 0 && as->gen[y][x - 1].type == 1
    && as->gen[y][x - 1].pass == 0)
        path_creator(as, y, x - 1);
}

void path2(as_t *as, int y, int x)
{
    if (as->room < as->set->level_max && y > 0 && as->gen[y - 1][x].type == 1
    && as->gen[y - 1][x].pass == 0)
        path_creator(as, y - 1, x);
    if (as->room < as->set->level_max && x < as->set->size_max - 1 &&
    as->gen[y][x + 1].type == 1 && as->gen[y][x + 1].pass == 0)
        path_creator(as, y, x + 1);
    if (as->room < as->set->level_max && x > 0 && as->gen[y][x - 1].type == 1
    && as->gen[y][x - 1].pass == 0)
        path_creator(as, y, x - 1);
    if (as->room < as->set->level_max && y < as->set->size_max - 1 &&
    as->gen[y + 1][x].type == 1 && as->gen[y + 1][x].pass == 0)
        path_creator(as, y + 1, x);
}

void path3(as_t *as, int y, int x)
{
    if (as->room < as->set->level_max && x < as->set->size_max - 1 &&
    as->gen[y][x + 1].type == 1 && as->gen[y][x + 1].pass == 0)
        path_creator(as, y, x + 1);
    if (as->room < as->set->level_max && x > 0 && as->gen[y][x - 1].type == 1
    && as->gen[y][x - 1].pass == 0)
        path_creator(as, y, x - 1);
    if (as->room < as->set->level_max && y < as->set->size_max - 1 &&
    as->gen[y + 1][x].type == 1 && as->gen[y + 1][x].pass == 0)
        path_creator(as, y + 1, x);
    if (as->room < as->set->level_max && y > 0 && as->gen[y - 1][x].type == 1
    && as->gen[y - 1][x].pass == 0)
        path_creator(as, y - 1, x);
}

void path4(as_t *as, int y, int x)
{
    if (as->room < as->set->level_max && x > 0 && as->gen[y][x - 1].type == 1
    && as->gen[y][x - 1].pass == 0)
        path_creator(as, y, x - 1);
    if (as->room < as->set->level_max && y < as->set->size_max - 1 &&
    as->gen[y + 1][x].type == 1 && as->gen[y + 1][x].pass == 0)
        path_creator(as, y + 1, x);
    if (as->room < as->set->level_max && y > 0 && as->gen[y - 1][x].type == 1
    && as->gen[y - 1][x].pass == 0)
        path_creator(as, y - 1, x);
    if (as->room < as->set->level_max && x < as->set->size_max - 1 &&
    as->gen[y][x + 1].type == 1 && as->gen[y][x + 1].pass == 0)
        path_creator(as, y, x + 1);
}

void da_path(as_t *as, int y, int x)
{
    int nb = rand() % 4;

    if (nb == 0)
        path1(as, y, x);
    if (nb == 1)
        path2(as, y, x);
    if (nb == 2)
        path3(as, y, x);
    if (nb == 3)
        path4(as, y, x);
}