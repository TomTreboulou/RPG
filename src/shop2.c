/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** shop2
*/

#include "project.h"

int rand_mod(int a, int b)
{
    int nb = 0;

    while (nb < a || nb > b) {
        nb = rand() % b + 1;
    }
    return (nb);
}

void shopping2(as_t *as, shop_t *shop)
{
    if (shop->nb3 != -1) {
        sfSprite_setTexture(shop->obj3,
        sfTexture_createFromFile(cnc(cnc("res/item", cni2(shop->nb3)),
        ".png"), NULL), sfTrue);
        sfSprite_setPosition(shop->obj3, (sfVector2f){1020, 570});
        sfRenderWindow_drawSprite(as->win->window, shop->obj3, NULL);
    }
}

int purchase2(as_t *as, sfVector2i mouse, shop_t *shop)
{
    if (mouse.x >= 1025 && mouse.x <= 1125 && mouse.y >= 570 && mouse.y <=
    670 && shop->nb3 != -1) {
        as->is->money -= 25;
        add_obj(as, shop->nb3);
        give_stats(as, shop->nb3);
        set_obj(as);
        return (1);
    }
    return (0);
}

void init_clock(as_t *as)
{
    as->win->mousepos = sfMouse_getPosition(NULL);
    as->win->time = sfClock_getElapsedTime(as->win->clock);
    as->win->seconds = as->win->time.microseconds / 1000000.0;
    as->time = sfClock_getElapsedTime(as->clock);
    as->seconds = as->time.microseconds / 1000000.0;
    as->is->time = sfClock_getElapsedTime(as->is->clock);
    as->is->second = as->is->time.microseconds / 1000000.0;
    as->is->rect = (sfIntRect){0, 0, 5 + 48 * as->is->life, 222};
}

void killer(as_t *as, list_t *tmp)
{
    destroy_mob(tmp);
    as->is->life--;
    if (as->is->life <= 0)
        start_again(as);
}