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
void start(void);
void move_car(float speed);
void speed_change(data_t *tesla);
void pass_line(void);
void change_wheel(float value);
void move_forward(float speed);
char *my_strdup(char *str);
int	my_strlen(char *str);

#endif /* !PROTO_H_ */
