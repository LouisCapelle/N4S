/*
** EPITECH PROJECT, 2019
** ai
** File description:
** need4stek projet
*/

#include "n4s.h"

float get_info(data_car_t *tesla)
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

void pass_line(void)
{
    char *line = NULL;
    size_t len = 0;

    getline(&line, &len, stdin);
    free(line);
    line = NULL;
}

void start(void)
{
    dprintf(1, "START_SIMULATION\n");
    pass_line();
}

void end(data_car_t *tesla)
{
    if (tesla->end == 1) {
        dprintf(1, "STOP_SIMULATION\n");
        pass_line();
    }
}

int main(void)
{
    data_car_t tesla = {0, 0, 0, 0, 0, 1};

    start();
    while (1 && tesla.end == 0) {
        if (tesla.rotate == 1)
            change_wheel(0.05 * tesla.direction);
        dprintf(1, "GET_INFO_LIDAR\n");
        get_info(&tesla);
        end(&tesla);
        speed_change(&tesla);
    }
    return (0);
}
