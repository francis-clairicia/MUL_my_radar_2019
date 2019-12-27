/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** airplane_on_tower.c
*/

#include "my_radar.h"

static int airplane_on_tower(airplane_t *airplane, list_t *towers)
{
    tower_t *tower;
    sfVector2f airplane_pos = sfRectangleShape_getPosition(airplane->shape);
    sfVector2f center_area;

    while (towers != NULL) {
        tower = (tower_t *)(towers->data);
        center_area = sfCircleShape_getPosition(tower->area);
        if (vector_norm(vector(center_area, airplane_pos)) <= tower->radius)
            return (1);
        towers = towers->next;
    }
    return (0);
}

void check_airplane_on_tower(list_t *airplanes, list_t *towers)
{
    airplane_t *airplane;

    while (airplanes != NULL) {
        airplane = (airplane_t *)(airplanes->data);
        airplane->on_tower_area = airplane_on_tower(airplane, towers);
        airplanes = airplanes->next;
    }
}