/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** draw_object.c
*/

#include "csfml.h"

void draw_object(sfRenderWindow *window, object_t *object)
{
    sfRenderWindow_drawSprite(window, object->sprite, NULL);
}