/*
** EPITECH PROJECT, 2023
** put_float
** File description:
** prints out float number
*/

#include <stdio.h>
#include "../my.h"

void loop_print_float(int length_comma, double float_part, int digit_float)
{
    for (length_comma; length_comma > 0; length_comma--) {
        float_part *= 10;
        digit_float = (int)float_part;
        my_putchar('0' + digit_float);
        float_part -= digit_float;
    }
}

void my_putfloat(double num, int length_comma)
{
    long long integer_part;
    double float_part;
    int digit_integer;
    int digit_float;

    if (num < 0) {
        my_putchar('-');
        num = -num;
    }
    integer_part = (long long)num;
    float_part = num - integer_part;
    if ((long long)num == 0) {
        my_putchar('0');
    } else {
        my_put_nbr(integer_part);
    }
    if (length_comma > 0) {
        my_putchar('.');
    }
    loop_print_float(length_comma, float_part, digit_float);
}
