/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** settings
*/

// A LA NORME

#include "project.h"

void set_type(settings_t *set)
{
    sfVector2i mouse = sfMouse_getPosition(NULL);
}

settings_t *init_settings(as_t *as)
{
    settings_t *set = malloc(sizeof(settings_t));

    set->room_max = 4;
    set->luck = 10;
    set->size_max = 20;
    set->level_max = 100;
    set->volume_game = 30.0;
    set->volume_music = 75.0;
    return (set);
}