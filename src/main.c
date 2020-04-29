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

void change_speed(data_t *car)
{

}

float get_angle(data_t *car)
{
    if (car->front_left > car->front_right)
        car->angle = 0.08;
    else if (car->front_right > car->front_left)
        car->angle = -0.08;
    else
        car->angle = 0.0;
    
    if (car->front_left < 350)
        car->angle -= 0.15;
    if (car->front_right < 350)
        car->angle += 0.15;
    if (car->front_left < 250)
        car->angle -= 0.25;
    if (car->front_right < 250)
        car->angle += 0.25;
}

int main(void)
{
    data_t *car = malloc(sizeof(data_t));

    car = init_car(car);
    start_simulation();
    while (1) {
        get_info_lidar(car);
        move_forward(0.2);
        get_angle(car);
        dprintf(2, "left %f  right %f\n  angle : %f\n", car->front_left, car->front_right, car->angle);
        change_wheel(car->angle);
    }
    return (0);
}
