/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** free
*/

// A LA NORME

#include "project.h"
#include "source_toolbox.h"

int free_mob(isaac_t *p)
{
    sfSprite_destroy(p->spr);
    sfTexture_destroy(p->text);
    sfClock_destroy(p->clock);
    free(p);
    return (0);
}

void free_mobs(list_t *list)
{
    for (; list->next != NULL; list = list->next);
    for (; list->prev != NULL; list = list->prev) {
        sfSprite_destroy(list->player->spr);
        sfTexture_destroy(list->player->text);
        sfClock_destroy(list->player->clock);
    }
    for (; list->next != NULL; list = list->next);
    for (; list->prev != NULL; list = list->prev)
        free(list->next);
}

void free_map(obs_t *obj)
{
    for (; obj->next != NULL; obj = obj->next);
    for (; obj->prev != NULL; obj = obj->prev) {
        sfSprite_destroy(obj->hit);
        sfTexture_destroy(obj->font);
    }
    for (; obj->next != NULL; obj = obj->next);
    for (; obj->prev != NULL; obj = obj->prev)
        free(obj->next);
}

void free_bullet(entity_t *ent)
{
    for (; ent->next != NULL; ent = ent->next);
    for (; ent->prev != NULL; ent = ent->prev) {
        sfSprite_destroy(ent->spr);
        sfTexture_destroy(ent->text);
    }
    for (; ent->next != NULL; ent = ent->next);
    for (; ent->prev != NULL; ent = ent->prev)
        free(ent->next);
}

void generate_mobs(as_t *as)
{
    int count = rand() % 6;
    sfVector2f pos = (sfVector2f){0, 0};

    for (; count != 0;) {
        pos.x = rand() % 1750;
        pos.y = rand() % 910;
        if (pos.x > 90 && pos.y > 90 && obs(as->is->pos.x - pos.x) > 300 &&
        obs(as->is->pos.y - pos.y) > 300 && block_void(as, pos,
        (sfVector2f){0, 0}, (sfVector2f){80, 80}) == 0) {
            count--;
            create_ghost(&as->player, pos);
        }
    }
}