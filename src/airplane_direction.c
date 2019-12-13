/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** airplane_direction.c
*/

#include "my_radar.h"

static void determine_rotate_side(airplane_t *airplane, float former_angle)
{
    float new_angle = airplane->angle;
    int rotate_offset = new_angle - former_angle;

    airplane->rotate_side = rotate_offset / abs(rotate_offset);
    if (abs(rotate_offset) >= 180)
        airplane->rotate_side *= -1;
    airplane->rotate_offset = abs(rotate_offset);
}

float get_airplane_direction(airplane_t *airplane)
{
    sfVector2f pos = sfRectangleShape_getPosition(airplane->shape);
    sfVector2f director_v = {
        airplane->arrival.x - pos.x,
        airplane->arrival.y - pos.y
    };
    float norm_v = sqrt(pow(director_v.x, 2) + pow(director_v.y, 2));
    float angle = acos(director_v.x / norm_v);
    float angle_in_degrees;

    if (airplane->arrival.y < pos.y)
        angle = -angle;
    angle_in_degrees = conditionate_angle(to_degrees(angle));
    airplane->angle = angle_in_degrees;
    airplane->direction_to_arrival = angle_in_degrees;
    return (angle);
}

void calculate_airplane_direction(airplane_t *airplane, sfBool animation)
{
    float f_angle = airplane->angle;
    float d_angle;

    d_angle = get_airplane_direction(airplane);
    if (animation) {
        airplane->head_for_arrival = sfTrue;
        determine_rotate_side(airplane, f_angle);
    } else {
        airplane->direction.x = cos(d_angle);
        airplane->direction.y = sin(d_angle);
        sfRectangleShape_setRotation(airplane->shape, airplane->angle);
        airplane->rotate_side = 0;
    }
}

void change_airplane_direction(airplane_t *airplane,
    float angle_direction, float delay)
{
    float (*c_angle)(float) = conditionate_angle;
    int angle = airplane->angle;

    airplane->angle = c_angle(airplane->angle + angle_direction);
    determine_rotate_side(airplane, angle);
    airplane->rotate_offset = abs((int)angle_direction);
    airplane->head_for_arrival = sfFalse;
    sfClock_restart(airplane->head_for_arrival_clock);
    airplane->delay_before_readjustement = delay * 1000;
}

void head_for_arrival(airplane_t *airplane)
{
    calculate_airplane_direction(airplane, sfTrue);
    airplane->delay_before_readjustement = 0;
}