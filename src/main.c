/*
** EPITECH PROJECT, 2019
** ai
** File description:
** need4stek projet
*/

#include "n4s.h"

data_t *init_car(data_t *car)
{
    car->direction = 0;
    car->end = 0;
    car->front = 0;
    car->front_left = 0;
    car->front_right = 0;
    car->result = NULL;
    car->rotate = 0;
    car->middle = 0;
    car->speed = 0;
    car->angle = 0;
}

float get_angle(data_t *car)
{
    if (car->front_left > car->front_right)
        car->angle = 0.02;
    else if (car->front_right > car->front_left)
        car->angle = -0.02;
    else
        car->angle = 0.0;
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
    change_wheel(car->angle);
}

void change_speed(data_t *car)
{
    if (car->front > 2900 && (car->angle <= 0.08 || car->angle >= -0.08))
        car->speed = 0.6;
    else if (car->front > 1800 && (car->angle <= 0.1 || car->angle >= -0.1))
        car->speed += 0.02;
    if (car->front < 1800)
        car->speed -= 0.45;
    if (car->front < 500)
        car->speed = 0.25;  
    if (car->speed <= 0)
        car->speed = 0.2;
    if (car->front > 150) {
        move_forward(car->speed);
    }
    else {
        if (car->front_right > car->front_left)
            change_wheel(0.2);
        if (car->front_left > car->front_right)
            change_wheel(-0.2);
        move_backward(0.3);
        get_angle(car);
    }
    dprintf(2, "front: %f  right %f   left %f\n", car->front, car->front_right, car->front_left);
}

int main(void)
{
    data_t *car = malloc(sizeof(data_t));

    car = init_car(car);
    start_simulation();
    while (car->end != 1) {
        get_info_lidar(car);
        get_angle(car);
        change_speed(car);
    }
    return (0);
}
