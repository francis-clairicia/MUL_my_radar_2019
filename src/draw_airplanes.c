/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** draw_airplanes.c
*/

#include "my_radar.h"

static void draw_airplane(sfRenderWindow *window, airplane_t *airplane)
{
    sfVector2f hit_box_pos;
    float x;
    float y;
    float a;

    if (airplane->fly == sfFalse)
        return;
    if (airplane->outline)
        sfRenderWindow_drawRectangleShape(window, airplane->shape, NULL);
    if (airplane->show_sprite) {
        a = sfRectangleShape_getRotation(airplane->shape);
        sfSprite_setRotation(airplane->object->sprite, a);
        a = to_radians(a);
        hit_box_pos = sfRectangleShape_getPosition(airplane->shape);
        x = ((sfRectangleShape_getSize(airplane->shape).x) / 2.0) * cos(a);
        y = ((sfRectangleShape_getSize(airplane->shape).y) / 2.0) * sin(a);
        set_pos_object(airplane->object, hit_box_pos);
        move_object(airplane->object, -x + y, -y - x);
        draw_object(window, airplane->object);
    }
}

void draw_airplanes(sfRenderWindow *window, list_t *airplanes)
{
    airplane_t *airplane;

    while (airplanes != NULL) {
        airplane = (airplane_t *)(airplanes->data);
        if (airplane != NULL)
            draw_airplane(window, airplane);
        airplanes = airplanes->next;
    }
}