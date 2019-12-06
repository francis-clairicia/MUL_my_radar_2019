/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Sprite objects
*/

#include "csfml.h"

static const info_t spritesheet[] = {
    {"img/world_map.jpg", {0, 0, 1920, 1080}, 1},
    {"img/airplane.png", {0, 0, 465, 465}, 1}
};

object_t *create_object(enum OBJECTS obj, float width, float height)
{
    info_t info = spritesheet[obj];
    object_t *object = malloc(sizeof(object_t));
    sfIntRect rect = {0, 0,
        info.rect.width / info.nb_sprites, info.rect.height};

    object->texture = sfTexture_createFromFile(info.filepath, &(info.rect));
    object->sprite = sfSprite_create();
    object->rect = rect;
    refresh_object(object);
    resize_object(object, width, height);
    return (object);
}

void destroy_object(object_t *object)
{
    sfTexture_destroy(object->texture);
    sfSprite_destroy(object->sprite);
    free(object);
}