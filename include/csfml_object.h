/*
** EPITECH PROJECT, 2019
** My_Lib_C
** File description:
** csfml_object.h
*/

#ifndef HEADER_CSFML_OBJECT
#define HEADER_CSFML_OBJECT

#include <SFML/Graphics.h>
#include <stdlib.h>

enum OBJECTS
{
    WORLD_MAP,
    AIRPLANE
};

typedef struct info
{
    char const *filepath;
    sfIntRect rect;
    int nb_sprites;
} info_t;

typedef struct object
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfIntRect default_rect;
    sfVector2f pos;
    sfVector2f size;
    unsigned int index_sprite;
    unsigned int nb_sprites;
} object_t;

object_t *create_object(enum OBJECTS obj, float width, float height);
void destroy_object(object_t *object);
void draw_object(sfRenderWindow *window, object_t *object);
void animate_object(object_t *object);
void refresh_object(object_t *object);
void resize_object(object_t *object, float width, float height);
void move_object(object_t *object, float x_move, float y_move);
void set_pos_object(object_t *object, sfVector2f position);

#endif