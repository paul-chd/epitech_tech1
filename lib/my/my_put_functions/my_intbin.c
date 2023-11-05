/*
** EPITECH PROJECT, 2023
** my_inthex
** File description:
** changes an unsigned int into its hex value
*/
#include "../my.h"
#include <stdlib.h>

char *my_intbin(unsigned long num)
{
    char *result = malloc(sizeof(char) * 33);
    int remainder;
    const char values[2] = {
        '0', '1'
    };
    int i = 0;

    for (num; num > 0; num = num / 2) {
        remainder = num % 2;
        result[i] = values[remainder];
        i++;
    }
    result[i] = '\0';
    my_revstr(result);
    return result;
}
