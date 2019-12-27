/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** airplane_collision.c
*/

#include "my_radar.h"

static void airplane_collision(airplane_t *airplane, airplane_t *other_airplane)
{
    sfVector2f pos_a = sfRectangleShape_getPosition(airplane->shape);
    sfVector2f pos_b = sfRectangleShape_getPosition(other_airplane->shape);

    if (vector_norm(vector(pos_a, pos_b)) > 45)
        return;
    if (shape_intersection(airplane->shape, other_airplane->shape)) {
        airplane->destroyed = sfTrue;
        other_airplane->destroyed = sfTrue;
    }
}

static void check_collision(airplane_t *airplane, list_t *other_airplanes)
{
    airplane_t *other_airplane;

    while (other_airplanes != NULL) {
        other_airplane = (airplane_t *)(other_airplanes->data);
        if (other_airplane->take_off
        && !(other_airplane->land_on) && !(other_airplane->destroyed))
            airplane_collision(airplane, other_airplane);
        other_airplanes = other_airplanes->next;
    }
}

void check_airplane_collision(list_t *airplanes)
{
    airplane_t *airplane;

    while (airplanes != NULL) {
        airplane = (airplane_t *)(airplanes->data);
        if (airplane->take_off
        && !(airplane->land_on) && !(airplane->destroyed))
            check_collision(airplane, airplanes->next);
        airplanes = airplanes->next;
    }
}