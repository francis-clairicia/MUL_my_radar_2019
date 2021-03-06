/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** move_object.c
*/

#include "csfml.h"

void move_object(object_t *object, float x_move, float y_move)
{
    sfVector2f offset = {x_move, y_move};

    sfSprite_move(object->sprite, offset);
}

void set_pos_object(object_t *object, sfVector2f position)
{
    sfSprite_setPosition(object->sprite, position);
}