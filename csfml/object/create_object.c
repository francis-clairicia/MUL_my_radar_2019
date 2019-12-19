/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Sprite objects
*/

#include "csfml.h"
#include "csfml_spritesheet.h"

object_t *create_object(enum OBJECTS obj)
{
    info_t info = spritesheet[obj];
    object_t *object = malloc(sizeof(object_t));
    sfIntRect sprite_rect = {0, 0, 0, 0};

    if (info.rect.width > 0 && info.rect.height > 0)
        object->texture = sfTexture_createFromFile(info.filepath, &(info.rect));
    else
        object->texture = sfTexture_createFromFile(info.filepath, NULL);
    object->sprite = sfSprite_create();
    object->sprite_rect = sprite_rect;
    object->default_rect = sprite_rect;
    refresh_object(object);
    set_pos_object(object, info.position);
    return (object);
}

void destroy_object(object_t *object)
{
    sfTexture_destroy(object->texture);
    sfSprite_destroy(object->sprite);
    free(object);
}