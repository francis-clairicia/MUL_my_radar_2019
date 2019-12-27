/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** separating_axis_method.c
*/

#include "my_radar.h"

static sfVector2f normalize_vector(sfVector2f vector)
{
    float norm = vector_norm(vector);

    vector.x /= norm;
    vector.y /= norm;
    return (vector);
}

static void project_shape(sfVector2f axis, sfVector2f points[4],
    float *min, float *max)
{
    int i = 1;
    float d_prod = dot_product(axis, points[0]);

    *min = d_prod;
    *max = d_prod;
    while (i < 4) {
        d_prod = dot_product(axis, points[i]);
        if (d_prod < *min)
            *min = d_prod;
        else if (d_prod > *max)
            *max = d_prod;
        i += 1;
    }
}

static float interval_distance(float minA, float maxA, float minB, float maxB)
{
    if (minA < minB)
        return (minB - maxA);
    else
        return (minA - maxB);
}

int separating_axis_method(sfVector2f edges_first[4],
    sfVector2f points_first[4], sfVector2f points_second[4])
{
    sfVector2f axis;
    float minA = 0;
    float minB = 0;
    float maxA = 0;
    float maxB = 0;
    int i = 0;

    while (i < 4) {
        axis.x = -(edges_first[i].y);
        axis.y = edges_first[i].x;
        axis = normalize_vector(axis);
        project_shape(axis, points_first, &minA, &maxA);
        project_shape(axis, points_second, &minB, &maxB);
        if (interval_distance(minA, maxA, minB, maxB) > 0)
            return (0);
        i += 1;
    }
    return (1);
}