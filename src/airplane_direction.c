/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** airplane_direction.c
*/

#include "my_radar.h"

static void determine_rotate_side(airplane_t *airplane, int new_angle)
{
    int rotate_offset = new_angle - (int)(airplane->angle);

    airplane->rotate_side = rotate_offset / abs(rotate_offset);
    if (abs(rotate_offset) >= 180)
        airplane->rotate_side *= -1;
}

float get_arrival_direction(airplane_t *airplane)
{
    sfVector2f pos = sfRectangleShape_getPosition(airplane->shape);
    sfVector2f director_v = {
        airplane->arrival.x - pos.x,
        airplane->arrival.y - pos.y
    };
    float norm_v = sqrt(pow(director_v.x, 2) + pow(director_v.y, 2));
    float angle = acos(director_v.x / norm_v);

    if (airplane->arrival.y < pos.y)
        angle = -angle;
    return (conditionate_angle(to_degrees(angle)));
}

void set_direction_to_arrival(airplane_t *airplane)
{
    float d_angle = get_arrival_direction(airplane);

    airplane->angle = d_angle;
    airplane->direction.x = cos(to_radians(d_angle));
    airplane->direction.y = sin(to_radians(d_angle));
    sfRectangleShape_setRotation(airplane->shape, d_angle);
    airplane->rotate_side = 0;
}

void change_airplane_direction(airplane_t *airplane,
    float rotate_offset, float delay)
{
    determine_rotate_side(airplane, airplane->angle + rotate_offset);
    airplane->rotate_offset = abs((int)rotate_offset);
    airplane->head_for_arrival = sfFalse;
    sfClock_restart(airplane->head_for_arrival_clock);
    airplane->delay_before_readjustement = delay * 1000;
}

void head_for_arrival(airplane_t *airplane)
{
    airplane->head_for_arrival = sfTrue;
    determine_rotate_side(airplane, get_arrival_direction(airplane));
    airplane->delay_before_readjustement = 0;
}