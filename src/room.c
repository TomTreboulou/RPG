/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** room
*/

// A LA NORME

#include "project.h"

void create_door(obs_t **last, int i, int j)
{
    obs_t *n = malloc(sizeof(obs_t));
    n->hit = sfSprite_create();

    if (i == 4 && j == 0)
        n->font = sfTexture_createFromFile("res/left_door.png", NULL);
    if (i == 8 && j == 7)
        n->font = sfTexture_createFromFile("res/down_door.png", NULL);
    if (i == 4 && j == 14)
        n->font = sfTexture_createFromFile("res/right_door.png", NULL);
    if (i == 0 && j == 7)
        n->font = sfTexture_createFromFile("res/up_door.png", NULL);
    sfSprite_setTexture(n->hit, n->font, sfTrue);
    n->type = 0;
    n->next = NULL;
    n->prev = *last;
    (*last)->next = n;
    *last = n;
}

void create_hole(obs_t **last, int i, int j, int type)
{
    obs_t *n = malloc(sizeof(obs_t));
    n->hit = sfSprite_create();

    if (type == 0)
        n->font = sfTexture_createFromFile("res/void_top.png", NULL);
    else
        n->font = sfTexture_createFromFile("res/void_center.png", NULL);
    n->pos = (sfVector2f){(j - 1) * 136 + 80, (i - 1) * 130 + 76};
    sfSprite_setTexture(n->hit, n->font, sfTrue);
    sfSprite_setPosition(n->hit, n->pos);
    n->type = 2;
    n->next = NULL;
    n->prev = *last;
    (*last)->next = n;
    *last = n;
}

void create_rock(obs_t **last, int i, int j)
{
    obs_t *n = malloc(sizeof(obs_t));
    n->font = sfTexture_createFromFile("res/rock.png", NULL);
    n->hit = sfSprite_create();

    sfSprite_setTexture(n->hit, n->font, sfTrue);
    n->pos = (sfVector2f){(j - 1) * 136 + 80, (i - 1) * 130 + 76};
    sfSprite_setPosition(n->hit, n->pos);
    n->type = 1;
    n->next = NULL;
    n->prev = *last;
    (*last)->next = n;
    *last = n;
}

obs_t *my_first_node(obs_t *first)
{
    first = malloc(sizeof(obs_t));

    first->type = -1;
    first->pos = (sfVector2f){0, 0};
    first->hit = NULL;
    first->font = NULL;
    first->next = NULL;
    first->prev = NULL;
    return (first);
}

obs_t *generate_room(char **room)
{
    obs_t *first = my_first_node(first);

    for (int i = 0; room[i] != NULL; i++) {
        for (int j = 0; room[i][j] != '\0'; j++) {
            if (room[i][j] == 'X')
                create_rock(&first, i, j);
            if (room[i][j] == 'O' && room[i - 1][j] != 'O')
                create_hole(&first, i, j, 0);
            else if (room[i][j] == 'O' && room[i - 1][j] == 'O')
                create_hole(&first, i, j, 1);
            if (room[i][j] == 'P')
                create_door(&first, i, j);
        }
    }
    while (first->prev != NULL)
        first = first->prev;
    return (first);
}