/*
** EPITECH PROJECT, 2020
** angle
** File description:
** angle
*/

#include "n4s.h"

void get_angle_next(data_t *car)
{
    if (car->front_left < 350) {
        car->speed -= 0.15;
        car->angle -= 0.20;
    }
    if (car->front_right < 350) {
        car->angle += 0.15;
        car->speed -= 0.15;
    }
    if (car->front_left < 250) {
        car->angle -= 0.31;
        car->speed -= 0.15;
    }
    if (car->front_right < 250) {
        car->speed -= 0.15;
        car->angle += 0.31;
    }
}

void get_angle(data_t *car)
{
    if (car->front_left > car->front_right)
        car->angle = 0.02;
    else if (car->front_right > car->front_left)
        car->angle = -0.02;
    else
        car->angle = 0.0;
    get_angle_next(car);
    change_wheel(car->angle);
}