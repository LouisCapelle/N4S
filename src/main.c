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
    car->angle_left = 0;
    car->angle_right = 0;
}

void get_middle(data_t * car)
{
    float result = 0;

    result = (car->front_left + car->front_right) / 2;
    car->middle = result;
}

void change_speed(data_t *car)
{
    dprintf(2, "%f\n", car->speed);
    if (car->front > 1000 && car->angle_left == 0 && car->angle_right == 0) {
        car->speed += 0.025;
        move_forward(car->speed);
    }
    else {
        car->speed = 0.15;
        move_forward(car->speed);
    }
    if (car->speed >= 0.70)
        car->speed = 0.70;
}

float get_angle_right(data_t *car)
{
    float result = 0;

    if (car->front_right > car->middle + 500) {
        car->keep_right = car->front_right;
        car->angle_right = 0.0;
    } 
    else if (car->front_right < 370 && car->front_right > 200)
        car->angle_right = 0.2;
    else if (car->front_right < 200)
        car->angle_right = 0.35;
}

float get_angle_left(data_t *car)
{
    float result = 0;

    if (car->front_left > car->middle + 500) {
        car->angle_left = 0.0;
        car->keep_left = car->front_left;
    }
    else if (car->front_left < 370 && car->front_left > 200)
        car->angle_left = -0.2;
    else if (car->front_left < 200)
        car->angle_left = -0.35;
}

void change_orientation(data_t *car)
{
    float left = car->middle + 20;
    float right = car->middle + 20;

    get_angle_left(car);
    get_angle_right(car);
    if (left > car->front_left) {
        change_wheel(car->angle_left);
    }
    else if (right > car->front_right) {
        change_wheel(car->angle_right);
    }
    else if (car->angle_left < 0 && left < car->front_left - 40 && left > car->front_left) {
        change_wheel(0);
    }
    else if (car->angle_right > 0 && right < car->front_right - 40 && right > car->front_right) {
        change_wheel(0);
    }
    dprintf(2, "right %f   lfet %f\n", right, left);
}

int main(void)
{
    data_t *car = malloc(sizeof(data_t));

    car = init_car(car);
    start_simulation();
    while (1) {
        get_info_lidar(car);
        change_speed(car);
        get_middle(car);
        change_orientation(car);
        dprintf(2, "middle: %f\n", car->middle);
        dprintf(2, "front: %f, front right: %f, front left: %f\n", car->front, car->front_right, car->front_left);
    }
    return (0);
}
