/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** move_airplanes.c
*/

#include "my_radar.h"

static void check_airplane_landing_on(airplane_t *airplane, sfVector2f pos)
{
    sfVector2f actual_pos = sfRectangleShape_getPosition(airplane->shape);

    airplane->land_on = point_on_segment(pos, actual_pos, airplane->arrival);
}

static void move_airplane(airplane_t *airplane)
{
    sfVector2f offset;
    sfVector2f former_pos = sfRectangleShape_getPosition(airplane->shape);

    if (elapsed_time(10, airplane->move_clock)) {
        offset.x = airplane->speed * airplane->direction.x;
        offset.y = airplane->speed * airplane->direction.y;
        sfRectangleShape_move(airplane->shape, offset);
        check_airplane_landing_on(airplane, former_pos);
    }
}

static sfBool airplane_can_move(airplane_t *airplane, sfBool first_call)
{
    if (first_call) {
        sfClock_restart(airplane->move_clock);
        sfClock_restart(airplane->delay_clock);
    }
    if (!(airplane->take_off)) {
        if (elapsed_time(airplane->delay * 1000, airplane->delay_clock))
            airplane->take_off = sfTrue;
        if (!(airplane->take_off))
            return (sfFalse);
    }
    return (!(airplane->land_on) && !(airplane->destroyed));
}

void move_airplanes(list_t *airplanes)
{
    static sfBool first_call = sfTrue;
    airplane_t *airplane;

    while (airplanes != NULL) {
        airplane = (airplane_t *)(airplanes->data);
        airplanes = airplanes->next;
        if (airplane == NULL)
            continue;
        if (airplane_can_move(airplane, first_call))
            move_airplane(airplane);
    }
    first_call = sfFalse;
}