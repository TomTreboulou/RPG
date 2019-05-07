/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** event_game2
*/

// A LA NORME

#include "project.h"
#include "source_toolbox.h"

void triple_shot2(as_t *as, int x, int y, sfVector2i ms)
{
    if (x > y && ms.x < as->is->pos.x + 30) {
        add_bullet2(as, &as->ent, as->is->damage,
        (sfVector2f){-as->is->s_attack, -1});
        add_bullet2(as, &as->ent, as->is->damage,
        (sfVector2f){-as->is->s_attack, 0});
        add_bullet2(as, &as->ent, as->is->damage,
        (sfVector2f){-as->is->s_attack, 1});
    } else if (x > y && ms.x > as->is->pos.x + 30) {
        add_bullet2(as, &as->ent, as->is->damage,
        (sfVector2f){as->is->s_attack, -1});
        add_bullet2(as, &as->ent, as->is->damage,
        (sfVector2f){as->is->s_attack, 0});
        add_bullet2(as, &as->ent, as->is->damage,
        (sfVector2f){as->is->s_attack, 1});
    }
}

void triple_shot(as_t *as)
{
    sfVector2i ms = sfMouse_getPosition(NULL);
    int x = obs(as->is->pos.x + 30 - ms.x);
    int y = obs(as->is->pos.y + 40 - ms.y);

    if (x < y && ms.y < as->is->pos.y + 40) {
        add_bullet2(as, &as->ent, as->is->damage,
        (sfVector2f){0, -as->is->s_attack});
        add_bullet2(as, &as->ent, as->is->damage,
        (sfVector2f){1, -as->is->s_attack});
        add_bullet2(as, &as->ent, as->is->damage,
        (sfVector2f){-1, -as->is->s_attack});
    } else if (x < y && ms.y > as->is->pos.y + 40) {
        add_bullet2(as, &as->ent, as->is->damage,
        (sfVector2f){0, as->is->s_attack});
        add_bullet2(as, &as->ent, as->is->damage,
        (sfVector2f){1, as->is->s_attack});
        add_bullet2(as, &as->ent, as->is->damage,
        (sfVector2f){-1, as->is->s_attack});
    }
    triple_shot2(as, x , y, ms);
}

int quit_map(as_t *as)
{
    if (sfKeyboard_isKeyPressed(sfKeyM)) {
        while (sfKeyboard_isKeyPressed(sfKeyM));
        return (1);
    }
    return (0);
}

sfVector2i get_mouse(as_t *as, sfVector2i pos, sfSprite *menu2)
{
    sfVector2i init = sfMouse_getPosition(NULL);
    sfVector2i init2 = (sfVector2i){0, 0};

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        my_usleep(0.01);
        init2 = sfMouse_getPosition(NULL);
        pos.x += init2.x - init.x;
        pos.y += init2.y - init.y;
        sfRenderWindow_clear(as->win->window, sfWhite);
        for (int i = 0; i < as->set->size_max; i++)
            for (int j = 0; j < as->set->size_max; j++)
                select_map(as, i, j, pos);
        sfRenderWindow_drawSprite(as->win->window, menu2, NULL);
        sfRenderWindow_display(as->win->window);
    }
    return (pos);
}

void init_map(as_t *as)
{
    sfSprite *menu2 = sfSprite_create();
    sfTexture *map2 = sfTexture_createFromFile("res/map_e.png", NULL);
    sfVector2i pos = (sfVector2i){0, 0};
    int check = 0;

    sfSprite_setTexture(menu2, map2, sfTrue);
    sfRenderWindow_clear(as->win->window, sfWhite);
    for (int i = 0; i < as->set->size_max; i++)
        for (int j = 0; j < as->set->size_max; j++)
            select_map(as, i, j, pos);
    sfRenderWindow_drawSprite(as->win->window, menu2, NULL);
    sfRenderWindow_display(as->win->window);
    while (sfRenderWindow_isOpen(as->win->window) && check != 1) {
        check = quit_map(as);
        pos = get_mouse(as, pos, menu2);
    }
    sfSprite_destroy(menu2);
    sfTexture_destroy(map2);
}