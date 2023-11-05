/*
** EPITECH PROJECT, 2023
** show_e.c
** File description:
** placeholder
*/
#include <stdlib.h>
#include <math.h>
#include "../my.h"

static int get_precision(va_list args, flag_t *flag)
{
    if (flag->_precision.precision_in_prev_arg) {
        return (va_arg(args, int));
    } else {
        return (flag->_precision.float_precision);
    }
}

int show_e_upcase(va_list args, flag_t *flag)
{
    int char_put = 0;
    int precision = get_precision(args, flag);
    double nb = va_arg(args, double);
    char *ptr = my_dblsci(nb, precision);

    switch (fpclassify(nb)) {
    case FP_INFINITE:
        return (my_putstr("INF"));
    case FP_NAN:
        return (my_putstr("NAN"));
    }
    my_strupcase(ptr);
    char_put = my_putstr(ptr);
    free(ptr);
    return (char_put);
}

#include <math.h>
