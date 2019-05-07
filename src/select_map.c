/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** select_map
*/

// A LA NORME

#include "project.h"

void select_map2(as_t *as, int i, int j, sfVector2i pos)
{
    sfSprite *spr;
    sfTexture *text;

    if (as->gen[i][j].pass == 1 && as->gen[i][j].type == 0 && ((j
    > 0 && as->gen[i][j - 1].type == 1) || (j < as->set->size_max - 1 &&
    as->gen[i][j + 1].type == 1) || (i > 0 &&
    as->gen[i - 1][j].type == 1) || (i < as->set->size_max - 1 &&
    as->gen[i + 1][j].type == 1))) {
        spr = sfSprite_create();
        text = sfTexture_createFromFile("res/map_g.png", NULL);
        sfSprite_setPosition(spr, (sfVector2f){910 + pos.x + j * 100 +
        as->x * -100, 490 + pos.y + i * 100 + as->y * -100});
        sfSprite_setTexture(spr, text, sfTrue);
        sfRenderWindow_drawSprite(as->win->window, spr, NULL);
    }
}

void select_map3(as_t *as, sfVector2i pos, int i, int j)
{
    sfSprite *spr;
    sfTexture *text;

    spr = sfSprite_create();
    text = sfTexture_createFromFile("res/map_v.png", NULL);
    sfSprite_setPosition(spr, (sfVector2f){910 + pos.x + j * 100 +
    as->x * -100, 490 + pos.y + i * 100 + as->y * -100});
    sfSprite_setTexture(spr, text, sfTrue);
    sfRenderWindow_drawSprite(as->win->window, spr, NULL);
}

void select_map(as_t *as, int i, int j, sfVector2i pos)
{
    sfSprite *spr;
    sfTexture *text;

    if (as->gen[i][j].type == 2) {
        select_map3(as, pos, i, j);
    } else if (as->gen[i][j].type == 1) {
        spr = sfSprite_create();
        if ((i == as->y && j == as->x) || (i == as->set->size_max / 2 &&
        j == as->set->size_max / 2))
            text = sfTexture_createFromFile("res/map_r.png", NULL);
        else
            text = sfTexture_createFromFile("res/map_w.png", NULL);
        sfSprite_setPosition(spr, (sfVector2f){910 + pos.x + j * 100 +
        as->x * -100, 490 + pos.y + i * 100 + as->y * -100});
        sfSprite_setTexture(spr, text, sfTrue);
        sfRenderWindow_drawSprite(as->win->window, spr, NULL);
    } else
        select_map2(as, i, j, pos);
}
