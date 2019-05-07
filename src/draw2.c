/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** draw2
*/

// A LA NORME

#include "project.h"

void draw_text(as_t *as)
{
    sfText_setString(as->son->bomb, cni2(as->is->bomb));
    sfText_setString(as->son->coin, cni2(as->is->money));
    sfRenderWindow_drawText(as->win->window, as->son->bomb, NULL);
    sfRenderWindow_drawText(as->win->window, as->son->coin, NULL);
}

void rpg2(as_t *as)
{
    for (; as->obj->next != NULL; as->obj = as->obj->next)
        if (as->obj->type != -1)
            sfRenderWindow_drawSprite(as->win->window, as->obj->hit, NULL);
    if (as->obj->next == NULL && as->obj->type != -1)
        sfRenderWindow_drawSprite(as->win->window, as->obj->hit, NULL);
    for (; as->obj->prev != NULL; as->obj = as->obj->prev);
    draw_npc(as);
    print_bullet(as);
    draw_ennemis(as);
    draw_isaac(as);
    draw_text(as);
    print_quest(as);
    for (; as->ent->prev != NULL; as->ent = as->ent->prev);
    sfRenderWindow_display(as->win->window);
}