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

#define ABS(value) ((value < 0) ? -value : value)
#define MIN(a, b) ((a < b) ? (a) : (b))
#define MAX(a, b) ((a > b) ? (a) : (b))

#define DEGREES(angle_in_radians) ((float)angle_in_radians * 180.0 / M_PI)
#define RADIANS(angle_in_degrees) ((float)angle_in_degrees * M_PI / 180.0)

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
    sfBool on_tower_area;
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
int valid_script(char const *script_path);
int error_script(char const *script);
void event_switch_sprite(sfKeyEvent event, list_t *airplanes, list_t *towers);
void show_clock(sfRenderWindow *window, sfClock *clock);
void show_fps(sfRenderWindow *window, sfClock *clock);

list_t *load_airplanes(char const *script);
void draw_airplanes(sfRenderWindow *window, list_t *airplanes);
void destroy_airplanes(list_t **airplanes);
void move_airplanes(list_t *airplanes);
int all_airplanes_stopped_flying(list_t *airplanes);
void check_airplane_on_tower(list_t *airplanes, list_t *towers);
float get_arrival_direction(airplane_t *airplane);
void set_direction_to_arrival(airplane_t *airplane);
void change_airplane_direction(airplane_t *airplane,
    float rotate_offset, float delay);
void head_for_arrival(airplane_t *airplane);
void check_airplane_collision(list_t *airplanes);

list_t *load_towers(char const *script);
void draw_towers(sfRenderWindow *window, list_t *towers);
void destroy_towers(list_t **towers);

float set_angle_to_range(float angle, float min, float max);

sfVector2f vector(sfVector2f point_a, sfVector2f point_b);
float vector_norm(sfVector2f vector);
float dot_product(sfVector2f u, sfVector2f v);
float cross_product(sfVector2f u, sfVector2f v);
float angle_formed_by_vector(sfVector2f u, sfVector2f v);

int shape_intersection(sfRectangleShape *shape_A, sfRectangleShape *shape_B);
int separating_axis_method(sfVector2f edges_first[4],
    sfVector2f points_first[4], sfVector2f points_second[4]);

int point_on_line(sfVector2f p_a, sfVector2f u, sfVector2f point_to_check);
int point_on_segment(sfVector2f p_a, sfVector2f p_b, sfVector2f p_c);

#endif