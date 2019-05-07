/*
** EPITECH PROJECT, 2018
** event_game.c
** File description:
** event_game function
*/

// A LA NORME

#include "source_toolbox.h"
#include "project.h"

void new_dir(as_t *as)
{
    entity_t *tmp = as->ent;
    sfVector2i ms = sfMouse_getPosition(NULL);
    int nb = 0;

    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->type != -1 && ms.x > tmp->pos.x - 20 && ms.x < tmp->pos.x + 40
        && ms.y > tmp->pos.y - 10 && ms.y < tmp->pos.y + 40) {
            tmp->dir = (sfVector2f){0, 0};
            continue;
        }
        if (tmp->type != -1) {
            nb = sqrt(pow(ms.x - tmp->pos.x + 15, 2) + pow(ms.y -
            tmp->pos.y, 2));
            tmp->dir = (sfVector2f){((ms.x - (tmp->pos.x + 30)) / nb) *
            (as->is->s_attack * 2), ((ms.y - tmp->pos.y) / nb)
            * (as->is->s_attack * 2)};
        }
    }
}

void special_shoot(as_t *as)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && as->seconds >=
    as->is->attack_s / 17) {
        if (as->is->fire.x == 0)
            create_bullet(as, &as->ent, as->is->damage);
        if (as->is->fire.x == 1) {
            create_bullet(as, &as->ent, as->is->damage);
        }
        if (as->is->fire.x == 2)
            triple_shot(as);
        sfClock_restart(as->clock);
        as->time = sfClock_getElapsedTime(as->clock);
        as->seconds = as->time.microseconds / 1000000.0;
    }
    if (as->is->fire.x == 1)
        new_dir(as);
}

void special_bomb(as_t *as)
{
    add_bullet(as, &as->ent, 50, (sfVector2f){5, 0});
    add_bullet(as, &as->ent, 50, (sfVector2f){-5, 0});
    add_bullet(as, &as->ent, 50, (sfVector2f){0, 5});
    add_bullet(as, &as->ent, 50, (sfVector2f){0, -5});
    add_bullet(as, &as->ent, 50, (sfVector2f){2.75, 1.25});
    add_bullet(as, &as->ent, 50, (sfVector2f){1.25, 2.75});
    add_bullet(as, &as->ent, 50, (sfVector2f){3, 3});
    add_bullet(as, &as->ent, 50, (sfVector2f){-1.25, 2.75});
    add_bullet(as, &as->ent, 50, (sfVector2f){-2.75, 1.25});
    add_bullet(as, &as->ent, 50, (sfVector2f){-3, 3});
    add_bullet(as, &as->ent, 50, (sfVector2f){2.75, -1.25});
    add_bullet(as, &as->ent, 50, (sfVector2f){1.25, -2.75});
    add_bullet(as, &as->ent, 50, (sfVector2f){3, -3});
    add_bullet(as, &as->ent, 50, (sfVector2f){-2.75, -1.25});
    add_bullet(as, &as->ent, 50, (sfVector2f){-1.25, -2.75});
    add_bullet(as, &as->ent, 50, (sfVector2f){-3, -3});
}

void event_game2(as_t *as)
{
    if (as->win->event.type == sfEvtClosed)
        sfRenderWindow_close(as->win->window);
    if (as->win->event.type == sfEvtKeyPressed \
    && as->win->event.key.code == sfKeyEscape)
        init_pause(as->win, as->var, as->spr, as->son);
    if (sfKeyboard_isKeyPressed(sfKeyM)) {
        while (sfKeyboard_isKeyPressed(sfKeyM));
        init_map(as);
    }
    special_shoot(as);
    if (sfKeyboard_isKeyPressed(sfKeyI)) {
        while (sfKeyboard_isKeyPressed(sfKeyI));
        init_inv(as);
    }
}

void event_game(as_t *as)
{
    event_game2(as);
    if (sfKeyboard_isKeyPressed(sfKeyLShift) && as->is->second >= 1 &&
    as->is->bomb > 0) {
        if (as->is->fire.y == 0) {
            add_bullet2(as, &as->ent, 50, (sfVector2f){5, 0});
            add_bullet2(as, &as->ent, 50, (sfVector2f){-5, 0});
            add_bullet2(as, &as->ent, 50, (sfVector2f){0, 5});
            add_bullet2(as, &as->ent, 50, (sfVector2f){0, -5});
            add_bullet2(as, &as->ent, 50, (sfVector2f){3, 3});
            add_bullet2(as, &as->ent, 50, (sfVector2f){-3, 3});
            add_bullet2(as, &as->ent, 50, (sfVector2f){3, -3});
            add_bullet2(as, &as->ent, 50, (sfVector2f){-3, -3});
        } else
            special_bomb(as);
        sfClock_restart(as->is->clock);
        as->is->time = sfClock_getElapsedTime(as->is->clock);
        as->is->second = as->is->time.microseconds / 1000000.0;
        as->is->bomb--;
    }
}