/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** move_airplanes.c
*/

#include "my_radar.h"

static float abs_float(float x)
{
    return ((x < 0) ? -x : x);
}

static void refresh_director_vector(airplane_t *airplane)
{
    float angle;

    sfRectangleShape_rotate(airplane->shape, airplane->rotate_side);
    if (airplane->rotate_offset > 0)
        airplane->rotate_offset -= 1;
    angle = sfRectangleShape_getRotation(airplane->shape);
    airplane->angle = angle;
    airplane->direction.x = cos(to_radians(angle));
    airplane->direction.y = sin(to_radians(angle));
    if (airplane->head_for_arrival) {
        if (abs_float(angle - airplane->direction_to_arrival) <= 1)
            calculate_airplane_direction(airplane, sfFalse);
        return;
    }
    if (airplane->rotate_offset == 0)
        airplane->rotate_side = 0;
}

static void move_airplane(airplane_t *airplane)
{
    sfVector2f offset;

    if (airplane == NULL)
        return;
    if (airplane->rotate_side != 0) {
        get_airplane_direction(airplane);
        if (elapsed_time(10, airplane->rotation_clock))
            refresh_director_vector(airplane);
    }
    if (elapsed_time(10, airplane->move_clock)) {
        offset.x = airplane->speed * airplane->direction.x;
        offset.y = airplane->speed * airplane->direction.y;
        sfRectangleShape_move(airplane->shape, offset);
    }
}

void move_airplanes(list_t *airplanes)
{
    airplane_t *airplane;

    while (airplanes != NULL) {
        airplane = (airplane_t *)(airplanes->data);
        if (elapsed_time(airplane->delay * 1000, airplane->delay_clock))
            airplane->fly = sfTrue;
        if (airplane->fly)
            move_airplane(airplane);
        if (airplane->delay_before_readjustement > 0
        && elapsed_time(airplane->delay_before_readjustement,
        airplane->head_for_arrival_clock))
            head_for_arrival(airplane);
        airplanes = airplanes->next;
    }
}