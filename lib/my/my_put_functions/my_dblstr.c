/*
** EPITECH PROJECT, 2023
** my_dblstr
** File description:
** puts a float number to a string
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../my.h"

void add_integer_part(double num, char *result, int *result_count)
{
    int remainder;
    int leading_zeros = 0;
    long long reverse = 0;
    long long number = (long long)num;

    if (number == 0) {
        result[(*result_count)++] = '0';
        return;
    }
    for (number; number != 0; number /= 10) {
        remainder = number % 10;
        if (remainder == 0 && reverse == 0)
            leading_zeros++;
        reverse = reverse * 10 + remainder;
    }
    for (reverse; reverse != 0; reverse /= 10)
        result[(*result_count)++] = (reverse % 10) + '0';
    while (leading_zeros-- > 0)
        result[(*result_count)++] = '0';
}

void loop_print_float(int length, double float_part, char *result, int *count)
{
    int i;
    int a;
    int digit_float;
    long long multiplier = 1;

    for (a = 0; a < length; a++) {
    multiplier = multiplier * 10;
    }
    result[(*count)++] = '.';
    float_part = float_part * multiplier + 0.5;
    float_part = float_part / multiplier;
    for (i = 0; i < length; i++) {
        float_part *= 10;
        digit_float = (int)float_part;
        result[(*count)++] = '0' + digit_float;
        float_part -= digit_float;
    }
    result[*count] = '\0';
}

char *my_dblstr(double num, int length)
{
    int result_count = 0;
    int total_length = 21 + 1;
    char *result;

    if (length > 0)
        total_length += length + 1;
    if (length == 0)
        num += 0.5;
    result = malloc((total_length + 1) * sizeof(char));
    if (num < 0) {
        result[result_count++] = '-';
        num = -num;
    }
    add_integer_part(num, result, &result_count);
    if (length > 0) {
        loop_print_float(length, num - (long long)num, result, &result_count);
    }
    return result;
}
