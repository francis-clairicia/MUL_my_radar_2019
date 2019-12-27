/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** shape_intersection.c
*/

#include "my_radar.h"

static void get_edges(sfVector2f edges[4][2], sfRectangleShape *shape)
{
    sfTransform transform = sfRectangleShape_getTransform(shape);
    sfVector2f point_0 = sfRectangleShape_getPoint(shape, 0);
    sfVector2f point_1 = sfRectangleShape_getPoint(shape, 1);
    sfVector2f point_2 = sfRectangleShape_getPoint(shape, 2);
    sfVector2f point_3 = sfRectangleShape_getPoint(shape, 3);

    edges[0][0] = sfTransform_transformPoint(&transform, point_0);
    edges[0][1] = sfTransform_transformPoint(&transform, point_1);
    edges[1][0] = sfTransform_transformPoint(&transform, point_1);
    edges[1][1] = sfTransform_transformPoint(&transform, point_2);
    edges[2][0] = sfTransform_transformPoint(&transform, point_2);
    edges[2][1] = sfTransform_transformPoint(&transform, point_3);
    edges[3][0] = sfTransform_transformPoint(&transform, point_3);
    edges[3][1] = sfTransform_transformPoint(&transform, point_0);
}

static int edge_intersection(sfVector2f edge[2], sfVector2f edges_other[4][2])
{
    int i = 0;

    while (i < 4) {
        if (segment_intersection(edge, edges_other[i]))
            return (1);
        i += 1;
    }
    return (0);
}

int shape_intersection(sfRectangleShape *shape_A, sfRectangleShape *shape_B)
{
    sfVector2f edges_A[4][2];
    sfVector2f edges_B[4][2];
    int i = 0;

    get_edges(edges_A, shape_A);
    get_edges(edges_B, shape_B);
    while (i < 4) {
        if (edge_intersection(edges_A[i], edges_B))
            return (1);
        i += 1;
    }
    return (0);
}