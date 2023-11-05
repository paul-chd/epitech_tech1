/*
** EPITECH PROJECT, 2023
** my_strcat.c
** File description:
** placeholder
*/
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int lendest = my_strlen(dest);

    while (src[i] != '\0') {
        dest[lendest + i] = src[i];
        i++;
    }
    dest[lendest + i] = '\0';
    return (dest);
}
