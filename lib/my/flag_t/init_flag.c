/*
** EPITECH PROJECT, 2023
** init_flag.c
** File description:
** Initializes a given flag (a pointer to a flag_t variable)
*/
#include "../my.h"
#include <stdbool.h>

static void init_default_flags(flag_t *flag)
{
    flag->flags.left_justify = false;
    flag->flags.force_show_sign = false;
    flag->flags.add_space = false;
    flag->flags.alternative_display = false;
    flag->flags.padding_char = ' ';
    return;
}

static void init_default_width(flag_t *flag)
{
    flag->width.min_nb_of_putchar = 1;
    flag->width.width_in_prev_arg = false;
}

static void init_default_precision(flag_t *flag)
{
    flag->_precision.float_precision = 6;
    flag->_precision.precision_in_prev_arg = false;
}

static void init_default_length(flag_t *flag)
{
    flag->length.length_type = 0;
}

void init_default_flag(flag_t *flag)
{
    init_default_flags(flag);
    init_default_width(flag);
    init_default_precision(flag);
    init_default_length(flag);
    return;
}
