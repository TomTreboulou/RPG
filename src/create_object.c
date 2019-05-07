/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** create_object
*/

// A LA NORME

#include "project.h"

void create_obj_4(as_t *as, int i)
{
    for (; as->inv[i].number != -1; i++);
    as->inv[i].spr1 = sfSprite_create();
    as->inv[i].spr2 = sfSprite_create();
    as->inv[i].text = sfTexture_createFromFile("res/item4.png", NULL);
    as->inv[i].text2 = sfTexture_createFromFile("res/font4.png", NULL);
    sfSprite_setTexture(as->inv[i].spr1, as->inv[i].text, sfTrue);
    sfSprite_setTexture(as->inv[i].spr2, as->inv[i].text2, sfTrue);
    as->inv[i].number = 4;
    as->inv[i].s_attack = 1;
    as->is->max_life += 2;
    as->is->life += 2;
    as->inv[i].state = 1;
}

void create_obj_3(as_t *as, int i)
{
    for (; as->inv[i].number != -1; i++);
    as->inv[i].spr1 = sfSprite_create();
    as->inv[i].spr2 = sfSprite_create();
    as->inv[i].text = sfTexture_createFromFile("res/item3.png", NULL);
    as->inv[i].text2 = sfTexture_createFromFile("res/font3.png", NULL);
    sfSprite_setTexture(as->inv[i].spr1, as->inv[i].text, sfTrue);
    sfSprite_setTexture(as->inv[i].spr2, as->inv[i].text2, sfTrue);
    as->inv[i].number = 3;
    as->inv[i].attack_s = -3;
    as->inv[i].damage = -2;
    as->inv[i].s_attack = 1;
    as->inv[i].state = 1;
}

void create_obj_2(as_t *as, int i)
{
    for (; as->inv[i].number != -1; i++);
    as->inv[i].spr1 = sfSprite_create();
    as->inv[i].spr2 = sfSprite_create();
    as->inv[i].text = sfTexture_createFromFile("res/item2.png", NULL);
    as->inv[i].text2 = sfTexture_createFromFile("res/font2.png", NULL);
    sfSprite_setTexture(as->inv[i].spr1, as->inv[i].text, sfTrue);
    sfSprite_setTexture(as->inv[i].spr2, as->inv[i].text2, sfTrue);
    as->inv[i].number = 2;
    as->inv[i].speed = 2;
    as->inv[i].state = 1;
}

void create_obj_1(as_t *as, int i)
{
    for (; as->inv[i].number != -1; i++);
    as->inv[i].spr1 = sfSprite_create();
    as->inv[i].spr2 = sfSprite_create();
    as->inv[i].text = sfTexture_createFromFile("res/item1.png", NULL);
    as->inv[i].text2 = sfTexture_createFromFile("res/font1.png", NULL);
    sfSprite_setTexture(as->inv[i].spr1, as->inv[i].text, sfTrue);
    sfSprite_setTexture(as->inv[i].spr2, as->inv[i].text2, sfTrue);
    as->inv[i].number = 1;
    as->inv[i].damage = 1;
    as->inv[i].speed = 1;
    as->inv[i].state = 1;
}

void create_obj_0(as_t *as, int i)
{
    for (; as->inv[i].number != -1; i++);
    as->inv[i].spr1 = sfSprite_create();
    as->inv[i].spr2 = sfSprite_create();
    as->inv[i].text = sfTexture_createFromFile("res/item0.png", NULL);
    as->inv[i].text2 = sfTexture_createFromFile("res/font0.png", NULL);
    sfSprite_setTexture(as->inv[i].spr1, as->inv[i].text, sfTrue);
    sfSprite_setTexture(as->inv[i].spr2, as->inv[i].text2, sfTrue);
    as->inv[i].number = 0;
    as->inv[i].attack_s = 2;
    as->inv[i].s_attack = -1;
    as->inv[i].state = 1;
    as->inv[i].size_bullet = 1;
}