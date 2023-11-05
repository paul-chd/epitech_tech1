/*
** EPITECH PROJECT, 2023
** my_printf.c
** File description:
** Partially recreates the printf function
*/
#include "my.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

const int (*SPECIFIER_FUNCTIONS[20])(va_list, flag_t *) = {
    show_a,
    show_a_upcase,
    show_b,
    show_c,
    show_d_i,
    show_d_i,
    show_e,
    show_e_upcase,
    show_f,
    show_f_upcase,
    show_g,
    show_g_upcase,
    show_n,
    show_o,
    show_p,
    show_percent,
    show_s,
    show_u,
    show_x,
    show_x_upcase};

const char SPECIFIERS[20] = {
    'a', 'A', 'b', 'c',
    'd', 'i', 'e', 'E',
    'f', 'F', 'g', 'G',
    'n', 'o', 'p', '%',
    's', 'u', 'x', 'X'};

const char *LENGTH_TYPES[6] = {"d", "h", "hh", "l", "ll", "L"};

bool is_specifier(const char c)
{
    for (int i = 0; i < 20; i++) {
        if (c == SPECIFIERS[i]) {
            return (true);
        }
    }
    return (false);
}

static void change_specifier(const char c, flag_t *flag)
{
    for (int i = 0; i < 20; i++) {
        if (c == SPECIFIERS[i]) {
            flag->specifier.arg_type = i;
            return;
        }
    }
    flag->specifier.arg_type = -1;
    return;
}

static void my_getmodifiers(const char *str,
    flag_t *current_flag, int *flag_end, int *char_count)
{
    int flag_start = *flag_end;

    change_flags(str, current_flag, flag_end);
    change_width(str, current_flag, flag_end);
    change_precision(str, current_flag, flag_end);
    change_length(str, current_flag, flag_end);
    change_specifier(str[*flag_end], current_flag);
    if (current_flag->specifier.arg_type == -1) {
        my_putchar('%');
        *flag_end = flag_start - 1;
    }
}

static void my_putflag(flag_t *current_flag, va_list args, int *char_count)
{
    if (current_flag->specifier.arg_type == -1) {
        return;
    }
    if (current_flag->width.width_in_prev_arg) {
        current_flag->width.min_nb_of_putchar = va_arg(args, int);
    }
    *char_count += SPECIFIER_FUNCTIONS[current_flag->specifier.arg_type]
        (args, current_flag);
    return;
}

int my_printf(const char *format, ...)
{
    int char_count = 0;
    flag_t current_flag;
    va_list args;

    init_default_flag(&current_flag);
    va_start(args, format);
    for (int i = 0; i < my_strlen(format); i++) {
        if (format[i] == '%') {
            i++;
            my_getmodifiers(format, &current_flag, &i, &char_count);
            my_putflag(&current_flag, args, &char_count);
            init_default_flag(&current_flag);
        } else {
            my_putchar(format[i]);
            char_count++;
        }
    }
    va_end(args);
    return (char_count);
}
