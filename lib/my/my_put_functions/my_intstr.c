/*
** EPITECH PROJECT, 2023
** my_intstr
** File description:
** transforms an integer into a string
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../my.h"

int count_int(long long n)
{
    int count = 0;

    while (n != 0) {
        n = n / 10;
        count++;
    }
    return count;
}

static int print_int(long long num, char *return_str, int i)
{
    while (num != 0) {
        return_str[i++] = (num % 10) + '0';
        num /= 10;
    }
    return i;
}

char *my_intstr(long long num)
{
    char *return_str = malloc(sizeof(char) * 21);
    int count = 0;
    int i = 0;
    bool isneg = false;
    long long n = num;

    if (num < 0) {
        isneg = true;
        num = -num;
        n = -num;
    }
    count = count_int(n);
    i = print_int(num, return_str, i);
    if (isneg == true) {
        return_str[i] = '-';
        i++;
    }
    my_revstr(return_str);
    return_str[i] = '\0';
    return return_str;
}
