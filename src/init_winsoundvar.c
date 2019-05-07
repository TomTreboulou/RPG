/*
** EPITECH PROJECT, 2018
** init_struct.c
** File description:
** program to initialise struct
*/

// A LA NORME

#include "source_toolbox.h"
#include "project.h"

void create_window(win_t *win)
{
    win->mode = (sfVideoMode) {1920, 1080, 32};
    win->window = sfRenderWindow_create(win->mode, "Episaac", \
    sfFullscreen | sfResize | sfClose, NULL);
    win->icon = sfImage_createFromFile("./perso/icon.png");
    sfRenderWindow_setVerticalSyncEnabled(win->window, sfTrue);
    sfRenderWindow_setIcon(win->window, 32, 32, \
    sfImage_getPixelsPtr(win->icon));
    win->clock = sfClock_create();
    win->s_adj = 0;
    error_fps(win);
}

void init_sound_and_text(sound_t *son)
{
    son->bomb = sfText_create();
    son->coin = sfText_create();
    sfText_setCharacterSize(son->bomb, 50);
    sfText_setPosition(son->bomb, (sfVector2f){80, 145});
    sfText_setCharacterSize(son->coin, 50);
    sfText_setPosition(son->coin, (sfVector2f){80, 70});
    sfText_setString(son->bomb, "0");
    sfText_setString(son->coin, "0");
    sfText_setFont(son->bomb, sfFont_createFromFile("perso/isaac_letter.ttf"));
    sfText_setFont(son->coin, sfFont_createFromFile("perso/isaac_letter.ttf"));
    son->menu = sfMusic_createFromFile("./music/menu.ogg");
    sfMusic_setLoop(son->menu, sfTrue);
    sfMusic_setVolume(son->menu, 30.0);
    son->game = sfMusic_createFromFile("./music/game.ogg");
    sfMusic_setLoop(son->game, sfTrue);
    sfMusic_setVolume(son->game, 50.0);
    son->sbc = sfSoundBuffer_createFromFile("./music/clic.ogg");
    son->clic = sfSound_create();
    sfSound_setBuffer(son->clic, son->sbc);
    init_text(son);
}

void destroy(as_t *as)
{
    sfRenderWindow_destroy(as->win->window);
    sfMusic_stop(as->son->game);
    sfMusic_destroy(as->son->game);
    sfMusic_stop(as->son->menu);
    sfMusic_destroy(as->son->menu);
    sfMusic_stop(as->son->boss);
    sfMusic_destroy(as->son->boss);
    sfSoundBuffer_destroy(as->son->sbc);
    sfSound_destroy(as->son->clic);
}

void init_var(var_t *var)
{
    var->game_info = 0;
    var->game_status = 0;
    var->game_pause = 0;
}