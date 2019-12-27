/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** segment_intersection.c
*/

#include "my_radar.h"

static int bounding_box_collision(sfVector2f a[2], sfVector2f b[2])
{
    return (a[0].x <= b[1].x
    && a[1].x >= b[0].x
    && a[0].y <= b[1].y
    && a[1].y >= b[0].y);
}

static int point_on_line_support_of_segment(sfVector2f segment[2],
    sfVector2f point)
{
    sfVector2f director_vector = vector(segment[0], segment[1]);

    return (point_on_line(segment[0], director_vector, point));
}

static int point_right_to_segment(sfVector2f segment[2], sfVector2f point)
{
    sfVector2f u = vector(segment[0], segment[1]);
    sfVector2f v = vector(segment[0], point);

    return (cross_product(u, v) <= 0);
}

static int segment_touchs_or_crosses_line(sfVector2f a[2], sfVector2f b[2])
{
    int p1 = point_on_line_support_of_segment(a, b[0]);
    int p2 = point_on_line_support_of_segment(a, b[1]);
    int p3 = point_right_to_segment(a, b[0]);
    int p4 = point_right_to_segment(a, b[1]);

    return (p1 || p2 || (p3 ^ p4));
}

int segment_intersection(sfVector2f segment_1[2], sfVector2f segment_2[2])
{
    return (bounding_box_collision(segment_1, segment_2)
    && segment_touchs_or_crosses_line(segment_1, segment_2)
    && segment_touchs_or_crosses_line(segment_2, segment_1));
}