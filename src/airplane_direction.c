/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** airplane_direction.c
*/

#include "my_radar.h"

void determine_rotate_side(airplane_t *airplane, int former_angle)
{
    int new_angle = airplane->angle;
    int former_angle_2 = former_angle;
    unsigned int r_clockwise = 0;
    unsigned int r_counter_clockwise = 0;

    while (former_angle != new_angle) {
        r_clockwise += 1;
        former_angle = conditionate_angle(former_angle + 1);
    }
    while (former_angle_2 != new_angle) {
        r_counter_clockwise += 1;
        former_angle_2 = conditionate_angle(former_angle_2 - 1);
    }
    airplane->rotate_side = (r_counter_clockwise > r_clockwise) ? 1 : -1;
    airplane->rotate_offset = (airplane->rotate_side == 1) ?
    r_clockwise : r_counter_clockwise;
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
        angle += 2 * sin(angle);
    angle_in_degrees = conditionate_angle(to_degrees(angle));
    airplane->direction.x = cos(angle);
    airplane->direction.y = sin(angle);
    airplane->angle = (-sin(angle) >= 0) ?
    angle_in_degrees : 360 - angle_in_degrees;
    return (angle_in_degrees);
}

void calculate_airplane_direction(airplane_t *airplane, sfBool animation)
{
    int f_angle = airplane->angle;
    float sprite_angle;

    sprite_angle = get_airplane_direction(airplane);
    airplane->head_for_arrival = sfTrue;
    if (animation) {
        determine_rotate_side(airplane, f_angle);
    } else {
        sfRectangleShape_setRotation(airplane->shape, sprite_angle);
        airplane->rotate_side = 0;
    }
}

void change_airplane_direction(airplane_t *airplane, int angle_direction)
{
    float (*c_angle)(float) = conditionate_angle;
    int angle = airplane->angle;

    airplane->angle = c_angle(airplane->angle + angle_direction);
    determine_rotate_side(airplane, angle);
    airplane->rotate_offset = abs(angle_direction);
    airplane->head_for_arrival = sfFalse;
}

void head_for_arrival(airplane_t *airplane)
{
    calculate_airplane_direction(airplane, sfTrue);
}