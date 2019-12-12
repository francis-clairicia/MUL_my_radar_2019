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
#include <math.h>
#include "csfml.h"
#include "my.h"
#include "mylist.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

typedef struct airplane
{
    sfRectangleShape *shape;
    sfTexture *texture;
    sfVector2f departure;
    sfVector2f arrival;
    float speed;
    unsigned int delay;
    sfVector2f direction;
    float angle;
    float direction_to_arrival;
    sfColor outline_color;
    sfBool outline;
    sfBool show_sprite;
    int rotate_side;
    unsigned int rotate_offset;
    sfBool head_for_arrival;
    sfClock *rotation_clock;
    sfClock *delay_clock;
    sfClock *move_clock;
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
void handle_view(sfEvent event, sfView *view, sfVector2i mouse_pos);

list_t *load_airplanes(char const *script);
void draw_airplanes(sfRenderWindow *window, list_t *airplanes);
void destroy_airplanes(list_t **airplanes);
void move_airplanes(list_t *airplanes);
void calculate_airplane_direction(airplane_t *airplane, sfBool animation);
void change_airplane_direction(airplane_t *airplane, int angle_direction);
void head_for_arrival(airplane_t *airplane);

float to_degrees(float radians);
float to_radians(float degrees);

float conditionate_angle(float angle);
sfVector2f vector(sfVector2f point_a, sfVector2f point_b);
int is_colinear(sfVector2f vector_u, sfVector2f vector_v);
int point_on_line(sfVector2f p_a, sfVector2f u, sfVector2f point_to_check);

#endif