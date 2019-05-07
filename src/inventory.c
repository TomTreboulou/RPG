/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** inventory
*/

// A LA NORME

#include "project.h"

void free_obj(as_t *as, int nb)
{
    int i = 0;
    for (i = 0; as->inv->number != -1 && as->inv->number != nb; i++);
    sfSprite_destroy(as->inv[i].spr1);
    sfSprite_destroy(as->inv[i].spr2);
    sfTexture_destroy(as->inv[i].text);
    sfTexture_destroy(as->inv[i].text2);
    for (; as->inv->number != -1; i++) {
        as->inv[i] = as->inv[i + 1];
    }
    set_obj(as);
}

void free_stats(as_t *as, int nb)
{
    int i = 0;

    for (; as->inv[i].number != nb; i++);
    as->inv[i].state = 0;
    as->is->speed -= as->inv[i].speed;
    as->is->attack_s -= as->inv[i].attack_s;
    as->is->s_attack -= as->inv[i].s_attack;
    as->is->damage -= as->inv[i].damage;
    as->inv[i].text =
    sfTexture_createFromFile(cnc(cni(cnc("res/item", cni2(nb)), 3), ".png")
    , NULL);
    sfSprite_setTexture(as->inv[i].spr1, as->inv[i].text, sfTrue);
}

void give_stats(as_t *as, int nb)
{
    int i = 0;

    for (; as->inv[i].number != nb; i++);
    as->inv[i].state = 1;
    as->is->speed += as->inv[i].speed;
    as->is->attack_s += as->inv[i].attack_s;
    as->is->s_attack += as->inv[i].s_attack;
    as->is->damage += as->inv[i].damage;
    as->inv[i].text =
    sfTexture_createFromFile(cnc(cnc("res/item", cni2(nb)), ".png"), NULL);
    sfSprite_setTexture(as->inv[i].spr1, as->inv[i].text, sfTrue);
}

void change_state(as_t *as, int nb, int number)
{
    while (sfMouse_isButtonPressed(sfMouseLeft));

    if (as->inv[nb].state == 1) {
        if (number == 7)
            as->is->fire.x = 0;
        else if (number == 8)
            as->is->fire.y = 0;
        else if (number == 5)
            as->is->fire.x = 0;
        free_stats(as, number);
    } else if (as->inv[nb].state == 0) {
        if (number == 7)
            as->is->fire.x = 2;
        else if (number == 8)
            as->is->fire.y = 1;
        else if (number == 5)
            as->is->fire.x = 1;
        give_stats(as, number);
    }
}

void print_obj(as_t *as)
{
    sfVector2i ms = sfMouse_getPosition(NULL);

    set_print_obj(as);
    sfRenderWindow_drawText(as->win->window, as->son->stat1, NULL);
    sfRenderWindow_drawText(as->win->window, as->son->stat2, NULL);
    sfRenderWindow_drawText(as->win->window, as->son->stat3, NULL);
    sfRenderWindow_drawText(as->win->window, as->son->stat4, NULL);
    for (int i = 0; as->inv[i].number != -1; i++) {
        if (ms.x > as->inv[i].pos.x && ms.x < as->inv[i].pos.x + 100 && ms.y
        > as->inv[i].pos.y && ms.y < as->inv[i].pos.y + 100) {
            if (sfMouse_isButtonPressed(sfMouseLeft))
                change_state(as, i, as->inv[i].number);
            sfRenderWindow_drawSprite(as->win->window, as->inv[i].spr2, NULL);
        }
        if (i > 5)
            sfRenderWindow_drawSprite(as->win->window, as->inv[i].spr1, NULL);
        else if (i <= 5)
            sfRenderWindow_drawSprite(as->win->window, as->inv[i].spr1, NULL);
    }
}