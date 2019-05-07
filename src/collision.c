/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** collision.c
*/

// PAS A LA NORME function co2

#include "project.h"
#include "source_toolbox.h"

int block_void(as_t *as, sfVector2f p, sfVector2f a, sfVector2f s)
{
    obs_t *tmp = as->obj;

    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->type == 1 && p.x + s.x + a.x > tmp->pos.x && p.x + a.x <
        tmp->pos.x + 130 && p.y + a.y + s.y > tmp->pos.y && p.y + a.y <
        tmp->pos.y + 120)
            return (1);
        if (tmp->type == 2 && p.x + s.x + a.x > tmp->pos.x && p.x + a.x <
        tmp->pos.x
        + 130 && p.y + a.y + s.y > tmp->pos.y && p.y + a.y < tmp->pos.y + 120)
            return (2);
    }
    return (0);
}

int co3(as_t *as, sfVector2f p, sfVector2f a, sfVector2f s)
{
    obs_t *tmp = as->obj;

    if (p.x + a.x < 76 || p.x + a.x > 1844 - s.x || p.y + a.y < 84 ||
    p.y + a.y > 996 - s.y)
        return (1);
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->type == 1 && p.x + s.x + a.x > tmp->pos.x && p.x + a.x <
        tmp->pos.x + 130 && p.y + a.y + s.y > tmp->pos.y && p.y + a.y <
        tmp->pos.y + 120)
            return (1);
    }
    return (0);
}

void create_loot(as_t *as)
{
    int nb = rand() % 3;
    int type = rand() % 3;

    as->is->ghost++;
    if (nb == 0) {
        if (type == 0) {
            as->is->money++;
        } else if (type == 1) {
            as->is->bomb++;
        } else if (type == 2 && as->is->life < as->is->max_life) {
            as->is->life++;
        }
    }
}

int co2(as_t *as, sfVector2f p, sfVector2f a, int damage)
{
    obs_t *tmp = as->obj;
    list_t *tmp2 = as->player;

    if (p.x + a.x < 76 || p.x + a.x > 1844 - 15 || p.y + a.y < 84 || p.y
    + a.y > 996 - 30)
        return (1);
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->type == 1 && p.x + 15 + a.x > tmp->pos.x && p.x + a.x <
        tmp->pos.x + 130 && p.y + a.y + 30 > tmp->pos.y && p.y + a.y <
        tmp->pos.y + 120)
            return (1);
        if (tmp->type == 2 && p.x + 15 + a.x > tmp->pos.x && p.x + a.x <
        tmp->pos.x + 130 && p.y + a.y + 30 > tmp->pos.y && p.y + a.y <
        tmp->pos.y + 120)
            return (2);
        tmp2 = as->player;
        for (; tmp->type != -1 && tmp2 != NULL; tmp2 = tmp2->next) {
            if (tmp2->type == 1 && p.x + 15 + a.x > tmp2->player->pos.x
            && p.x + a.x < tmp2->player->pos.x + 70 && p.y + a.y + 30 >
            tmp2->player->pos.y && p.y + a.y < tmp2->player->pos.y + 70) {
                tmp2->player->life -= damage;
                if (co3(as, tmp2->player->pos, a, (sfVector2f){60, 60}) != 1) {
                    tmp2->player->pos.x += a.x;
                    tmp2->player->pos.y += a.y;
                }
                if (tmp2->player->life <= 0){
                    create_loot(as);
                    destroy_mob(tmp2);
                }
                return (1);
            }
        }
    }
    return (0);
}

int colli(as_t *as, sfVector2f p, sfVector2f a, sfVector2f s)
{
    if (check_pnj(as, p, a, s) == 1)
        return (1);
    if (p.x + a.x < 76 || p.x + a.x > 1844 - s.x || p.y + a.y < 84 ||
    p.y + a.y > 996 - s.y) return (1);
    return (second_colli(as, p, a, s));
}