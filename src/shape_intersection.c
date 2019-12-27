/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** shape_intersection.c
*/

#include "my_radar.h"

static void get_edges(sfVector2f edges[4], sfVector2f points[4],
    sfRectangleShape *shape)
{
    sfTransform transform = sfRectangleShape_getTransform(shape);
    sfVector2f point_0 = sfRectangleShape_getPoint(shape, 0);
    sfVector2f point_1 = sfRectangleShape_getPoint(shape, 1);
    sfVector2f point_2 = sfRectangleShape_getPoint(shape, 2);
    sfVector2f point_3 = sfRectangleShape_getPoint(shape, 3);

    points[0] = sfTransform_transformPoint(&transform, point_0);
    points[1] = sfTransform_transformPoint(&transform, point_1);
    points[2] = sfTransform_transformPoint(&transform, point_2);
    points[3] = sfTransform_transformPoint(&transform, point_3);
    edges[0] = vector(points[0], points[1]);
    edges[1] = vector(points[1], points[2]);
    edges[2] = vector(points[2], points[3]);
    edges[3] = vector(points[3], points[0]);
}

int shape_intersection(sfRectangleShape *shape_A, sfRectangleShape *shape_B)
{
    sfVector2f edges_A[4];
    sfVector2f points_A[4];
    sfVector2f edges_B[4];
    sfVector2f points_B[4];

    get_edges(edges_A, points_A, shape_A);
    get_edges(edges_B, points_B, shape_B);
    if (separating_axis_method(edges_A, points_A, points_B) == 1
    || separating_axis_method(edges_B, points_B, points_A) == 1)
        return (1);
    return (0);
}