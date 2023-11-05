/*
** EPITECH PROJECT, 2023
** my_inthex
** File description:
** changes an unsigned int into its hex value
*/
#include "../my.h"
#include <stdlib.h>

char *my_inthex(unsigned long num)
{
    char *result = malloc(sizeof(char) * 10);
    int remainder;
    const char values[16] = {
        '0', '1', '2', '3',
        '4', '5', '6', '7',
        '8', '9', 'a', 'b',
        'c', 'd', 'e', 'f'
    };
    int i = 0;

    for (num; num > 0; num = num / 16) {
        remainder = num % 16;
        result[i] = values[remainder];
        i++;
    }
    result[i] = '\0';
    my_revstr(result);
    return result;
}
