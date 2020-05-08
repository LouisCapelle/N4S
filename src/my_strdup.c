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

    if (!dest || !src)
        return NULL;
    while (src[i]) {
        dest[i] = src[i];
        i += 1;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strdup(char *str)
{
    int len = 0;
    char *dup = NULL;

    if (!str)
        return NULL;
    len = my_strlen(str) + 1;
    dup = malloc(sizeof(char) * len);
    if (dup == NULL)
        return NULL;
    dup = my_strcpy(dup, str);
    return (dup);
}