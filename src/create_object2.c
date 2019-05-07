/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** create_object2
*/

// A LA NORME

#include "project.h"

void create_obj_5(as_t *as, int i)
{
    for (; as->inv[i].number != -1; i++);
    as->inv[i].spr1 = sfSprite_create();
    as->inv[i].spr2 = sfSprite_create();
    as->inv[i].text = sfTexture_createFromFile("res/item5.png", NULL);
    as->inv[i].text2 = sfTexture_createFromFile("res/font5.png", NULL);
    sfSprite_setTexture(as->inv[i].spr1, as->inv[i].text, sfTrue);
    sfSprite_setTexture(as->inv[i].spr2, as->inv[i].text2, sfTrue);
    as->inv[i].number = 5;
    as->is->fire.x = 1;
    as->inv[i].state = 1;
}

void create_obj_9(as_t *as, int i)
{
    for (; as->inv[i].number != -1; i++);
    as->inv[i].spr1 = sfSprite_create();
    as->inv[i].spr2 = sfSprite_create();
    as->inv[i].text = sfTexture_createFromFile("res/item9.png", NULL);
    as->inv[i].text2 = sfTexture_createFromFile("res/font9.png", NULL);
    sfSprite_setTexture(as->inv[i].spr1, as->inv[i].text, sfTrue);
    sfSprite_setTexture(as->inv[i].spr2, as->inv[i].text2, sfTrue);
    as->inv[i].number = 9;
    as->inv[i].attack_s = -2;
    as->is->max_life += 1;
    as->is->life += 1;
    as->inv[i].state = 1;
}

void create_obj_8(as_t *as, int i)
{
    for (; as->inv[i].number != -1; i++);
    as->inv[i].spr1 = sfSprite_create();
    as->inv[i].spr2 = sfSprite_create();
    as->inv[i].text = sfTexture_createFromFile("res/item8.png", NULL);
    as->inv[i].text2 = sfTexture_createFromFile("res/font8.png", NULL);
    sfSprite_setTexture(as->inv[i].spr1, as->inv[i].text, sfTrue);
    sfSprite_setTexture(as->inv[i].spr2, as->inv[i].text2, sfTrue);
    as->inv[i].number = 8;
    as->is->fire.y = 1;
    as->is->bomb += 25;
    as->inv[i].state = 1;
}

void create_obj_7(as_t *as, int i)
{
    for (; as->inv[i].number != -1; i++);
    as->inv[i].spr1 = sfSprite_create();
    as->inv[i].spr2 = sfSprite_create();
    as->inv[i].text = sfTexture_createFromFile("res/item7.png", NULL);
    as->inv[i].text2 = sfTexture_createFromFile("res/font7.png", NULL);
    sfSprite_setTexture(as->inv[i].spr1, as->inv[i].text, sfTrue);
    sfSprite_setTexture(as->inv[i].spr2, as->inv[i].text2, sfTrue);
    as->inv[i].number = 7;
    as->is->fire.x = 2;
    as->inv[i].state = 1;
}

void create_obj_6(as_t *as, int i)
{
    for (; as->inv[i].number != -1; i++);
    as->inv[i].spr1 = sfSprite_create();
    as->inv[i].spr2 = sfSprite_create();
    as->inv[i].text = sfTexture_createFromFile("res/item6.png", NULL);
    as->inv[i].text2 = sfTexture_createFromFile("res/font6.png", NULL);
    sfSprite_setTexture(as->inv[i].spr1, as->inv[i].text, sfTrue);
    sfSprite_setTexture(as->inv[i].spr2, as->inv[i].text2, sfTrue);
    as->inv[i].number = 6;
    as->inv[i].attack_s = 1;
    as->inv[i].damage = 3;
    as->inv[i].s_attack = -1;
    as->inv[i].speed = -1;
    as->inv[i].state = 1;
}
