/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** inventory2
*/

// A LA NORME

#include "project.h"

void add_obj(as_t *as, int nb)
{
    if (nb == 0)
        create_obj_0(as, 0);
    if (nb == 1)
        create_obj_1(as, 0);
    if (nb == 2)
        create_obj_2(as, 0);
    if (nb == 3)
        create_obj_3(as, 0);
    if (nb == 4)
        create_obj_4(as, 0);
    if (nb == 5)
        create_obj_5(as, 0);
    if (nb == 6)
        create_obj_6(as, 0);
    if (nb == 7)
        create_obj_7(as, 0);
    if (nb == 8)
        create_obj_8(as, 0);
    if (nb == 9)
        create_obj_9(as, 0);
}

inv_t create_object(void)
{
    inv_t obj;

    obj.state = 0;
    obj.number = -1;
    obj.attack_s = 0;
    obj.damage = 0;
    obj.life = 0;
    obj.pos = (sfVector2f){0, 0};
    obj.s_attack = 0;
    obj.size_bullet = 0;
    obj.speed = 0;
    obj.spr1 = NULL;
    obj.spr2 = NULL;
    obj.text = NULL;
    obj.text2 = NULL;
    return (obj);
}

void create_inv(as_t *as)
{
    inv_t *object = malloc(sizeof(inv_t) * 16);

    for (int i = 0; i < 16; i++) {
        object[i] = create_object();
    }
    as->inv = object;
}

int quit_inv(as_t *as)
{
    if (sfKeyboard_isKeyPressed(sfKeyI)) {
        while (sfKeyboard_isKeyPressed(sfKeyI));
        return (1);
    }
    return (0);
}

void init_inv(as_t *as)
{
    int check = 0;
    int check2 = 0;
    sfSprite *spr = sfSprite_create();
    sfTexture *text = sfTexture_createFromFile("res/inventory.png", NULL);
    sfVector2i mouse = (sfVector2i){0, 0};

    sfSprite_setTexture(spr, text, sfTrue);
    while (sfRenderWindow_isOpen(as->win->window) && check != 1) {
        sfRenderWindow_drawSprite(as->win->window, spr, NULL);
        mouse = sfMouse_getPosition(NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) && mouse.x >= 1225 &&
        mouse.x <= 1300 && mouse.y >= 150 && mouse.y <= 210)
            break;
        check = quit_inv(as);
        print_obj(as);
        sfRenderWindow_display(as->win->window);
        sfRenderWindow_clear(as->win->window, sfBlack);
    }
}