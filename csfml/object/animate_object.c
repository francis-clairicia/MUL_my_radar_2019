/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Sprite objects
*/

#include "csfml.h"

void refresh_object(object_t *object)
{
    sfSprite_setTexture(object->sprite, object->texture, sfFalse);
    sfSprite_setTextureRect(object->sprite, object->rect);
}

void animate_object(object_t *object)
{
    if (object->index_sprite < object->nb_sprites) {
        (object->rect).left += (object->rect).width;
        object->index_sprite += 1;
    } else {
        (object->rect).left = object->default_rect.left;
        object->index_sprite = 1;
    }
    refresh_object(object);
}