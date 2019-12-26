/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** move_airplanes.c
*/

#include "my_radar.h"

static void refresh_director_vector(airplane_t *airplane)
{
    float angle;

    sfRectangleShape_rotate(airplane->shape, airplane->rotate_side);
    if (airplane->rotate_offset > 0)
        airplane->rotate_offset -= 1;
    angle = sfRectangleShape_getRotation(airplane->shape);
    airplane->angle = angle;
    airplane->direction.x = cos(RADIANS(angle));
    airplane->direction.y = sin(RADIANS(angle));
    if (airplane->head_for_arrival) {
        if (ABS(angle - get_arrival_direction(airplane)) <= 0.5)
            set_direction_to_arrival(airplane);
    } else if (airplane->rotate_offset == 0)
        airplane->rotate_side = 0;
}

static void check_airplane_landing_on(airplane_t *airplane, sfVector2f pos)
{
    sfVector2f actual_pos = sfRectangleShape_getPosition(airplane->shape);

    airplane->land_on = point_on_segment(pos, actual_pos, airplane->arrival);
}

static void move_airplane(airplane_t *airplane)
{
    sfVector2f offset;
    sfVector2f former_pos = sfRectangleShape_getPosition(airplane->shape);

    if (airplane == NULL)
        return;
    if (airplane->rotate_side != 0) {
        if (elapsed_time(10, airplane->rotation_clock))
            refresh_director_vector(airplane);
    }
    if (elapsed_time(10, airplane->move_clock)) {
        offset.x = airplane->speed * airplane->direction.x;
        offset.y = airplane->speed * airplane->direction.y;
        sfRectangleShape_move(airplane->shape, offset);
        check_airplane_landing_on(airplane, former_pos);
    }
}

void move_airplanes(list_t *airplanes)
{
    airplane_t *airplane;

    while (airplanes != NULL) {
        airplane = (airplane_t *)(airplanes->data);
        if (elapsed_time(airplane->delay * 1000, airplane->delay_clock))
            airplane->take_off = sfTrue;
        if (airplane->take_off
        && !(airplane->land_on) && !(airplane->destroyed))
            move_airplane(airplane);
        if (airplane->delay_before_readjustement > 0
        && elapsed_time(airplane->delay_before_readjustement,
        airplane->head_for_arrival_clock))
            head_for_arrival(airplane);
        airplanes = airplanes->next;
    }
}