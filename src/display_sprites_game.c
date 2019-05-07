/*
** EPITECH PROJECT, 2018
** display_sprites_menu.c
** File description:
** event_menu function
*/

// A LA NORME

#include "source_toolbox.h"
#include "project.h"

void rect(sfIntRect *rect, int offset, int max_value, int reset_value)
{
    if (rect->left <= max_value - offset)
        rect->left += offset;
    else
        rect->left = reset_value;
}

void animation_sprites(win_t *win, var_t *var, sprt_t *spr)
{

}

void move_sprites_game(win_t *win, var_t *var, sprt_t *spr, sound_t *son)
{

}

void display_sprites_game(win_t *win, var_t *var, sprt_t *spr, sound_t *son)
{
    sfRenderWindow_clear(win->window, sfBlack);
    sfRenderWindow_drawSprite(win->window, spr->back_game->spr, NULL);
}