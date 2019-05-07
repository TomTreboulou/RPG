/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** shop
*/

#include "project.h"

int checking_inventory(as_t *as)
{
    int nb = rand() % 10;
    int check = 0;

    for (int j = 0; j < 50; j++) {
        check = 0;
        for (int i = 0; as->inv[i].number != -1 && check == 0; i++) {
            check += (as->inv[i].number == nb) ? 1 : 0;
        }
        if (check == 0)
            return (nb);
        nb = rand() % 10;
    }
    return (-1);
}

void shopping(as_t *as, shop_t *shop)
{
    shop->nb1 = checking_inventory(as);
    shop->nb2 = checking_inventory(as);
    shop->nb3 = checking_inventory(as);

    if (shop->nb1 != -1) {
        sfSprite_setTexture(shop->obj1,
        sfTexture_createFromFile(cnc(cnc("res/item", cni2(shop->nb1)),
        ".png"), NULL), sfTrue);
        sfSprite_setPosition(shop->obj1, (sfVector2f){815, 570});
        sfRenderWindow_drawSprite(as->win->window, shop->obj1, NULL);
    }
    if (shop->nb2 != -1) {
        sfSprite_setTexture(shop->obj2,
        sfTexture_createFromFile(cnc(cnc("res/item", cni2(shop->nb2)),
        ".png"), NULL), sfTrue);
        sfSprite_setPosition(shop->obj2, (sfVector2f){920, 570});
        sfRenderWindow_drawSprite(as->win->window, shop->obj2, NULL);
    }
    shopping2(as, shop);
}

int purchase(as_t *as, sfVector2i mouse, shop_t *shop)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && as->is->money >= 25) {
        if (mouse.x >= 815 && mouse.x <= 915 && mouse.y >= 570 && mouse.y <=
        670 && shop->nb1 != -1) {
            as->is->money -= 25;
            add_obj(as, shop->nb1);
            give_stats(as, shop->nb1);
            set_obj(as);
            return (1);
        }
        if (mouse.x >= 920 && mouse.x <= 1020 && mouse.y >= 570 && mouse.y <=
        670 && shop->nb2 != -1) {
            as->is->money -= 25;
            add_obj(as, shop->nb2);
            give_stats(as, shop->nb2);
            set_obj(as);
            return (1);
        }
        return (purchase2(as, mouse, shop));
    }
    return (0);
}

void shop(as_t *as)
{
    shop_t *shop = malloc(sizeof(shop_t));
    shop->obj1 = sfSprite_create();
    shop->obj2 = sfSprite_create();
    shop->obj3 = sfSprite_create();
    sfVector2i mouse;

    sfRenderWindow_drawSprite(as->win->window, as->spr->shop->spr, NULL);
    shopping(as, shop);
    sfWindow_display(as->win->window);
    while (sfRenderWindow_isOpen(as->win->window)) {
        mouse = sfMouse_getPosition(NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) && mouse.x >= 1225 &&
        mouse.x <= 1300 && mouse.y >= 150 && mouse.y <= 210)
            break;
        if (purchase(as, mouse, shop) == 1)
            break;
    }
}

void init_quest(as_t *as)
{
    sfFont *font = sfFont_createFromFile("perso/isaac_letter.ttf");
    as->is->quest = malloc(sizeof(quest_t));
    as->is->quest->number = 0;
    as->is->quest->type = 0;
    as->is->quest->spr = sfSprite_create();
    as->is->quest->font = sfTexture_createFromFile("res/quest.png", NULL);
    sfSprite_setTexture(as->is->quest->spr, as->is->quest->font, sfTrue);
    as->is->quest->money = sfText_create();
    sfText_setCharacterSize(as->is->quest->money, 40);
    sfText_setFont(as->is->quest->money, font);
    sfText_setColor(as->is->quest->money, sfBlack);
    as->is->quest->count = sfText_create();
    sfText_setCharacterSize(as->is->quest->count, 70);
    sfText_setFont(as->is->quest->count, font);
    sfText_setColor(as->is->quest->count, sfBlack);
    as->is->quest->nb = sfText_create();
    sfText_setCharacterSize(as->is->quest->nb, 70);
    sfText_setFont(as->is->quest->nb, font);
    sfText_setColor(as->is->quest->nb, sfBlack);
}