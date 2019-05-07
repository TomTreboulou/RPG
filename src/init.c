/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init
*/

// A LA NORME

#include "project.h"

void init_isaac(as_t *as)
{
    as->is = malloc(sizeof(isaac_t));
    as->is->clock = sfClock_create();
    as->is->pos = (sfVector2f){800, 450};
    as->is->speed = 6;
    as->is->s_attack = 4;
    as->is->attack_s = 7;
    as->is->damage = 5;
    as->is->size_bullet = 1;
    as->is->max_life = 6;
    as->is->life = 6;
    as->is->spr = sfSprite_create();
    as->is->text = sfTexture_createFromFile("res/health.png", NULL);
    as->is->rect = (sfIntRect){0, 0, 288, 222};
    sfSprite_setTexture(as->is->spr, as->is->text, sfTrue);
    sfSprite_setTextureRect(as->is->spr, as->is->rect);
    as->is->money = 0;
    as->is->bomb = 0;
    as->is->ghost = 0;
    as->is->fire = (sfVector2i){0, 0};
    init_quest(as);
}

entity_t *init_bullet(as_t *as)
{
    entity_t *ent = malloc(sizeof(entity_t));

    ent->type = -1;
    ent->dir = (sfVector2f){0, 0};
    ent->pos = (sfVector2f){0, 0};
    ent->spr = NULL;
    ent->text = NULL;
    ent->next = NULL;
    ent->prev = NULL;
    return (ent);
}

list_t *init_mobs(as_t *as)
{
    list_t *list = malloc(sizeof(list_t));

    list->next = NULL;
    list->prev = NULL;
    list->type = -1;
    list->player = malloc(sizeof(isaac_t));
    list->player->clock = NULL;
    list->player->second = 0;
    list->player->pos = (sfVector2f){0, 0};
    list->player->speed = 0;
    list->player->s_attack = 0;
    list->player->attack_s = 0;
    list->player->damage = 0;
    list->player->size_bullet = 0;
    list->player->life = 0;
    list->player->spr = NULL;
    list->player->text = NULL;
    return (list);
}

void init_as(as_t *as)
{
    as->ent = init_bullet(as);
    init_isaac(as);
    as->is->nb_quest = 0;
    as->var = malloc(sizeof(var_t));
    as->spr = malloc(sizeof(sprt_t));
    as->win = malloc(sizeof(win_t));
    as->son = malloc(sizeof(sound_t));
    as->player = init_mobs(as);
    as->set = init_settings(as);
    as->down = 0;
    as->left = 0;
    as->right = 0;
    as->up = 0;
    as->last = 0;
    as->x = as->set->size_max / 2;
    as->y = as->set->size_max / 2;
    create_inv(as);
    map_creator(as);
}

void state(as_t *as)
{
    while (sfRenderWindow_isOpen(as->win->window)) {
        if (as->var->game_status == 0) {
            menu(as);
        } else if (as->var->game_status == 1) {
            loading(as);
            game(as);
        }
    }
}