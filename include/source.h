/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** pour include tout
*/

#ifndef MY_RPG_H
#define MY_RPG_H

#pragma GCC diagnostic ignored "-Wchar-subscripts"
#pragma GCC diagnostic ignored "-Wunused-parameter"

#include "lib.h"

// global
void launch_game(window_t *win);
void game_director(window_t *win);
void gameplay(window_t *win);
void menu(window_t *win);
window_t *init_window(void);
intro_t *init_intro(window_t *win);
menu_t *init_menu(window_t *win);
win_clock_t *init_clock(void);
void init_scene_variable(window_t *win);
void init_menu_pause(window_t *win, menu_pause_t *pause);
void destroy_intro(window_t *win);
void destroy_menu(window_t *win);
void destroy_win(window_t *win);
void refresh_time(win_clock_t *clock);

//menu
char new_game(window_t *win);
char settings(window_t *win);
char load_game(window_t *win);

//gameplay
char init_gameplay(window_t *win);
void display_pause_menu(window_t *win);

//player
void player_event(window_t *win, player_t *player);
char *create_control(char const *str, char const nb);
char init_player(window_t *win);
void new_player(window_t *);
void player_left(window_t *win, player_t *player);
void player_right(window_t *win, player_t *player);
void player_jump(window_t *win, player_t *player);
void display_player(window_t *win, player_t *player);
void display_hud(window_t *win, player_t *player);

void switch_player_creative(window_t *win);
void creative_event(window_t *win, creative_t *creative);

// SFML function
void display_sprite(window_t *win, sfSprite *sprite);
void set_sprite_pos(sfSprite *sprite, int x, int y);
void display_text(window_t *win, sfText *text);
void texture_createfromfile(sfSprite **sp, sfTexture **tx, char const *path);
sfSprite *create_sprite(sfTexture *texture, sfVector2f const position,
                        sfVector2f const origin);
sfSprite *create_sprite_without_set(sfTexture const *texture);
sfText *create_sftext(sfFont *font, char const *str, int size, sfColor color);
sfText *move_text(sfText *text, sfVector2f pos);
void show_pict(sfRenderWindow *wind, sfSprite *sp,
               sfVector2f *pos, sfIntRect *rect);
sfUint8 *create_framebuffer(int w, int h, unsigned char const px[4]);
void draw_sprite(sfSprite *sprite, sfIntRect const rect,
                            sfVector2f *pos, sfRenderWindow *win);
void clear_fb(sfUint8 **fb, unsigned char const px[4], u_int32_t len);
void replace_framebuffer(sfUint8 **fb, unsigned char const px[4], u_int32_t len);
void change_fb(sfUint8 **fb, unsigned char const px[4], u_int32_t len);
void my_pc(sfUint8 **fb, sfVector2f a, window_t *win, unsigned char const px[4]);
void my_ppl(sfUint8 **fb, sfVector2f *a,
            window_t *win, unsigned char const px[4]);

void intro(window_t *win);

void print_inventory(window_t *win, inventory_t *inventory,
                     sfVector2f const pos);
inventory_t *create_inventory(window_t *win, bool is_chest);
void set_time_filter(window_t *win);

// intro
void display_intro(window_t *win);
file_path_t *get_all_path(DIR *dir, char *folder_path, int *len,
                          bool const check_extension);
void tools_pickaxe(void *window, sfVector2i *pos);

//map_handling
u_int16_t get_ground(tile_t ***map, u_int16_t x);
map_t *generate_map(window_t *window, char *map_name);
void fill_map(window_t *win, tile_t ***map);
bool add_tile(tile_t **tile, sfSprite *sprite, sfIntRect rect, u_int8_t flag);
void remove_ground(tile_t **tile, u_int8_t ground);
void remove_tile(tile_t **tile);
void generate_houses(window_t *win, tile_t ***map);
void generate_caves(window_t *win, tile_t ***map,
                    u_int32_t width, u_int32_t height);
void display_map(window_t *, sfVector2f *, sfVector2i *);


//button
button_t create_new_button(sfText *text, sfVector2i const pos,
                           sfVector2i const size, char const status);
void destroy_button(button_t *button, char const nb);
void set_button_position(button_t *button, sfVector2i const *center);

/////////* destroy */
void destroy_all(window_t *win);
/////////////////////
#endif /* MY_RPG_H */
