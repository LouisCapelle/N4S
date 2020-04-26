/*
** EPITECH PROJECT, 2019
** ai
** File description:
** need4stek projet
*/

#include "n4s.h"

float change_speed(data_car_t *tesla)
{
    float speed = 0;

    if (tesla->front > 2300){
        speed = 0.6;
    } else if (tesla->front > 1000) {
        speed = 0.5;
    } else if (tesla->front > 700) {
        speed = 0.4;
    }else if (tesla->front > 600) {
        speed = 0.3;
    }else if (tesla->front > 300) {
        speed = 0.2;
    }else if (tesla->front <= 300) {
        speed = 0.1;
    }
    if (tesla->front <= 500 || tesla->front_left <= 200 ||
    tesla->front_right <= 200) {
        speed = 0.05;
        tesla->rotate = 0;
    } else {
        tesla->rotate = 1;
    }
    return (speed);
}

void move_forward(float speed)
{
    dprintf(1, "CAR_FORWARD:%.1f\n", speed);
    pass_line();
}

void change_wheel(float value)
{
    dprintf(1, "WHEELS_DIR:%.1f\n", value);
    pass_line();
}

void found_virage(data_car_t *tesla)
{
    if (tesla->front_left < 100 || tesla->front_right < 100)
        return;
    if (tesla->front_left > tesla->front_right) {
        tesla->direction = 1;
        change_wheel(0.5);
    } else if (tesla->front_right > tesla->front_left) {
        tesla->direction = -1;
        change_wheel(-0.5);
    }
}

void speed_change(data_car_t *tesla)
{
    float speed = change_speed(tesla);

    move_forward(speed);
    found_virage(tesla);
}