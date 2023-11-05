/*
** EPITECH PROJECT, 2023
** show_g.c
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

static int get_shortest(char *dbl, char *sci)
{
    int len_f = my_strlen(dbl);
    int len_e = my_strlen(sci);

    if (len_f < len_e) {
        free(sci);
        return (my_putstr(dbl));
    } else if (len_f > len_e) {
        free(dbl);
        return (my_putstr(sci));
    } else {
        free(sci);
        return (my_putstr(dbl));
    }
}

int show_g(va_list args, flag_t *flag)
{
    int char_put = 0;
    int precision = get_precision(args, flag);
    double nb = va_arg(args, double);

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
    char_put = get_shortest(my_dblstr(nb, precision),
                            my_dblsci(nb, precision));
    return (char_put);
}
