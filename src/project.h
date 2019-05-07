/*
** EPITECH PROJECT, 2018
** source_toolbox.h
** File description:
** ressources for lib
*/

#ifndef PROJECT_H
    #define PROJECT_H

    #include <SFML/System.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <math.h>

    typedef struct shop_s
    {
        sfSprite *obj1;
        sfSprite *obj2;
        sfSprite *obj3;
        int nb1;
        int nb2;
        int nb3;
    } shop_t;

    typedef struct inv_s
    {
        int state;
        sfVector2f pos;
        int number;
        int speed;
        int s_attack;
        float attack_s;
        int damage;
        int size_bullet;
        int life;
        sfTexture *text;
        sfTexture *text2;
        sfSprite *spr1;
        sfSprite *spr2;
    } inv_t;

    typedef struct quest_s
    {
        int type;
        int number;
        sfSprite *spr;
        sfTexture *font;
        sfText *count;
        sfText *nb;
        sfText *money;
    } quest_t;

    typedef struct settings_s
    {
        int type;
        int room_max;
        int luck;
        int size_max;
        int level_max;
        double volume_game;
        double volume_music;
    } settings_t;

    typedef struct entity_s
    {
        int type;
        int damage;
        sfVector2f pos;
        sfVector2f dir;
        sfSprite *spr;
        sfTexture *text;
        struct entity_s *next;
        struct entity_s *prev;
    } entity_t;

    typedef struct obs_s
    {
        int type;
        sfSprite *hit;
        sfTexture *font;
        sfVector2f pos;
        struct obs_s *next;
        struct obs_s *prev;
    } obs_t;

    typedef struct gen_s
    {
        int type;
        int pass;
        char **map;
    }gen_t;

    typedef struct obj_s
    {
        int type;
        sfImage *img;
        sfTexture *tex;
        sfSprite *spr;
        sfVector2f pos;
        sfIntRect rect;
        float speed;
    } obj_t;

    typedef struct button_s {
        sfRectangleShape *rect;
    } but_t;

    typedef struct window_s
    {
        sfVideoMode mode;
        int s_adj;
        sfRenderWindow *window;
        sfImage *icon;
        sfEvent event;
        sfClock *clock;
        sfTime time;
        float seconds;
        sfVector2i mousepos;
        int fps;
    } win_t;

    typedef struct sound_s
    {
        sfSound *clic;
        sfSoundBuffer *sbc;
        sfMusic *game;
        sfMusic *menu;
        sfMusic *boss;
        sfText *coin;
        sfText *bomb;
        sfText *stat1;
        sfText *stat2;
        sfText *stat3;
        sfText *stat4;
    } sound_t;

    typedef struct sprt_s
    {
        obj_t *back_menu;
        obj_t *back_game;
        obj_t *menu_start;
        obj_t *menu_start_s;
        obj_t *menu_info;
        obj_t *menu_info_s;
        obj_t *menu_quit;
        obj_t *menu_quit_s;
        obj_t *rules;
        obj_t *game_pause;
        obj_t *pause_resume;
        obj_t *pause_resume_s;
        obj_t *pause_quit;
        obj_t *pause_quit_s;
        obj_t *loading_isaac;
        obj_t *tears;
        obj_t *loading_head;
        obj_t *left;
        obj_t *right;
        obj_t *up;
        obj_t *down;
        obj_t *htp;
        obj_t *npc_coin;
        obj_t *npc_quest;
        obj_t *shop;
    } sprt_t;

    typedef struct var_s
    {
        int game_status;
        int game_pause;
        int game_info;
    } var_t;

    typedef struct isaac_s
    {
        int money;
        int speed;
        int s_attack;
        float attack_s;
        int damage;
        int size_bullet;
        int life;
        int ghost;
        int nb_quest;
        sfVector2i fire;
        sfTime time;
        float second;
        sfClock *clock;
        sfVector2f pos;
        sfSprite *spr;
        sfTexture *text;
        int max_life;
        int bomb;
        sfIntRect rect;
        quest_t *quest;
    } isaac_t;

    typedef struct list_s
    {
        int type;
        isaac_t *player;
        struct list_s *next;
        struct list_s *prev;
    } list_t;

    typedef struct npc_s
    {
        int interact;
        int first_talk_shop;
        int first_talk_quest;
        int collide_shop;
        int collide_quest;
    } npc_t;

    typedef struct as_s
    {
        int room;
        int left;
        int right;
        int up;
        int down;
        int last;
        int x;
        int y;
        sfClock *clock;
        sfTime time;
        float seconds;
        obs_t *obj;
        isaac_t *is;
        var_t *var;
        sprt_t *spr;
        sound_t *son;
        win_t *win;
        but_t *but;
        gen_t **gen;
        list_t *player;
        entity_t *ent;
        npc_t *npc;
        settings_t *set;
        inv_t *inv;
    } as_t;

    int error(int, char **, win_t *);
    void create_window(win_t *);
    void error_fps(win_t *);
    void init_struct(as_t *);
    obj_t *create_obj(sprt_t *, const char *, sfVector2f, \
    sfIntRect);
    sfText *create_txt(sprt_t *, sfFont *, int, sfText *);
    void menu(as_t *);
    void state(as_t *);
    void event_menu(win_t *, var_t *, sprt_t *, sound_t *);
    void event_game(as_t *);
    void display_sprites_menu(win_t *, var_t *, sprt_t *, \
    sound_t *);
    void display_sprites_game(win_t *, var_t *, sprt_t *, \
    sound_t *);
    void init_pause(win_t *, var_t *, sprt_t *, sound_t *);
    void game_pause(win_t *, var_t *, sprt_t *, sound_t *);
    void event_pause(win_t *, var_t *, sprt_t *, sound_t *);
    void manage_key_character(as_t *);
    void destroy(as_t *);
    void map_filler(as_t *, int, int);
    void map_creator(as_t *);
    char *cnc(char *, char *);
    char *cni(char *, int);
    char *cni2(int);
    void da_way(as_t *, int, int);
    obs_t *generate_room(char **);
    void da_path(as_t *, int, int);
    void path_creator(as_t *, int, int);
    char **my_double_malloc(int, int);
    char **tab_filler(char *);
    int colli(as_t *, sfVector2f, sfVector2f, sfVector2f);
    int co2(as_t *, sfVector2f, sfVector2f, int);
    int destroy_bullet(entity_t *);
    void create_bullet(as_t *, entity_t **, int);
    entity_t *init_bullet(as_t *);
    settings_t *init_settings(as_t *);
    void my_usleep(float);
    void create_ghost(list_t **, sfVector2f);
    void draw_npc(as_t *);
    void draw_ennemis(as_t *);
    int free_mob(isaac_t *);
    int destroy_mob(list_t *);
    void move_ennemis(as_t *);
    int co3(as_t *, sfVector2f, sfVector2f, sfVector2f);
    int test_npc(as_t *as);
    void menu_quest(as_t *);
    void menu_shop(as_t *);
    void init_npc(npc_t *);
    void draw_isaac(as_t *);
    void print_bullet(as_t *);
    void draw_ennemis(as_t *);
    void init_as(as_t *);
    list_t *init_mobs(as_t *);
    entity_t *init_bullet(as_t *);
    void init_isaac(as_t *);
    void state(as_t *);
    void free_bullet(entity_t *);
    void free_map(obs_t *);
    void free_mobs(list_t *);
    void generate_mobs(as_t *);
    void my_usleep(float);
    void game(as_t *);
    void add_bullet(as_t *, entity_t **, int, sfVector2f);
    void add_bullet2(as_t *, entity_t **, int, sfVector2f);
    void init_inv(as_t *);
    void create_obj_0(as_t *, int);
    void create_obj_1(as_t *, int);
    void create_obj_2(as_t *, int);
    void create_obj_3(as_t *, int);
    void create_obj_4(as_t *, int);
    void create_obj_5(as_t *, int);
    void create_obj_6(as_t *, int);
    void create_obj_7(as_t *, int);
    void create_obj_8(as_t *, int);
    void create_obj_9(as_t *, int);
    void create_inv(as_t *);
    void add_obj(as_t *, int);
    void set_obj(as_t *);
    void print_obj(as_t *);
    void give_stats(as_t *, int);
    void draw_text(as_t *);
    int anim_mob(isaac_t *);
    int anim_isaac(obj_t *, int, win_t *);
    int rand_mod(int, int);
    void init_text(sound_t *);
    void init_map(as_t *);
    int move(as_t *, int, int, sfVector2f);
    void set_print_obj(as_t *);
    void triple_shot(as_t *);
    int check_pnj(as_t *, sfVector2f, sfVector2f, sfVector2f);
    int second_colli(as_t *, sfVector2f, sfVector2f, sfVector2f);
    void init_quest(as_t *);
    void shopping2(as_t *, shop_t *);
    int purchase2(as_t *, sfVector2i, shop_t *);
    void shop(as_t *);
    int check_quest(as_t *);
    void select_boss(as_t *);
    void killer(as_t *, list_t *);
    void init_clock(as_t *);
    void rpg2(as_t *);
    int obs(int);
#endif