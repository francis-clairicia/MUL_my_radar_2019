/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Sprite objects
*/

#include "csfml.h"

void resize_object(object_t *object, float width, float height)
{
    float x_scale = width / (object->rect).width;
    float y_scale = height / (object->rect).height;
    sfVector2f scale = {x_scale, y_scale};

    sfSprite_scale(object->sprite, scale);
    (object->size).x = width;
    (object->size).y = height;
}