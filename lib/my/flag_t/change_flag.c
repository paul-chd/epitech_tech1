/*
** EPITECH PROJECT, 2023
** change_flag.c
** File description:
** Contains all functions used to change flag modifiers
*/
#include <stdbool.h>
#include "../my.h"
#include <stdio.h>

const void (*FLAGS_FUNCTIONS[5])(flag_t *flag) = {
    left_justify,
    force_show_sign,
    add_space,
    alternative_display,
    padding_char};

const char FLAGS[5] = {'-', '+', ' ', '#', '0'};

static int is_length(char c)
{
    return (c == 'h' || c == 'l' || c == 'L');
}

static int is_num(char c)
{
    return (c >= 48 && c <= 57);
}

static void l_case(const char *str, flag_t *flag, int *start)
{
    (*start)++;
    flag->length.length_type = 3;
    if (str[*start] == 'l') {
        (*start)++;
        flag->length.length_type = 4;
    }
    return;
}

static void h_case(const char *str, flag_t *flag, int *start)
{
    (*start)++;
    flag->length.length_type = 1;
    if (str[*start] == 'h') {
        (*start)++;
        flag->length.length_type = 2;
    }
    return;
}

void change_length(const char *str, flag_t *flag, int *start)
{
    if (!(is_length(str[*start]))) {
        return;
    }
    switch (str[*start]) {
    case 'l':
        l_case(str, flag, start);
        return;
    case 'h':
        h_case(str, flag, start);
        return;
    case 'L':
        (*start)++;
        flag->length.length_type = 5;
        return;
    }
}

void change_precision(const char *str, flag_t *flag, int *start)
{
    unsigned int i = 0;

    if (str[*start] == '.') {
        (*start)++;
        if (is_digit(str[*start]) == false) {
            flag->_precision.float_precision = 0;
            return;
        }
        if (is_digit(str[*start]) == true) {
            flag->_precision.float_precision = my_getnbr(str + *start);
            *start += count_int(flag->_precision.float_precision);
        } else {
            (*start)++;
            flag->_precision.precision_in_prev_arg = true;
        }
    }
}

void change_width(const char *str, flag_t *flag, int *start)
{
    if (is_digit(str[*start])) {
        flag->width.min_nb_of_putchar = my_getnbr(str + *start);
        *start += count_int(flag->width.min_nb_of_putchar);
    } else if (str[*start] == '*') {
        (*start)++;
        flag->width.width_in_prev_arg = true;
    }
}

static void change_flag(const char c, flag_t *flag, int *start)
{
    for (int i = 0; i < 5; i++) {
        if (c == FLAGS[i]) {
            FLAGS_FUNCTIONS[i](flag);
            return;
        }
    }
}

static bool is_flag(const char c)
{
    for (int i = 0; i < 5; i++) {
        if (c == FLAGS[i]) {
            return (true);
        }
    }
    return (false);
}

void change_flags(const char *str, flag_t *flag, int *start)
{
    for (int i = 0; i < 5; i++) {
        if (is_specifier(str[*start + i]) || !(is_flag(str[*start + i]))) {
            *start += i;
            return;
        } else {
            change_flag(str[*start + i], flag, start);
        }
    }
    return;
}
