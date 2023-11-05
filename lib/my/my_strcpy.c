/*
** EPITECH PROJECT, 2023
** my_strcpy
** File description:
** copies src string into target dest
*/

#include "my.h"

char *my_strcpy(char *dest, const char *src, int start)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i + start] = src[i];
        i++;
    }
    dest[i + start] = '\0';
    return dest;
}
