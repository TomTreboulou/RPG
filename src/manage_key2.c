/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** manage_key2
*/

// A LA NORME

#include "project.h"

void move_character(sfClock *clock, obj_t *obj, int anim)
{
    obj->rect.left += 67;
    if (obj->rect.left > 67 * (anim - 1))
        obj->rect.left = 0;
    sfSprite_setTextureRect(obj->spr, obj->rect);
    sfClock_restart(clock);
}

int anim_isaac(obj_t *obj, int anim, win_t *time)
{
    if (time->seconds > 0.09)
        move_character(time->clock, obj, anim);
    return (0);
}

void move_mob(sfClock *clock, isaac_t *player, int anim)
{
    player->rect.left += 80;
    if (player->rect.left > 80 * (anim - 1))
        player->rect.left = 0;
    sfSprite_setTextureRect(player->spr, player->rect);
    sfClock_restart(player->clock);
}

int anim_mob(isaac_t *player)
{
    player->time = sfClock_getElapsedTime(player->clock);
    player->second = player->time.microseconds / 1000000.0;
    if (player->second > 0.09)
        move_mob(player->clock, player, 4);
    return (0);
}