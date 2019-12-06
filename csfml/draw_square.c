/*
** EPITECH PROJECT, 2019
** CSFML project
** File description:
** Draw a square in a framebuffer
*/

#include <csfml.h>

void draw_square(framebuffer_t *framebuffer, sfVector2u position,
    unsigned int size, sfColor color)
{
    unsigned int x = position.x;
    unsigned int y = position.y;
    unsigned int i = x;
    unsigned int j = y;

    while (i < (x + size)) {
        while (j < (y + size)) {
            put_pixel(framebuffer, i, j, color);
            j += 1;
        }
        i += 1;
        j = y;
    }
}