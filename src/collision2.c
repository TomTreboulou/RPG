/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** collision2
*/

// A LA NORME

#include "project.h"

int move(as_t *as, int x, int y, sfVector2f pos)
{
    as->is->pos.x = pos.x;
    as->is->pos.y = pos.y;
    as->x = x;
    as->y = y;
    sfSprite_setPosition(as->spr->up->spr, as->is->pos);
    sfSprite_setPosition(as->spr->down->spr, as->is->pos);
    sfSprite_setPosition(as->spr->left->spr, as->is->pos);
    sfSprite_setPosition(as->spr->right->spr, as->is->pos);
    free_map(as->obj);
    free_bullet(as->ent);
    as->obj = generate_room(as->gen[y][x].map);
    as->ent = init_bullet(as);
    if (as->gen[as->y][as->x].type == 0)
        generate_mobs(as);
    if (as->gen[as->y][as->x].type != 2)
        as->gen[as->y][as->x].type = 1;
    return (1);
}

void move_player(as_t *as, sfVector2f a)
{
    as->is->pos.x += -a.x * 10;
    as->is->pos.y += -a.y *10;
}

void end_quest(as_t *as)
{
    if (as->is->nb_quest < 3 && check_quest(as) == 0) {
        as->is->nb_quest = 3;
        as->is->quest->type = 0;
    }
    if (as->is->quest->type == 1 && as->is->quest->number <= as->is->ghost) {
        as->is->quest->type = 0;
        as->is->nb_quest++;
        as->is->ghost = 0;
        as->is->money += as->is->quest->number;
    }
    if (as->is->nb_quest == 3) {
        as->is->nb_quest = 4;
        select_boss(as);
    }
}

int check_pnj(as_t *as, sfVector2f p, sfVector2f a, sfVector2f s)
{
    end_quest(as);
    if (as->x == as->set->size_max / 2 && as->y == as->set->size_max / 2 &&
    p.x + a.x + s.x > 1340 && p.x + a.x < 1400 && p.y + a.y + s.y >
    250 && p.y + a.y < 320) {
        shop(as);
        move_player(as, a);
        return (1);
    } else if (as->x == as->set->size_max / 2 && as->y == as->set->size_max
    / 2 && p.x + a.x + s.x > 500 && p.x + a.x < 560 && p.y + a.y + s.y >
    250 && p.y + a.y < 320 && as->is->nb_quest < 3) {
        as->is->ghost = 0;
        as->is->quest->type = 1;
        as->is->quest->number = rand_mod(10, 20);
        move_player(as, a);
        return (1);
    }
    return (0);
}

int second_colli(as_t *as, sfVector2f p, sfVector2f a, sfVector2f s)
{
    list_t *tmp = as->player;
    int check = 0;

    for (int i = 0; tmp != NULL; tmp = tmp->next, i++)
        check += (tmp->type != -1) ? 1 : 0;
    if (as->gen[as->y][as->x].map[4][0] == 'P' && p.y + a.y > 480 &&
    p.y + a.y < 510 && p.x + a.x < 85 && check == 0)
        return (move(as, as->x - 1, as->y, (sfVector2f){1740, 490}));
    if (as->gen[as->y][as->x].map[4][14] == 'P' && p.y + a.y > 480 &&
    p.y + a.y < 510 && p.x + a.x > 1765 && check == 0)
        return (move(as, as->x + 1, as->y, (sfVector2f){120, 490}));
    if (as->gen[as->y][as->x].map[0][7] == 'P' && p.y + a.y < 100 &&
    p.x + a.x > 900 && p.x + a.x < 955 && check == 0)
        return (move(as, as->x, as->y - 1, (sfVector2f){930, 900}));
    if (as->gen[as->y][as->x].map[8][7] == 'P' && p.y + a.y > 910 &&
    p.x + a.x > 900 && p.x + a.x < 955 && check == 0)
        return (move(as, as->x, as->y + 1, (sfVector2f){930, 100}));
    return (block_void(as, p, a, s));
}