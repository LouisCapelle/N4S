/*
** EPITECH PROJECT, 2019
** ai
** File description:
** need4stek projet
*/

#include "n4s.h"

float get_info(data_t *tesla)
{
    float speed = 0.5;
    char *line = NULL;
    size_t len = 0;
    char **tab = NULL;

    getline(&line, &len, stdin);
    tab = my_str_to_word_array(line);
    tesla->front = atof(tab[19]);
    tesla->front_left = atof(tab[3]);
    tesla->front_right = atof(tab[34]);
    tesla->end = (strcmp(tab[35], "Track Cleared") == 0) ? 1 : 0;
    free_tab(tab);
    free(line);
    line = NULL;
    return (speed);
}

void get_result(data_t *tesla)
{
    char *line = NULL;
    size_t len = 0;

    getline(&line, &len, stdin);
    tesla->result = my_strdup(line);
    free(line);
    line = NULL;
}

void start(void)
{
    dprintf(1, "START_SIMULATION\n");
}

void end(data_t *tesla)
{
    if (tesla->end == 1) {
        dprintf(1, "STOP_SIMULATION\n");
    }
}

data_t *init_car(data_t *car)
{
    car->direction = 0;
    car->end = 0;
    car->front = 0;
    car->front_left = 0;
    car->front_right = 0;
    car->result = NULL;
    car->rotate = 0;
}

int main(void)
{
    data_t *car = malloc(sizeof(data_t));

    car = init_car(car);
    start();
    while (car->end == 0) {
        move_forward(0.5);
    }
    return (0);
}
