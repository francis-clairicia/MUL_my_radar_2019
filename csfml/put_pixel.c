/*
** EPITECH PROJECT, 2019
** CSFML project
** File description:
** Put a pixel in a framebuffer
*/

#include <csfml.h>

void put_pixel(framebuffer_t *f, unsigned int x, unsigned int y, sfColor color)
{
    unsigned int width = f->width;
    unsigned int height = f->height;
    int pixel = 4 * ((f->width) * y + x);

    (f->pixels)[pixel] = color.r;
    (f->pixels)[pixel + 1] = color.g;
    (f->pixels)[pixel + 2] = color.b;
    (f->pixels)[pixel + 3] = color.a;
    sfTexture_updateFromPixels(f->texture, f->pixels, width, height, 0, 0);
    sfSprite_setTexture(f->sprite, f->texture, sfFalse);
}