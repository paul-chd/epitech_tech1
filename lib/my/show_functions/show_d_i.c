/*
** EPITECH PROJECT, 2023
** show_d_i.c
** File description:
** Prints given arg
*/
#include "../my.h"
#include <stdlib.h>
#include <stdio.h>

static char *pad(char *arg_buf, flag_t *flag)
{
    int len_arg_buf = my_strlen(arg_buf);
    char *buf = malloc(sizeof(char) * (flag->width.min_nb_of_putchar + 1));

    if (flag->flags.left_justify) {
        my_strcat(buf, arg_buf);
        for (int i = len_arg_buf; i < flag->width.min_nb_of_putchar; i++) {
            buf[i] = ' ';
        }
        buf[flag->width.min_nb_of_putchar] = '\0';
    } else {
        for (int i = 0; i < flag->width.min_nb_of_putchar - len_arg_buf; i++) {
            buf[i] = flag->flags.padding_char;
        }
        buf[flag->width.min_nb_of_putchar] = '\0';
        my_strcat(buf, arg_buf);
    }
    return (buf);
}

static void add_plus(int nb, char *arg_buf)
{
    if (nb >= 0) {
        my_strcat(arg_buf, "+");
    }
    return;
}

static void add_positive_space(int nb, char *arg_buf)
{
    if (nb >= 0) {
        my_strcat(arg_buf, " ");
    }
    return;
}

static void optional_additions(int nb, char *arg_buf, flag_t *flag)
{
    if (flag->flags.force_show_sign) {
        add_plus(nb, arg_buf);
    } else if (flag->flags.add_space) {
        add_space(nb, arg_buf);
    }
    return;
}

int show_d_i(va_list args, flag_t *flag)
{
    int char_put = 0;
    int nb = va_arg(args, int);
    char *nb_str = my_intstr(nb);
    char *arg_buf = malloc(sizeof(char) * (1 + count_int(nb) + 1));

    arg_buf[0] = '\0';
    optional_additions(nb, arg_buf, flag);
    my_strcat(arg_buf, nb_str);
    if (my_strlen(arg_buf) < flag->width.min_nb_of_putchar) {
        char_put += my_putstr(pad(arg_buf, flag));
    } else {
        char_put += my_putstr(arg_buf);
    }
    return (char_put);
}
