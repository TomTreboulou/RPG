/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** shoot
*/

// A LA NORMES

#include "project.h"
#include "source_toolbox.h"

void add_bullet2(as_t *as, entity_t **last, int damage, sfVector2f dir)
{
    entity_t *bullet = malloc(sizeof(entity_t));
    sfVector2i ms = sfMouse_getPosition(NULL);

    for (; (*last)->next != NULL; (*last) = (*last)->next);
    bullet->dir = dir;
    bullet->pos = (sfVector2f){as->is->pos.x + 20, as->is->pos.y + 10};
    bullet->type = 1;
    bullet->damage = damage;
    bullet->text = sfTexture_createFromFile("res/tears.png", NULL);
    bullet->spr = sfSprite_create();
    sfSprite_setTexture(bullet->spr, bullet->text, sfTrue);
    bullet->next = NULL;
    bullet->prev = *last;
    (*last)->next = bullet;
    *last = bullet;
    for (; (*last)->prev != NULL; (*last) = (*last)->prev);
}

void add_bullet(as_t *as, entity_t **last, int damage, sfVector2f dir)
{
    entity_t *bullet = malloc(sizeof(entity_t));
    sfVector2i ms = sfMouse_getPosition(NULL);

    for (; (*last)->next != NULL; (*last) = (*last)->next);
    bullet->dir = dir;
    bullet->pos = (sfVector2f){ms.x, ms.y};
    bullet->type = 1;
    bullet->damage = damage;
    bullet->text = sfTexture_createFromFile("res/tears.png", NULL);
    bullet->spr = sfSprite_create();
    sfSprite_setTexture(bullet->spr, bullet->text, sfTrue);
    bullet->next = NULL;
    bullet->prev = *last;
    (*last)->next = bullet;
    *last = bullet;
    for (; (*last)->prev != NULL; (*last) = (*last)->prev);
}

void create_bullet(as_t *as, entity_t **last, int damage)
{
    entity_t *bullet = malloc(sizeof(entity_t));
    sfVector2i ms = sfMouse_getPosition(NULL);
    int nb = sqrt(pow(ms.x - as->is->pos.x + 30, 2) + pow(ms.y -
    as->is->pos.y, 2));

    for (; (*last)->next != NULL; (*last) = (*last)->next);
    bullet->dir = (sfVector2f){((ms.x - (as->is->pos.x + 30)) / nb) *
    (as->is->s_attack * 2), ((ms.y - as->is->pos.y) / nb)
    * (as->is->s_attack * 2)};
    bullet->pos = (sfVector2f){as->is->pos.x + 33, as->is->pos.y + 15};
    bullet->type = 1;
    bullet->damage = damage;
    bullet->text = sfTexture_createFromFile("perso/tears.png", NULL);
    bullet->spr = sfSprite_create();
    sfSprite_setTexture(bullet->spr, bullet->text, sfTrue);
    bullet->next = NULL;
    bullet->prev = *last;
    (*last)->next = bullet;
    *last = bullet;
    for (; (*last)->prev != NULL; (*last) = (*last)->prev);
}

int destroy_mob(list_t *mob)
{
    mob->type = -1;
    if (mob->next == NULL && mob->prev != NULL) {
        return (free_mob(mob->player));
    } else if (mob->next != NULL && mob->prev == NULL) {
        mob->next->prev = NULL;
        mob->next = mob->prev;
        return (free_mob(mob->player));
    } else if (mob->next != NULL && mob->prev != NULL){
        mob->prev->next = mob->next;
        mob->next->prev = mob->prev;
        mob->next = mob->prev;
        return (free_mob(mob->player));
    }
}

int destroy_bullet(entity_t *bullet)
{
    bullet->type = -1;
    if (bullet->next == NULL && bullet->prev != NULL) {
        bullet = NULL;
        return (0);
    } else if (bullet->next != NULL && bullet->prev == NULL) {
        bullet->next->prev = NULL;
        bullet->next = bullet->prev;
        return (0);
    } else if (bullet->next != NULL && bullet->prev != NULL) {
        bullet->prev->next = bullet->next;
        bullet->next->prev = bullet->prev;
        bullet->next = bullet->prev;
        return (0);
    }
}