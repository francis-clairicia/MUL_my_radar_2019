/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** move_airplanes.c
*/

#include "my_radar.h"

static void move_airplane(airplane_t *airplane)
{
    sfVector2f offset;

    if (elapsed_time(500, airplane->rotation_clock)
    && sfRectangleShape_getRotation(airplane->shape) != airplane->angle)
        sfRectangleShape_rotate(airplane->shape, airplane->rotate_side);
    if (elapsed_time(airplane->delay, airplane->delay_clock))
        airplane->fly = sfTrue;
    if (airplane->fly) {
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