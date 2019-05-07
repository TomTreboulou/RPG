/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** map_creator.c
*/

// A LA NORME

#include "source_toolbox.h"
#include "project.h"

gen_t node_creator(void)
{
    gen_t node;

    node.map = NULL;
    node.type = 0;
    return (node);
}

void map_filler2(as_t *as, int x, int y, char *name)
{
    char *tmp;
    FILE *file = fopen(name, "r");
    struct stat board;

    if (file == NULL)
        return;
    stat(name, &board);
    tmp = malloc(sizeof(char) * board.st_size + 1);
    fread(tmp, board.st_size, 1, file);
    tmp[board.st_size] = '\0';
    as->gen[y][x].map = tab_filler(tmp);
    free(tmp);
    fclose(file);
}

void map_filler(as_t *as, int x, int y)
{
    char *name = "map/";
    int result = 1111;
    int nb = 0;

    as->room++;
    if (y > 0 && as->gen[y - 1][x].pass == 1)
        result += 1000;
    if (x < as->set->size_max - 1 && as->gen[y][x + 1].pass == 1)
        result += 100;
    if (y < as->set->size_max - 1 && as->gen[y + 1][x].pass == 1)
        result += 10;
    if (x > 0 && as->gen[y][x - 1].pass == 1)
        result += 1;
    nb = (rand() % as->set->room_max) + 1;
    nb = (result == 2222) ? (rand() % 8) + 1 : nb;
    nb = (x == as->set->size_max / 2 && y == as->set->size_max / 2) ? 1 : nb;
    name = cni(name, result);
    name = cnc(name, "/");
    name = cni(name, nb + 1);
    map_filler2(as, x, y, cnc(name, ".txt"));
}

void path_creator(as_t *as, int y, int x)
{
    int nb = 0;

    as->room++;
    as->gen[y][x].pass = 1;
    if (as->room < as->set->level_max && y < as->set->size_max - 1 &&
    as->gen[y + 1][x].type == 0)
        as->gen[y + 1][x].type = ((nb = rand() % as->set->luck) != 0) ? 1 : 2;
    if (as->room < as->set->level_max && y > 0 && as->gen[y - 1][x].type == 0)
        as->gen[y - 1][x].type = ((nb = rand() % as->set->luck) != 0) ? 1 : 2;
    if (as->room < as->set->level_max && x < as->set->size_max - 1 &&
    as->gen[y][x + 1].type == 0)
        as->gen[y][x + 1].type = ((nb = rand() % as->set->luck) != 0) ? 1 : 2;
    if (as->room < as->set->level_max && y > 0 && as->gen[y][x - 1].type == 0)
        as->gen[y][x - 1].type = ((nb = rand() % as->set->luck) != 0) ? 1 : 2;
    da_path(as, y, x);
}

void map_creator(as_t *as)
{
    gen_t **gen = malloc(sizeof(gen_t *) * as->set->size_max);

    for (int i = 0; i < as->set->size_max; i++) {
        gen[i] = malloc(sizeof(gen_t) * as->set->size_max);
        for (int j = 0; j < as->set->size_max; j++)
            gen[i][j] = node_creator();
    }
    as->gen = gen;
    as->room = 0;
    as->gen[as->set->size_max / 2][as->set->size_max / 2].type = 1;
    path_creator(as, as->set->size_max / 2, as->set->size_max / 2);
    as->room = 0;
    for (int i = 0; i < as->set->size_max; i++) {
        for (int j = 0; j < as->set->size_max; j++) {
            as->gen[i][j].type = 0;
            if (as->gen[i][j].pass == 1)
                map_filler(as, j, i);
        }
    }
}