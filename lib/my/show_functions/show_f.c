/*
** EPITECH PROJECT, 2023
** show_f.c
** File description:
** placeholder
*/
#include "../my.h"
#include <math.h>
#include <stdlib.h>

static int get_precision(va_list args, flag_t *flag)
{
    if (flag->_precision.precision_in_prev_arg) {
        return (va_arg(args, int));
    } else {
        return (flag->_precision.float_precision);
    }
}

int show_f(va_list args, flag_t *flag)
{
    int char_put = 0;
    int precision = get_precision(args, flag);
    double nb = va_arg(args, double);
    char *ptr = my_dblstr(nb, precision);

    switch (fpclassify(nb)) {
    case FP_INFINITE:
        if (nb < 0) {
            return (my_putstr("-inf"));
        }
        return (my_putstr("inf"));
    case FP_NAN:
        if (nb < 0) {
            return (my_putstr("-nan"));
        }
        return (my_putstr("nan"));
    }
    char_put = my_putstr(ptr);
    free(ptr);
    return (char_put);
}
