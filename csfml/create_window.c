/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** create_window.c
*/

#include <csfml.h>

sfRenderWindow *create_window(char const *title, int width, int height)
{
    sfVideoMode v_mod = {width, height, 32};
    sfUint32 style = sfDefaultStyle;
    sfRenderWindow *w = sfRenderWindow_create(v_mod, title, style, NULL);

    sfRenderWindow_setFramerateLimit(w, 60);
    return (w);
}