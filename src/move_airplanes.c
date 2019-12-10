/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** move_airplanes.c
*/

#include "my_radar.h"

static void refresh_director_vector(airplane_t *airplane)
{
    double angle_in_degrees;
    double angle_in_radians;

    sfRectangleShape_rotate(airplane->shape, airplane->rotate_side);
    angle_in_degrees = sfRectangleShape_getRotation(airplane->shape);
    angle_in_radians = angle_in_degrees * acos(-1) / 180;
    airplane->direction.x = cos(angle_in_radians);
    airplane->direction.y = sin(angle_in_radians);
}

static void move_airplane(airplane_t *airplane)
{
    sfVector2f offset;

    if (elapsed_time(airplane->delay, airplane->delay_clock))
        airplane->fly = sfTrue;
    if (!(airplane->fly))
        return;
    if (sfRectangleShape_getRotation(airplane->shape) != airplane->angle) {
        if (elapsed_time(10, airplane->rotation_clock))
            refresh_director_vector(airplane);
        if (sfRectangleShape_getRotation(airplane->shape) == airplane->angle)
            airplane->rotate_side = 0;
    }
    if (elapsed_time(10, airplane->move_clock)) {
        offset.x = airplane->speed * airplane->direction.x;
        offset.y = airplane->speed * airplane->direction.y;
        sfRectangleShape_move(airplane->shape, offset);
    }
}

void move_airplanes(list_t *airplanes)
{
    while (airplanes != NULL) {
        move_airplane((airplane_t *)(airplanes->data));
        airplanes = airplanes->next;
    }
}