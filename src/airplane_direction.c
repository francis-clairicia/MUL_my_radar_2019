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

static void get_airplane_direction(airplane_t *airplane)
{
    sfVector2f pos = sfRectangleShape_getPosition(airplane->shape);
    sfVector2f director_v = {
        airplane->arrival.x - pos.x,
        airplane->arrival.y - pos.y
    };
    float norm_v = sqrt(pow(director_v.x, 2) + pow(director_v.y, 2));
    float angle = acos(director_v.x / norm_v);
    float angle_in_degrees;

    if (airplane->arrival.y < pos.y) {
        angle = asin(sin(-angle));
        if (airplane->arrival.x < pos.x)
            angle -= 2 * cos(angle);
    }
    angle_in_degrees = conditionate_angle(to_degrees(angle));
    airplane->direction.x = cos(angle);
    airplane->direction.y = sin(angle);
    airplane->angle = angle_in_degrees;
    airplane->direction_to_arrival = angle_in_degrees;
}

void calculate_airplane_direction(airplane_t *airplane, sfBool animation)
{
    float f_angle = airplane->angle;

    get_airplane_direction(airplane);
    airplane->head_for_arrival = sfTrue;
    if (animation) {
        determine_rotate_side(airplane, f_angle);
    } else {
        sfRectangleShape_setRotation(airplane->shape, airplane->angle);
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