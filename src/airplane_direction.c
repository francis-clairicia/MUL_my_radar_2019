/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** airplane_direction.c
*/

#include "my_radar.h"

float get_arrival_direction(airplane_t *airplane)
{
    sfVector2f axis = {1, 0};
    sfVector2f pos = sfRectangleShape_getPosition(airplane->shape);
    float angle = angle_formed_by_vector(vector(pos, airplane->arrival), axis);

    if (airplane->arrival.y < pos.y)
        angle = -angle;
    return (set_angle_to_range(DEGREES(angle), 0, 360));
}

void set_direction_to_arrival(airplane_t *airplane)
{
    float d_angle = get_arrival_direction(airplane);

    airplane->angle = d_angle;
    airplane->direction.x = cos(RADIANS(d_angle));
    airplane->direction.y = sin(RADIANS(d_angle));
    sfRectangleShape_setRotation(airplane->shape, d_angle);
}