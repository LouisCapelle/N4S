/*
** EPITECH PROJECT, 2020
** strdup
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "n4s.h"

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i]) {
        dest[i] = src[i];
        i += 1;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strdup(char *str)
{
	int len = my_strlen(str) + 1;
	char *dup = malloc(sizeof(char *) * len);

	dup = my_strcpy(dup, str);
	dup[len - 1] = '\0';
	return (dup);
}