/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** clock.c
*/

#include <csfml.h>

int elapsed_time(float milliseconds, sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    int output = 0;

    if ((time.microseconds / 1000.0) >= milliseconds) {
        output = 1;
        sfClock_restart(clock);
    }
    return (output);
}