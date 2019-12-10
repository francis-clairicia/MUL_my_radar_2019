/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** view.c
*/

#include "my_radar.h"

static void handle_zoom(sfMouseWheelScrollEvent event, sfView *view)
{
    float zoom = (event.delta == 1.f) ? 1.1 : 0.9;
    sfVector2f size = sfView_getSize(view);
    sfVector2f center;

    if (size.x * zoom <= 1920 && size.x * zoom > 0)
        sfView_zoom(view, zoom);
    size = sfView_getSize(view);
    center = sfView_getCenter(view);
    if (center.x - (size.x / 2) < 0)
        center.x = size.x / 2;
    if (center.y - (size.y / 2) < 0)
        center.y = size.y / 2;
    if (center.x + (size.y / 2) > 1920)
        center.x = 1920 - (size.x / 2);
    if (center.y + (size.y / 2) > 1080)
        center.y = 1080 - (size.y / 2);
    sfView_setCenter(view, center);
}

static void handle_move(sfMouseMoveEvent event, sfView *view,
    sfVector2i mouse_pos)
{
    sfVector2f offset;
    sfVector2f center = sfView_getCenter(view);
    sfVector2f size = sfView_getSize(view);
    sfVector2f pos;

    offset.x = event.x - mouse_pos.x;
    offset.y = event.y - mouse_pos.y;
    pos.x = (center.x + offset.x) - (size.x / 2);
    pos.y = (center.y + offset.y) - (size.y / 2);
    if (pos.x >= 0 && pos.x + size.x <= 1920
    && pos.y >= 0 && pos.y + size.y <= 1080)
        sfView_move(view, offset);
}

void handle_view(sfEvent event, sfView *view, sfVector2i mouse_pos)
{
    if (event.type == sfEvtMouseWheelScrolled)
        handle_zoom(event.mouseWheelScroll, view);
    if (event.type == sfEvtMouseMoved && sfMouse_isButtonPressed(sfMouseLeft))
        handle_move(event.mouseMove, view, mouse_pos);
}