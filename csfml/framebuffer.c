/*
** EPITECH PROJECT, 2019
** CSFML project
** File description:
** Generate a framebuffer
*/

#include <csfml.h>

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *fb = malloc(sizeof(framebuffer_t));
    fb->width = width;
    fb->height = height;
    fb->pixels = malloc(width * height * 4);
    fb->texture = sfTexture_create(width, height);
    fb->sprite = sfSprite_create();
    return (fb);
}

void framebuffer_update(framebuffer_t *fb)
{
    sfTexture_updateFromPixels(fb->texture, fb->pixels,
        fb->width, fb->height, 0, 0);
    sfSprite_setTexture(fb->sprite, fb->texture, sfFalse);
}

void framebuffer_destroy(framebuffer_t *fb)
{
    free(fb->pixels);
    sfTexture_destroy(fb->texture);
    sfSprite_destroy(fb->sprite);
    free(fb);
}