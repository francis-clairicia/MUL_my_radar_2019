/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** draw_towers.c
*/

#include "my_radar.h"

void draw_towers(sfRenderWindow *window, list_t *towers)
{
    tower_t *tower;

    while (towers != NULL) {
        tower = (tower_t *)(towers->data);
        if (tower == NULL) {
            towers = towers->next;
            continue;
        }
        if (tower->show_area)
            sfRenderWindow_drawCircleShape(window, tower->area, NULL);
        if (tower->show_sprite)
            draw_object(window, tower->object);
        towers = towers->next;
    }
}