/*
** EPITECH PROJECT, 2018
** init_struct.c
** File description:
** program to initialise struct
*/

// A LA NORME

#include "source_toolbox.h"
#include "project.h"

void init_struct_tris(as_t *as)
{
    as->spr->tears = create_obj(as->spr, "./res/loading_3.png",
    (sfVector2f){0, -200}, (sfIntRect) {0, 0, 1920, 1080});
    as->spr->left = create_obj(as->spr, "./perso/left_sprite_80.png",
    (sfVector2f){800, 450}, (sfIntRect){0, 0, 67, 80});
    as->spr->right = create_obj(as->spr, "./perso/right_sprite_80.png",
    (sfVector2f){800, 450}, (sfIntRect){0, 0, 67, 80});
    as->spr->up = create_obj(as->spr, "./perso/up_sprite_80.png",
    (sfVector2f){800, 450}, (sfIntRect){0, 0, 67, 80});
    as->spr->down = create_obj(as->spr, "./perso/down_sprite_80.png",
    (sfVector2f){800, 450}, (sfIntRect){0, 0, 67, 80});
    as->spr->htp = create_obj(as->spr, "./res/menu.png",
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080});
    as->spr->npc_coin = create_obj(as->spr, "./res/npc_coin.png",
    (sfVector2f){500, 250}, (sfIntRect){0, 0, 67, 90});
    as->spr->npc_quest = create_obj(as->spr, "./res/npc_quest.png",
    (sfVector2f){1340, 250}, (sfIntRect){0, 0, 67, 90});
    as->spr->shop = create_obj(as->spr, "./res/shop.png",
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080});
}

void init_struct_bis(as_t *as)
{
    as->spr->pause_resume = create_obj(as->spr, "./res/pause_resume.png",
    (sfVector2f){550, 600}, (sfIntRect) {0, 0, 400, 150});
    as->spr->pause_quit = create_obj(as->spr, "./res/menu_quit.png",
    (sfVector2f){1050, 600}, (sfIntRect) {0, 0, 400, 150});
    as->spr->menu_info_s = create_obj(as->spr, "./res/menu_info_s.png",
    (sfVector2f){200, 850}, (sfIntRect) {0, 0, 400, 150});
    as->spr->menu_quit_s = create_obj(as->spr, "./res/menu_quit_s.png",
    (sfVector2f){1400, 850}, (sfIntRect) {0, 0, 400, 150});
    as->spr->menu_start_s = create_obj(as->spr, "./res/menu_start_s.png",
    (sfVector2f){800, 850}, (sfIntRect) {0, 0, 400, 150});
    as->spr->pause_resume_s = create_obj(as->spr, "./res/resume_s.png",
    (sfVector2f){550, 600}, (sfIntRect) {0, 0, 400, 150});
    as->spr->pause_quit_s = create_obj(as->spr, "./res/menu_quit_s.png",
    (sfVector2f){1050, 600}, (sfIntRect) {0, 0, 400, 150});
    as->spr->loading_head = create_obj(as->spr, "./res/loading_2.png",
    (sfVector2f){0, 0}, (sfIntRect) {0, 0, 1920, 1080});
    as->spr->loading_isaac = create_obj(as->spr, "./res/loading_1.png",
    (sfVector2f){0, 0}, (sfIntRect) {0, 0, 1920, 1080});
    init_struct_tris(as);
}

void init_struct(as_t *as)
{
    init_var(as->var);
    init_sound_and_text(as->son);
    as->spr->back_menu = create_obj(as->spr, "./res/Episaac.png", \
    (sfVector2f){0, 0}, (sfIntRect) {0, 0, 1920, 1200});
    as->spr->back_game = create_obj(as->spr, "./res/back_game.png", \
    (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 1920, 1080});
    as->spr->menu_start = create_obj(as->spr, "./res/menu_start.png", \
    (sfVector2f){800, 850}, (sfIntRect) {0, 0, 400, 150});
    as->spr->menu_info = create_obj(as->spr, "./res/menu_info.png", \
    (sfVector2f){200, 850}, (sfIntRect) {0, 0, 400, 150});
    as->spr->menu_quit = create_obj(as->spr, "./res/menu_quit.png", \
    (sfVector2f){1400, 850}, (sfIntRect) {0, 0, 400, 150});
    as->spr->rules = create_obj(as->spr, "./res/rules.png", (sfVector2f) \
    {0, 0}, (sfIntRect) {0, 0, 1920, 1080});
    as->spr->game_pause = create_obj(as->spr, "./res/game_pause.png", \
    (sfVector2f){0, 0}, (sfIntRect) {0, 0, 1920, 1080});
    init_struct_bis(as);
}

void init_text2(sound_t *son)
{
    sfText_setFont(son->stat1,
    sfFont_createFromFile("perso/isaac_letter.ttf"));
    sfText_setFont(son->stat2,
    sfFont_createFromFile("perso/isaac_letter.ttf"));
    sfText_setFont(son->stat3,
    sfFont_createFromFile("perso/isaac_letter.ttf"));
    sfText_setFont(son->stat4,
    sfFont_createFromFile("perso/isaac_letter.ttf"));
}

void init_text(sound_t *son)
{
    son->stat1 = sfText_create();
    son->stat2 = sfText_create();
    son->stat3 = sfText_create();
    son->stat4 = sfText_create();
    sfText_setCharacterSize(son->stat1, 60);
    sfText_setCharacterSize(son->stat2, 60);
    sfText_setCharacterSize(son->stat3, 60);
    sfText_setCharacterSize(son->stat4, 60);
    sfText_setPosition(son->stat1, (sfVector2f){200, 240});
    sfText_setPosition(son->stat2, (sfVector2f){200, 325});
    sfText_setPosition(son->stat3, (sfVector2f){200, 410});
    sfText_setPosition(son->stat4, (sfVector2f){200, 495});
    sfText_setString(son->stat1, "0");
    sfText_setString(son->stat2, "0");
    sfText_setString(son->stat3, "0");
    sfText_setString(son->stat4, "0");
    son->boss = sfMusic_createFromFile("./music/boss.ogg");
    sfMusic_setLoop(son->boss, sfTrue);
    sfMusic_setVolume(son->boss, 100.0);
    init_text2(son);
}