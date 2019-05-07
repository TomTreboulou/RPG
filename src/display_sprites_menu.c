/*
** EPITECH PROJECT, 2018
** display_sprites_menu.c
** File description:
** event_menu function
*/

// A LA NORME

#include "source_toolbox.h"
#include "project.h"

void display_sprites_menu(win_t *win, var_t *var, sprt_t *spr, sound_t *son)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win->window);

    sfRenderWindow_clear(win->window, sfBlack);
    sfRenderWindow_drawSprite(win->window, spr->back_menu->spr, NULL);
    if (mouse.x >= 800 && mouse.x <= 1200 && mouse.y >= 850 && mouse.y <= 1000)
        sfRenderWindow_drawSprite(win->window, spr->menu_start_s->spr, NULL);
    else
        sfRenderWindow_drawSprite(win->window, spr->menu_start->spr, NULL);
    if (mouse.x >= 200 && mouse.x <= 600 && mouse.y >= 850 && mouse.y <= 1000)
        sfRenderWindow_drawSprite(win->window, spr->menu_info_s->spr, NULL);
    else
        sfRenderWindow_drawSprite(win->window, spr->menu_info->spr, NULL);
    display_sprites_menu_b(win, var, spr, son);
}

void display_sprites_menu_b(win_t *win, var_t *var, sprt_t *spr, sound_t *son)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win->window);

    if (mouse.x >= 1400 && mouse.x <= 1800 && mouse.y >= 850 && mouse.y <= 1000)
        sfRenderWindow_drawSprite(win->window, spr->menu_quit_s->spr, NULL);
    else
        sfRenderWindow_drawSprite(win->window, spr->menu_quit->spr, NULL);
    if (var->game_info == 1) {
        sfRenderWindow_drawSprite(win->window, spr->rules->spr, NULL);
    }
}