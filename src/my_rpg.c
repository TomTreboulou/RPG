/*
** EPITECH PROJECT, 2018
** my_main.c
** File description:
** program main function
*/

// A LA NORME

#include "source_toolbox.h"
#include "project.h"

void menu(as_t *as)
{
    sfMusic_play(as->son->menu);
    while (sfRenderWindow_isOpen(as->win->window) && as->var->game_status == 0)
    {
        as->win->mousepos = sfMouse_getPosition(NULL);
        while (sfRenderWindow_pollEvent(as->win->window, &(as->win)->event))
            event_menu(as->win, as->var, as->spr, as->son);
        display_sprites_menu(as->win, as->var, as->spr, as->son);
        sfRenderWindow_display(as->win->window);
    }
    sfMusic_stop(as->son->menu);
}

void print_quest(as_t *as)
{
    if (as->is->quest->type == 1) {
        sfText_setString(as->is->quest->nb, cni2(as->is->quest->number));
        sfText_setString(as->is->quest->money, cni2(as->is->quest->number));
        sfText_setString(as->is->quest->count, cni2(as->is->ghost));
        sfText_setPosition(as->is->quest->nb, (sfVector2f) {1740, 25});
        sfText_setPosition(as->is->quest->money, (sfVector2f) {1825, 103});
        sfText_setPosition(as->is->quest->count, (sfVector2f) {1600, 25});
        sfRenderWindow_drawSprite(as->win->window, as->is->quest->spr, NULL);
        sfRenderWindow_drawText(as->win->window, as->is->quest->money, NULL);
        sfRenderWindow_drawText(as->win->window, as->is->quest->nb, NULL);
        sfRenderWindow_drawText(as->win->window, as->is->quest->count, NULL);
    }
}

void game(as_t *as)
{
    sfClock_restart(as->win->clock);
    sfClock_restart(as->clock);
    sfClock_restart(as->is->clock);
    sfMusic_play(as->son->game);
    as->obj = generate_room(as->gen[as->y][as->x].map);
    while (sfRenderWindow_isOpen(as->win->window) && as->var->game_status == 1)
    {
        init_clock(as);
        while (sfRenderWindow_pollEvent(as->win->window, &(as->win)->event))
            event_game(as);
        if (sfRenderWindow_isOpen(as->win->window) && as->var->game_pause == 1)
            game_pause(as->win, as->var, as->spr, as->son);
        move_sprites_game(as->win, as->var, as->spr, as->son);
        display_sprites_game(as->win, as->var, as->spr, as->son);
        manage_key_character(as);
        move_ennemis(as);
        rpg2(as);
    }
    sfMusic_stop(as->son->game);
}

void loading(as_t *as)
{
    sfTime *timer;
    sfClock *clock;
    int x = 0;

    while (x <= 125) {
        sfRenderWindow_clear(as->win->window, sfBlack);
        sfRenderWindow_drawSprite(as->win->window, as->spr->loading_isaac->
        spr, NULL);
        sfRenderWindow_drawSprite(as->win->window, as->spr->tears->spr, NULL);
        as->spr->tears->pos.y += 4;
        sfSprite_setPosition(as->spr->tears->spr , as->spr->tears->pos);
        sfRenderWindow_drawSprite(as->win->window, as->spr->loading_head->
        spr, NULL);
        sfRenderWindow_display(as->win->window);
        x++;
    }
    as->spr->tears->pos.y = -200;
    return;
}

int main(int ac, char **av, char **env)
{
    as_t *as = malloc(sizeof(as_t));
    int error_output;
    char *tmp = malloc(sizeof(char));

    srand((unsigned long)(tmp));
    init_as(as);
    as->clock = sfClock_create();
    as->gen[as->set->size_max / 2][as->set->size_max / 2].type = 1;
    if ((error_output = error(ac, av, as->win)) != 1)
        return (error_output);
    create_window(as->win);
    init_struct(as);
    state(as);
    destroy(as);
    return (error_output);
}