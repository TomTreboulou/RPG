/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** create_mobs
*/

// A LA NORME

#include "project.h"

void create_ghost2(list_t **list, sfVector2f pos, list_t *node)
{
    node->player->money = 0;
    node->player->speed = 3;
    node->player->s_attack = 5;
    node->player->attack_s = 0.5;
    node->next = NULL;
    node->prev = *list;
    node->type = 1;
    (*list)->next = node;
    *list = node;
    for (; (*list)->prev != NULL; (*list) = (*list)->prev);
}

void create_ghost(list_t **list, sfVector2f pos)
{
    list_t *node = malloc(sizeof(list_t));

    for (; (*list)->next != NULL; (*list) = (*list)->next);
    node->player = malloc(sizeof(isaac_t));
    node->player->clock = sfClock_create();
    node->player->time = sfClock_getElapsedTime(node->player->clock);
    node->player->second = node->player->time.microseconds / 1000000.0;
    node->player->pos = pos;
    node->player->damage = 1;
    node->player->size_bullet = 1;
    node->player->life = 75;
    node->player->text = sfTexture_createFromFile("perso/mobs.png", NULL);
    node->player->spr = sfSprite_create();
    node->player->rect = (sfIntRect){0, 0, 80, 80};
    sfSprite_setTexture(node->player->spr, node->player->text, sfTrue);
    sfSprite_setTextureRect(node->player->spr, node->player->rect);
    sfSprite_setPosition(node->player->spr, pos);
    create_ghost2(list, pos, node);
}