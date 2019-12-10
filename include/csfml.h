/*
** EPITECH PROJECT, 2019
** csfml.h
** File description:
** Header for CSFML projects
*/

#ifndef HEADER_CSFML
#define HEADER_CSFML

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "csfml_object.h"
#include "csfml_spritesheet.h"

typedef struct framebuffer
{
    unsigned int width;
    unsigned int height;
    unsigned char *pixels;
    sfTexture *texture;
    sfSprite *sprite;
} framebuffer_t;

sfRenderWindow *create_window(char const *title, int width, int height);
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void framebuffer_update(framebuffer_t *fb);
void framebuffer_destroy(framebuffer_t *fb);
void put_pixel(framebuffer_t *f, unsigned int x, unsigned int y, sfColor color);
void draw_square(framebuffer_t *framebuffer, sfVector2u position,
    unsigned int size, sfColor color);
int elapsed_time(float milliseconds, sfClock *clock);

#endif
