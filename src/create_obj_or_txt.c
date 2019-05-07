/*
** EPITECH PROJECT, 2018
** create_obj_or_txt.c
** File description:
** creates my_defender sprites & textures
*/

// A LA NORME

#include "source_toolbox.h"
#include "project.h"

obj_t *create_obj(sprt_t *spr, const char *path, sfVector2f pos, \
sfIntRect rect)
{
    obj_t *obj = malloc(sizeof(obj_t));

    obj->tex = sfTexture_createFromFile(path, NULL);
    obj->spr = sfSprite_create();
    obj->pos = pos;
    obj->rect = rect;
    sfSprite_setTexture(obj->spr, obj->tex, sfTrue);
    sfSprite_setPosition(obj->spr, obj->pos);
    sfSprite_setTextureRect(obj->spr, obj->rect);
    return (obj);
}

sfText *create_txt(sprt_t *spr, sfFont *font, int size, sfText *text)
{
    text = sfText_create();
    sfText_setCharacterSize(text, size);
    sfText_setFont(text, font);
    sfColor c = sfColor_fromRGBA(0, 0, 0, 255);
    sfText_setColor(text, c);
    sfText_setPosition(text, (sfVector2f) {0, 0});
    return (text);
}