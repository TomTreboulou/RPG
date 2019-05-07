/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** inventory3
*/

// A LA NORME

#include "project.h"

void set_print_obj(as_t *as)
{
    sfText_setString(as->son->stat1, cni2(as->is->speed));
    sfText_setString(as->son->stat2, cni2(as->is->attack_s));
    sfText_setString(as->son->stat3, cni2(as->is->damage));
    sfText_setString(as->son->stat4, cni2(as->is->s_attack));
}

void set_obj(as_t *as)
{
    for (int i = 0; as->inv[i].number != -1; i++) {
        if (i >= 5) {
            as->inv[i].pos = (sfVector2f){700 + (110 * (i - 5)), 443};
            sfSprite_setPosition(as->inv[i].spr1, as->inv[i].pos);
        } else if (i < 5) {
            as->inv[i].pos = (sfVector2f){700 + (110 * i), 333};
            sfSprite_setPosition(as->inv[i].spr1, as->inv[i].pos);
        }
    }
}