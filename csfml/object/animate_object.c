/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Sprite objects
*/

#include "csfml.h"

void animate_object(object_t *object)
{
    if (object->index_sprite < object->nb_sprites) {
        (object->sprite_rect).left += (object->sprite_rect).width;
        object->index_sprite += 1;
    } else {
        (object->sprite_rect).left = object->default_rect.left;
        object->index_sprite = 1;
    }
    refresh_object(object);
}