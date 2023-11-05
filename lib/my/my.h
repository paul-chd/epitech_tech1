/*
** EPITECH PROJECT, 2023
** Header file for lib my
** File description:
** References all functions of the lib
*/
#ifndef MY_H
    #define MY_H
    #include <stdarg.h>
    #include <stdbool.h>

struct flags {
    bool left_justify;
    bool force_show_sign;
    bool add_space;
    bool alternative_display;
    char padding_char;
};
struct width {
    int min_nb_of_putchar;
    bool width_in_prev_arg;
};
struct _precision {
    int float_precision;
    bool precision_in_prev_arg;
};
struct length {
    int length_type;
};
struct specifier {
    int arg_type;
    void *arg;
};
typedef struct flag_modifiers {
    struct flags flags;
    struct width width;
    struct _precision _precision;
    struct length length;
    struct specifier specifier;
} flag_t;
int my_printf(const char *format, ...);
int my_strlen(char const *str);
int count_int(long long n);
int my_getnbr(char const *str);
char *my_inthex(unsigned long num);
char *my_intoct(unsigned long num);
char *my_intbin(unsigned long num);
char *my_revstr(char *str);
char *my_dblstr(double num, int length);
char *my_dblsci(double num, int length_comma);
char *my_intstr(long long num);
int my_putchar(char c);
int my_put_nbr(int nb);
int my_put_uint(unsigned int nb);
int my_putstr(char const *str);
void my_putfloat(double nb, int length);
char *my_strcpy(char *dest, const char *src, int start);
char *my_strcat(char *dest, char const *src);
char *my_strupcase(char *str);
int is_digit(char a);
int show_a(va_list args, flag_t *flag);
int show_a_upcase(va_list args, flag_t *flag);
int show_b(va_list args, flag_t *flag);
int show_c(va_list args, flag_t *flag);
int show_d_i(va_list args, flag_t *flag);
int show_e(va_list args, flag_t *flag);
int show_e_upcase(va_list args, flag_t *flag);
int show_f(va_list args, flag_t *flag);
int show_f_upcase(va_list args, flag_t *flag);
int show_g(va_list args, flag_t *flag);
int show_g_upcase(va_list args, flag_t *flag);
int show_n(va_list args, flag_t *flag);
int show_o(va_list args, flag_t *flag);
int show_p(va_list args, flag_t *flag);
int show_percent(va_list args, flag_t *flag);
int show_s(va_list args, flag_t *flag);
int show_u(va_list args, flag_t *flag);
int show_x(va_list args, flag_t *flag);
int show_x_upcase(va_list args, flag_t *flag);
void init_default_flag(flag_t *flag);
void left_justify(flag_t *flag);
void add_space(flag_t *flag);
void force_show_sign(flag_t *flag);
void alternative_display(flag_t *flag);
void padding_char(flag_t *flag);
void change_length(const char *str, flag_t *flag, int *start);
void change_precision(const char *str, flag_t *flag, int *start);
void change_flags(const char *str, flag_t *flag, int *start);
void change_width(const char *str, flag_t *flag, int *start);
bool is_specifier(const char c);

#endif
