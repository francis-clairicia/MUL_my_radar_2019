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

    airplane->rotate_side = rotate_offset / ABS(rotate_offset);
    if (abs(rotate_offset) >= 180)
        airplane->rotate_side *= -1;
}

float get_arrival_direction(airplane_t *airplane)
{
    sfVector2f axis = {1, 0};
    sfVector2f pos = sfRectangleShape_getPosition(airplane->shape);
    float angle = angle_formed_by_vector(vector(pos, airplane->arrival), axis);

    if (airplane->arrival.y < pos.y)
        return (set_angle_to_range(DEGREES(-angle), 0, 360));
    return (set_angle_to_range(DEGREES(angle), 0, 360));
}

void set_direction_to_arrival(airplane_t *airplane)
{
    float d_angle = get_arrival_direction(airplane);

    airplane->angle = d_angle;
    airplane->direction.x = cos(RADIANS(d_angle));
    airplane->direction.y = sin(RADIANS(d_angle));
    sfRectangleShape_setRotation(airplane->shape, d_angle);
    airplane->rotate_side = 0;
}

void change_airplane_direction(airplane_t *airplane,
    float rotate_offset, float delay)
{
    rotate_offset = set_angle_to_range(rotate_offset, -180, 180);
    if (ABS(rotate_offset) > 180.0)
        rotate_offset += (rotate_offset < 0) ? 360.0 : -360.0;
    determine_rotate_side(airplane, airplane->angle + rotate_offset);
    airplane->rotate_offset = ABS(rotate_offset);
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