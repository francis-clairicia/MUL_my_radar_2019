/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** my_radar.h
*/

#ifndef HEADER_MY_RADAR
#define HEADER_MY_RADAR

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "csfml.h"
#include "my.h"
#include "mylist.h"

typedef struct airplane
{
    sfRectangleShape *shape;
    sfTexture *texture;
    sfVector2f departure;
    sfVector2f arrival;
    unsigned int speed;
    unsigned int delay;
    sfVector2f direction;
    int angle;
    sfColor outline_color;
    sfBool outline;
    sfBool show_sprite;
    int rotate_side;
    sfClock *rotation_clock;
    sfClock *delay_clock;
    sfBool fly;
} airplane_t;

typedef struct control_tower
{
    sfVector2f position;
    unsigned int radius;
} tower_t;

void my_radar(sfRenderWindow *window, char const *script);
int error_script(char const *script);
void event_switch_sprite(sfKeyEvent event, list_t *airplanes);

list_t *load_airplanes(char const *script);
void draw_airplanes(sfRenderWindow *window, list_t *airplanes);
void destroy_airplanes(list_t **airplanes);
void move_airplanes(list_t *airplanes);

#endif