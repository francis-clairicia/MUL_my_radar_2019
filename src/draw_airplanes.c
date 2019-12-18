/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** draw_airplanes.c
*/

#include "my_radar.h"

static void draw_airplane(sfRenderWindow *window, airplane_t *airplane)
{
    sfVector2f hitbox_pos = sfRectangleShape_getPosition(airplane->shape);
    sfVector2f hitbox_size = sfRectangleShape_getSize(airplane->shape);
    float a = to_radians(airplane->angle);
    float x = (hitbox_size.x / 2.0) * cos(a);
    float y = (hitbox_size.y / 2.0) * sin(a);

    if (airplane->take_off == sfFalse)
        return;
    if (airplane->land_on || airplane->destroyed)
        return;
    if (airplane->outline)
        sfRenderWindow_drawRectangleShape(window, airplane->shape, NULL);
    if (airplane->show_sprite) {
        sfSprite_setRotation(airplane->object->sprite, airplane->angle);
        set_pos_object(airplane->object, hitbox_pos);
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