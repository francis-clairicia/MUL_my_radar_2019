/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** draw_object.c
*/

#include "csfml.h"

void refresh_object(object_t *object)
{
    sfSprite_setTexture(object->sprite, object->texture, sfFalse);
}

void draw_object(sfRenderWindow *window, object_t *object)
{
    sfRenderWindow_drawSprite(window, object->sprite, NULL);
}