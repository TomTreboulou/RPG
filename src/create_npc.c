/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** create npc
*/

// A LA NORME

#include "project.h"

int obs(int nb)
{
    if (nb < 0)
        return (-nb);
    return (nb);
}

void new_floor(as_t *as)
{
    map_creator(as);
    as->gen[as->set->size_max / 2][as->set->size_max / 2].type = 1;
    as->x = as->set->size_max / 2;
    as->y = as->set->size_max / 2;
    as->is->pos.x = 930;
    as->is->pos.y = 500;
    as->is->money += 10;
    as->is->nb_quest = 0;
    as->player = init_mobs(as);
    as->obj = generate_room(as->gen[as->y][as->x].map);
}

void draw_npc(as_t *as)
{
    if (as->gen[as->y][as->x].type == 2)
        new_floor(as);
    if (as->x == as->set->size_max / 2 && as->y == as->set->size_max / 2) {
        sfRenderWindow_drawSprite(as->win->window, as->spr->htp->spr, NULL);
        sfRenderWindow_drawSprite(as->win->window,
        as->spr->npc_quest->spr, NULL);
        sfRenderWindow_drawSprite(as->win->window,
        as->spr->npc_coin->spr, NULL);
    }
}