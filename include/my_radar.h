/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** my_radar.h
*/

#ifndef HEADER_MY_RADAR
#define HEADER_MY_RADAR

#include <math.h>
#include "csfml.h"
#include "my.h"
#include "mylist.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

typedef struct airplane
{
    object_t *object;
    sfRectangleShape *shape;
    sfVector2f departure;
    sfVector2f arrival;
    float speed;
    unsigned int delay;
    sfVector2f direction;
    float angle;
    float direction_to_arrival;
    sfBool outline;
    sfBool show_sprite;
    int rotate_side;
    unsigned int rotate_offset;
    sfBool head_for_arrival;
    sfClock *rotation_clock;
    sfClock *delay_clock;
    sfClock *move_clock;
    sfClock *head_for_arrival_clock;
    unsigned int delay_before_readjustement;
    sfBool take_off;
    sfBool land_on;
    sfBool destroyed;
} airplane_t;

typedef struct control_tower
{
    object_t *object;
    float radius;
    sfCircleShape *area;
    sfBool show_area;
    sfBool show_sprite;
} tower_t;

void my_radar(sfRenderWindow *window, char const *script);
int error_script(char const *script);
void event_switch_sprite(sfKeyEvent event, list_t *airplanes, list_t *towers);
sfBool handle_view(sfEvent event, sfView *view, sfVector2i mouse_pos);

list_t *load_airplanes(char const *script);
void draw_airplanes(sfRenderWindow *window, list_t *airplanes);
void destroy_airplanes(list_t **airplanes);
void move_airplanes(list_t *airplanes);
int all_airplanes_stopped_flying(list_t *airplanes);
float get_arrival_direction(airplane_t *airplane);
void set_direction_to_arrival(airplane_t *airplane);
void change_airplane_direction(airplane_t *airplane,
    float rotate_offset, float delay);
void head_for_arrival(airplane_t *airplane);

list_t *load_towers(char const *script);
void draw_towers(sfRenderWindow *window, list_t *towers);
void destroy_towers(list_t **towers);

float to_degrees(float radians);
float to_radians(float degrees);
float set_angle_to_range(float angle, float min, float max);
float abs_float(float x);

sfVector2f vector(sfVector2f point_a, sfVector2f point_b);
float vector_norm(sfVector2f vector);
float scalar_product(sfVector2f u, sfVector2f v);
float vector_product(sfVector2f u, sfVector2f v);
int point_on_line(sfVector2f p_a, sfVector2f u, sfVector2f point_to_check);
int point_on_segment(sfVector2f p_a, sfVector2f p_b, sfVector2f p_c);

#endif