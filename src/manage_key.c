/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** manage_key
*/

// A LA NORME function

#include "project.h"

void start_again(as_t *as)
{
    init_isaac(as);
    create_inv(as);
    as->is->nb_quest = 0;
    as->player = init_mobs(as);
    for (int i = 0; i < as->set->size_max; i++) {
        for (int j = 0; j < as->set->size_max; j++)
            as->gen[i][j].type = 0;
    }
    as->gen[as->set->size_max / 2][as->set->size_max / 2].type = 1;
    as->x = as->set->size_max / 2;
    as->y = as->set->size_max / 2;
    game(as);
}

void move_ennemis2(as_t *as, list_t *tmp, sfVector2f dir)
{
    if (tmp->type == 1 && co3(as, tmp->player->pos, dir,
    (sfVector2f){60, 60}) != 1) {
        tmp->player->pos.x += dir.x;
        tmp->player->pos.y += dir.y;
        sfSprite_setPosition(tmp->player->spr, tmp->player->pos);
    } else if (tmp->type == 1 && co3(as, tmp->player->pos,
    (sfVector2f){dir.x, 0}, (sfVector2f){60, 60}) != 1) {
        tmp->player->pos.x += dir.x;
        sfSprite_setPosition(tmp->player->spr, tmp->player->pos);
    } else if (tmp->type == 1 && co3(as, tmp->player->pos,
    (sfVector2f){0, dir.y}, (sfVector2f){60, 60}) != 1) {
        tmp->player->pos.y += dir.y;
        sfSprite_setPosition(tmp->player->spr, tmp->player->pos);
    }
}

void move_ennemis(as_t *as)
{
    list_t *tmp = as->player;
    sfVector2f dir = (sfVector2f){0, 0};
    int nb = 0;

    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->type == 1) {
            anim_mob(tmp->player);
            nb = sqrt(pow(tmp->player->pos.x - as->is->pos.x, 2) +
            pow(tmp->player->pos.y - as->is->pos.y, 2));
            dir = (sfVector2f){((as->is->pos.x - tmp->player->pos.x) / nb) *
            tmp->player->speed, ((as->is->pos.y - tmp->player->pos.y) / nb) *
            tmp->player->speed};
        }
        if (tmp->type == 1 && tmp->player->pos.x + dir.x + 80 > as->is->pos.x
        && tmp->player->pos.x + dir.x < as->is->pos.x + 67 &&
        tmp->player->pos.y + dir.y + 60 > as->is->pos.y && tmp->player->pos.y
        + dir.y < as->is->pos.y + 60)
            killer(as, tmp);
        move_ennemis2(as, tmp, dir);
    }
}

void manage_key_2(as_t *as)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ) && !colli(as, as->is->pos,
    (sfVector2f){0, -as->is->speed}, (sfVector2f){60, 80})) {
        anim_isaac(as->spr->up, 2, as->win);
        as->is->pos.y -= as->is->speed;
        as->up = 1;
        sfSprite_setPosition(as->spr->up->spr, as->is->pos);
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) && !colli(as, as->is->pos,
    (sfVector2f){0, as->is->speed}, (sfVector2f){60, 80})) {
        anim_isaac(as->spr->down, 8, as->win);
        as->is->pos.y += as->is->speed;
        as->down = 1;
        sfSprite_setPosition(as->spr->down->spr, as->is->pos);
    }
}

void manage_key_character(as_t *as)
{
    as->right = 0;
    as->left = 0;
    as->up = 0;
    as->down = 0;
    if (sfKeyboard_isKeyPressed(sfKeyQ) && !colli(as, as->is->pos,
    (sfVector2f){-as->is->speed, 0}, (sfVector2f){60, 80})) {
        anim_isaac(as->spr->left, 10, as->win);
        as->is->pos.x -= as->is->speed;
        as->left = 1;
        sfSprite_setPosition(as->spr->left->spr, as->is->pos);
    }
    if (sfKeyboard_isKeyPressed(sfKeyD) && !colli(as, as->is->pos,
    (sfVector2f){as->is->speed, 0}, (sfVector2f){60, 80})) {
        anim_isaac(as->spr->right, 10, as->win);
        as->is->pos.x += as->is->speed;
        as->right = 1;
        sfSprite_setPosition(as->spr->right->spr, as->is->pos);
    }
    manage_key_2(as);
}