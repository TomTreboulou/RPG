/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** dra
*/

// A LA NORME

#include "project.h"

void draw_isaac3(as_t *as)
{
    if (as->last == 2) {
        as->spr->right->rect.left = 0;
        sfSprite_setTextureRect(as->spr->right->spr, as->spr->right->rect);
        sfRenderWindow_drawSprite(as->win->window, as->spr->right->spr, NULL);
    }
    if (as->last == 3) {
        as->spr->left->rect.left = 0;
        sfSprite_setTextureRect(as->spr->left->spr, as->spr->left->rect);
        sfRenderWindow_drawSprite(as->win->window, as->spr->left->spr, NULL);
    }
}

void draw_isaac2(as_t *as)
{
    if (as->left == 1 && as->right == 0 && as->down == 0 && as->up == 0) {
        sfRenderWindow_drawSprite(as->win->window, as->spr->left->spr, NULL);
        as->last = 3;
        return;
    }
    if (as->last == 0) {
        as->spr->down->rect.left = 0;
        sfSprite_setTextureRect(as->spr->down->spr, as->spr->down->rect);
        sfRenderWindow_drawSprite(as->win->window, as->spr->down->spr, NULL);
    }
    if (as->last == 1) {
        as->spr->up->rect.left = 67;
        sfSprite_setTextureRect(as->spr->up->spr, as->spr->up->rect);
        sfRenderWindow_drawSprite(as->win->window, as->spr->up->spr, NULL);
    }
    draw_isaac3(as);
}

void draw_isaac(as_t *as)
{
    sfSprite_setTextureRect(as->is->spr, as->is->rect);
    sfRenderWindow_drawSprite(as->win->window, as->is->spr, NULL);
    if ((as->up == 1 && as->left == 1) || (as->up == 1 && as->right == 1) ||
    (as->up == 1 && as->down == 0)) {
        sfRenderWindow_drawSprite(as->win->window, as->spr->up->spr, NULL);
        as->last = 1;
        return;
    }
    if ((as->down == 1 && as->left == 1) || (as->down == 1 && as->right == 1)
    || (as->down == 1 && as->up == 0)) {
        sfRenderWindow_drawSprite(as->win->window, as->spr->down->spr, NULL);
        as->last = 0;
        return;
    }
    if (as->right == 1 && as->left == 0 && as->down == 0 && as->up == 0) {
        sfRenderWindow_drawSprite(as->win->window, as->spr->right->spr, NULL);
        as->last = 2;
        return;
    }
    draw_isaac2(as);
}

void print_bullet(as_t *as)
{
    entity_t *tmp = as->ent;
    int check = 0;

    for (; tmp != NULL; tmp = tmp->next, check = 0) {
        if (tmp->type != -1 && (check = co2(as, tmp->pos,
        (sfVector2f){tmp->dir.x, tmp->dir.y}, tmp->damage)) != 1) {
            tmp->pos.x += tmp->dir.x;
            tmp->pos.y += tmp->dir.y;
            sfSprite_setPosition(tmp->spr, tmp->pos);
            sfRenderWindow_drawSprite(as->win->window, tmp->spr, NULL);
        } else if (tmp->type != -1 && check == 1)
            destroy_bullet(tmp);
    }
}

void draw_ennemis(as_t *as)
{
    list_t *tmp = as->player;

    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->type != -1) {
            sfRenderWindow_drawSprite(as->win->window, tmp->player->spr, NULL);
        }
    }
}