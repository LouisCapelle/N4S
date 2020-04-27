/*
** EPITECH PROJECT, 2019
** proto
** File description:
** 2018
*/

#ifndef PROTO_H_
#define PROTO_H_

void free_tab(char **tab);
char **my_str_to_word_array(char *str);
float calc(float distance);
void move_car(float speed);
void speed_change(data_t *tesla);
void pass_line(void);
void change_wheel(float value);
void move_forward(float speed);
char *my_strdup(char *str);
int	my_strlen(char *str);
void start_simulation(void);
void end_simulation(void);
void move_forward(float speed);
void change_wheel(float value);
void parse_lidar(char *result, data_t *car);
void get_info_lidar(data_t *car);

#endif /* !PROTO_H_ */
