/*
** EPITECH PROJECT, 2018
** my_main.c
** File description:
** program main function
*/

// A LA NORME

#include "source_toolbox.h"
#include "project.h"

void init_pause(win_t *win, var_t *var, sprt_t *spr, sound_t *son)
{
    var->game_pause = 1;

    sfRenderWindow_drawSprite(win->window, spr->game_pause->spr, NULL);
    sfRenderWindow_drawSprite(win->window, spr->pause_resume->spr, NULL);
    sfRenderWindow_drawSprite(win->window, spr->pause_quit->spr, NULL);
    sfRenderWindow_display(win->window);
}

void print_pause(win_t *win, var_t *var, sprt_t *spr, sound_t *son)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win->window);

    if (mouse.x >= 550 && mouse.x <= 950 && mouse.y >= 600 && mouse.y <= 750)
        sfRenderWindow_drawSprite(win->window, spr->pause_resume_s->spr, NULL);
    else
        sfRenderWindow_drawSprite(win->window, spr->pause_resume->spr, NULL);
    if (mouse.x >= 1050 && mouse.x <= 1450 && mouse.y >= 600 && mouse.y <= 750)
        sfRenderWindow_drawSprite(win->window, spr->pause_quit_s->spr, NULL);
    else
        sfRenderWindow_drawSprite(win->window, spr->pause_quit->spr, NULL);
    sfRenderWindow_display(win->window);
}

void event_pause(win_t *win, var_t *var, sprt_t *spr, sound_t *son)
{
    if ((sfMouse_isButtonPressed(sfMouseLeft) && win->mousepos.x >=
    spr->pause_quit->pos.x && win->mousepos.x <= spr->pause_quit->pos.x + 400
    && win->mousepos.y >= spr->pause_quit->pos.y + win->s_adj &&
    win->mousepos.y <= spr->pause_quit->pos.y + 150 + win->s_adj) ||
    (win->event.type == sfEvtKeyPressed && win->event.key.code ==
    sfKeyEscape)) {
        var->game_status = 0;
        var->game_pause = 0;
        sfSound_play(son->clic);
    } if ((sfMouse_isButtonPressed(sfMouseLeft) && win->mousepos.x >= \
    spr->pause_resume->pos.x && win->mousepos.x <= spr->pause_resume->pos.x \
    + 400 && win->mousepos.y >= spr->pause_resume->pos.y + win->s_adj && \
    win->mousepos.y <= spr->pause_resume->pos.y + 150 + win->s_adj) || \
    (win->event.type == sfEvtKeyPressed && (win->event.key.code == sfKeyReturn \
    || win->event.key.code == sfKeyP))) {
        var->game_pause = 0;
        sfSound_play(son->clic);
    }
}

void game_pause(win_t *win, var_t *var, sprt_t *spr, sound_t *son)
{
    sfMusic_pause(son->game);
    while (sfRenderWindow_isOpen(win->window) && var->game_pause == 1) {
        win->mousepos = sfMouse_getPosition(NULL);
        print_pause(win, var, spr, son);
        while (sfRenderWindow_pollEvent(win->window, &win->event))
            event_pause(win, var, spr, son);
    }
    sfMusic_play(son->game);
}