/*
** EPITECH PROJECT, 2023
** my_getnbr.c
** File description:
** A function that returns a number that is sent to the function as a string.
*/
#include <limits.h>
#include "my.h"

static int detect_multiply_overflow(int a, int multi)
{
    int original_a = a;

    a *= multi;
    a /= multi;
    return (original_a != a);
}

static int detect_add_overflow(int a, int add, int sign)
{
    if (sign > 0) {
        return (add - 48 > (INT_MAX - a));
    } else {
        return (-(add - 48) < (INT_MIN - a));
    }
}

int is_digit(char a)
{
    int b = a - 48;

    return (b <= 9 && b >= 0);
}

static int is_valid_character(char a)
{
    return (is_digit(a) || a == '-' || a == '+');
}

static void change_sign(char a, int *sign)
{
    if (a == '-') {
        *sign *= -1;
    }
    if (!(is_valid_character(a))) {
        *sign = 1;
    }
    return;
}

static int find_sign(char const *str, int *i)
{
    int result = 1;

    while (str[*i] != '\0') {
        if (is_digit(str[*i])) {
            break;
        }
        change_sign(str[*i], &result);
        *i += 1;
    }
    return (result);
}

static void add_nbr(int *result, int i, char const *str, int sign)
{
    if (sign > 0) {
        *result += str[i] - 48;
    } else {
        *result -= str[i] - 48;
    }
    return;
}

int my_getnbr(char const *str)
{
    int result = 0;
    int i = 0;
    int sign = find_sign(str, &i);

    while (is_digit(str[i])) {
        if (detect_add_overflow(result, str[i], sign)) {
            return (0);
        }
        add_nbr(&result, i, str, sign);
        if (!(is_digit(str[i + 1]))) {
            break;
        }
        if (detect_multiply_overflow(result, 10)) {
            return (0);
        }
        result *= 10;
        i++;
    }
    return (result);
}
