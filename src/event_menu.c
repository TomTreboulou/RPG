/*
** EPITECH PROJECT, 2018
** event_menu.c
** File description:
** event_menu function
*/

// A LA NORME

#include "source_toolbox.h"
#include "project.h"

void event_menu_bis(win_t *win, var_t *var, sprt_t *spr, sound_t *son)
{
    if ((sfMouse_isButtonPressed(sfMouseLeft) && win->mousepos.x >= \
    spr->menu_start->pos.x && win->mousepos.x <= spr->menu_start->pos.x + 400 \
    && win->mousepos.y >= spr->menu_start->pos.y + win->s_adj && \
    win->mousepos.y <= spr->menu_start->pos.y + 150 + win->s_adj) || \
    (win->event.type == sfEvtKeyPressed && win->event.key.code == \
    sfKeyReturn) && var->game_status == 0) {
        var->game_status = 1;
        sfSound_play(son->clic);
    }
    if (win->event.type == sfEvtClosed)
        sfRenderWindow_close(win->window);
    if ((sfMouse_isButtonPressed(sfMouseLeft) && win->mousepos.x >= \
    spr->menu_quit->pos.x && win->mousepos.x <= spr->menu_quit->pos.x + 400 && \
    win->mousepos.y >= spr->menu_quit->pos.y + win->s_adj && win->mousepos.y \
    <= spr->menu_quit->pos.y + 150 + win->s_adj) || (win->event.type == \
    sfEvtKeyPressed && win->event.key.code == sfKeyEscape)) {
        sfRenderWindow_close(win->window);
    }
}

void event_menu(win_t *win, var_t *var, sprt_t *spr, sound_t *son)
{
    if ((sfMouse_isButtonPressed(sfMouseLeft) && win->mousepos.x >= \
    spr->menu_info->pos.x && win->mousepos.x <= spr->menu_info->pos.x + 400 && \
    win->mousepos.y >= spr->menu_info->pos.y + win->s_adj && win->mousepos.y \
    <= spr->menu_info->pos.y + 150 + win->s_adj) && var->game_info == 1) {
        var->game_info = 0;
        sfSound_play(son->clic);
    } else if ((sfMouse_isButtonPressed(sfMouseLeft) && win->mousepos.x >= \
    spr->menu_info->pos.x && win->mousepos.x <= spr->menu_info->pos.x + 400 && \
    win->mousepos.y >= spr->menu_info->pos.y + win->s_adj && win->mousepos.y \
    <= spr->menu_info->pos.y + 150 + win->s_adj) && var->game_info == 0) {
        var->game_info = 1;
        sfSound_play(son->clic);
    }
    event_menu_bis(win, var, spr, son);
}