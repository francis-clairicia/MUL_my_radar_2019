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
    sfVector2f point_1 = sfRectangleShape_getPoint(shape, 0);
    sfVector2f point_2;
    int i = 0;
    int j = 0;

    while (i < 4) {
        j = (i + 1 == 4) ? 0 : i + 1;
        point_2 = sfRectangleShape_getPoint(shape, j);
        edges[i][0] = sfTransform_transformPoint(&transform, point_1);
        edges[i][1] = sfTransform_transformPoint(&transform, point_2);
        i += 1;
        point_1 = point_2;
    }
}

static int edge_intersection(sfVector2f edge[2], sfVector2f edges_other[4][2],
    int size)
{
    int i = 0;

    while (i < size) {
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
        if (edge_intersection(edges_A[i], &edges_B[i], 4 - i))
            return (1);
        i += 1;
    }
    return (0);
}