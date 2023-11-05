/*
** EPITECH PROJECT, 2023
** unit test
** File description:
** test
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../lib/my/my.h"
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <float.h>

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

//____All normal cases
Test(printf_normal, no_flags, .init = redirect_all_std)
{
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}
/*Test(printf_normal, one_a_flag, .init = redirect_all_std)
{
    my_printf("hello %a", 14.5);
    cr_assert_stdout_eq_str("hello 0x1.dp+3");
}
Test(printf_normal, one_A_flag, .init = redirect_all_std)
{
    my_printf("hello %A", 14.5);
    cr_assert_stdout_eq_str("hello 0x1.DP+3");
}
*/
Test(printf_normal, one_c_flag, .init = redirect_all_std)
{
    my_printf("hello %c", 'b');
    cr_assert_stdout_eq_str("hello b");
}
Test(printf_normal, one_i_flag, .init = redirect_all_std)
{
    my_printf("hello world%i", 42);
    cr_assert_stdout_eq_str("hello world42");
}
Test(printf_normal, one_d_flag, .init = redirect_all_std)
{
    my_printf("hello world%d", 42);
    cr_assert_stdout_eq_str("hello world42");
}
Test(printf_normal, one_e_flag, .init = redirect_all_std)
{
    my_printf("hello world%e", 14.5);
    cr_assert_stdout_eq_str("hello world1.450000e+01");
}
Test(printf_normal, one_E_flag, .init = redirect_all_std)
{
    my_printf("hello world%E", 14.5);
    cr_assert_stdout_eq_str("hello world1.450000E+01");
}
Test(printf_normal, one_f_flag, .init = redirect_all_std)
{
    my_printf("hello %f", 4.2);
    cr_assert_stdout_eq_str("hello 4.200000");
}
Test(printf_normal, one_F_flag, .init = redirect_all_std)
{
    my_printf("hello %F", 4.2);
    cr_assert_stdout_eq_str("hello 4.200000");
}
Test(printf_normal, one_g_flag_f, .init = redirect_all_std)
{
    my_printf("hello %g", 14.5);
    cr_assert_stdout_eq_str("hello 14.5");
}
Test(printf_normal, one_g_flag_e, .init = redirect_all_std)
{
    my_printf("hello %g", 0.0000145);
    cr_assert_stdout_eq_str("hello 1.45e-05");
}
Test(printf_normal, one_G_flag_F, .init = redirect_all_std)
{
    my_printf("hello %G", 14.5);

    cr_assert_stdout_eq_str("hello 14.5");
}
Test(printf_normal, one_G_flag_E, .init = redirect_all_std)
{
    my_printf("hello %G", 0.0000145);
    cr_assert_stdout_eq_str("hello 1.45E-05");
}
Test(printf_normal, one_o_flag, .init = redirect_all_std)
{
    my_printf("hello %o", 42);
    cr_assert_stdout_eq_str("hello 52");
}
Test(printf_normal, one_p_flag, .init = redirect_all_std)
{
    int nb = 42;
    int *ptr = &nb;
    char *buffer = malloc(sizeof(char) * (10 + 14 + 1));
    sprintf(buffer, "int ptr = %p", ptr);
    my_printf("int ptr = %p", ptr);
    cr_assert_stdout_eq_str(buffer);
}
Test(printf_normal, one_percent_flag, .init = redirect_all_std)
{
    my_printf("hello %%");
    cr_assert_stdout_eq_str("hello %");
}
Test(printf_normal, one_s_flag, .init = redirect_all_std)
{
    my_printf("hello %s", "world");
    cr_assert_stdout_eq_str("hello world");
}
Test(printf_normal, one_u_flag, .init = redirect_all_std)
{
    my_printf("hello %u", 42);
    cr_assert_stdout_eq_str("hello 42");
}
Test(printf_normal, one_x_flag, .init = redirect_all_std)
{
    my_printf("hello %x", 42);
    cr_assert_stdout_eq_str("hello 2a");
}
Test(printf_normal, one_X_flag, .init = redirect_all_std)
{
    my_printf("hello %X", 42);
    cr_assert_stdout_eq_str("hello 2A");
}
//____All double cases
/*
Test(printf_double, double_a_flag, .init = redirect_all_std)
{
    my_printf("hello %a %a", 14.5, 14.5);
    cr_assert_stdout_eq_str("hello 0x1.dp+3 0x1.dp+3");
}
Test(printf_double, double_A_flag, .init = redirect_all_std)
{
    my_printf("hello %A %A", 14.5, 14.5);
    cr_assert_stdout_eq_str("hello 0x1.DP+3 0x1.DP+3");
}
*/
Test(printf_double, double_c_flag, .init = redirect_all_std)
{
    my_printf("hello %c %c", 'b', 'a');
    cr_assert_stdout_eq_str("hello b a");
}
Test(printf_double, double_i_flag, .init = redirect_all_std)
{
    my_printf("hello world%i %i", 42, 24);
    cr_assert_stdout_eq_str("hello world42 24");
}
Test(printf_double, double_d_flag, .init = redirect_all_std)
{
    my_printf("hello world%d %d", 42, 24);
    cr_assert_stdout_eq_str("hello world42 24");
}
Test(printf_double, double_e_flag, .init = redirect_all_std)
{
    my_printf("hello world%e %e", 14.5, 14.5);
    cr_assert_stdout_eq_str("hello world1.450000e+01 1.450000e+01");
}
Test(printf_double, double_E_flag, .init = redirect_all_std)
{
    my_printf("hello world%E %E", 14.5, 14.5);
    cr_assert_stdout_eq_str("hello world1.450000E+01 1.450000E+01");
}
Test(printf_double, double_f_flag, .init = redirect_all_std)
{
    my_printf("hello %f %f", 4.2, 4.2);
    cr_assert_stdout_eq_str("hello 4.200000 4.200000");
}
Test(printf_double, double_F_flag, .init = redirect_all_std)
{
    my_printf("hello %F %F", 4.2, 4.2);
    cr_assert_stdout_eq_str("hello 4.200000 4.200000");
}
Test(printf_double, double_g_flag_f, .init = redirect_all_std)
{
    my_printf("hello %g %g", 14.5, 14.5);
    cr_assert_stdout_eq_str("hello 14.5 14.5");
}
Test(printf_double, double_g_flag_e, .init = redirect_all_std)
{
    my_printf("hello %g %g", 0.0000145, 0.0000145);
    cr_assert_stdout_eq_str("hello 1.45e-05 1.45e-05");
}
Test(printf_double, double_G_flag_F, .init = redirect_all_std)
{
    my_printf("hello %G %G", 14.5, 14.5);
    cr_assert_stdout_eq_str("hello 14.5 14.5");
}
Test(printf_double, double_G_flag_E, .init = redirect_all_std)
{
    my_printf("hello %G %G", 0.0000145, 0.0000145);
    cr_assert_stdout_eq_str("hello 1.45E-05 1.45E-05");
}
Test(printf_double, double_o_flag, .init = redirect_all_std)
{
    my_printf("hello %o %o", 42, 42);
    cr_assert_stdout_eq_str("hello 52 52");
}
Test(printf_double, double_p_flag, .init = redirect_all_std)
{
    int nb = 42;
    int *ptr = &nb;
    int **ptrptr = &ptr;
    char *buffer = malloc(sizeof(char) * (10 + 14 + 1 + 14 + 1));
    sprintf(buffer, "int ptr = %p %p", ptr, ptrptr);
    my_printf("int ptr = %p %p", ptr, ptrptr);
    cr_assert_stdout_eq_str(buffer);
}
Test(printf_double, double_percent_flag, .init = redirect_all_std)
{
    my_printf("hello %% %%");
    cr_assert_stdout_eq_str("hello % %");
}
Test(printf_double, double_s_flag, .init = redirect_all_std)
{
    my_printf("hello %s %s", "world", "worl");
    cr_assert_stdout_eq_str("hello world worl");
}
Test(printf_double, double_u_flag, .init = redirect_all_std)
{
    my_printf("hello %u %u", 42, 24);
    cr_assert_stdout_eq_str("hello 42 24");
}
Test(printf_double, double_x_flag, .init = redirect_all_std)
{
    my_printf("hello %x %x", 42, 6);
    cr_assert_stdout_eq_str("hello 2a 6");
}
Test(printf_double, double_X_flag, .init = redirect_all_std)
{
    my_printf("hello %X %X", 42, 6);
    cr_assert_stdout_eq_str("hello 2A 6");
}
//____All extreme cases
Test(printf_extreme, int_max_i, .init = redirect_all_std)
{
    my_printf("hello world%i", INT_MAX);
    cr_assert_stdout_eq_str("hello world2147483647");
}
Test(printf_extreme, int_min_i, .init = redirect_all_std)
{
    my_printf("hello world%i", INT_MIN);
    cr_assert_stdout_eq_str("hello world-2147483648");
}
Test(printf_extreme, flt_max_f, .init = redirect_all_std)
{
    my_printf("hello world%f", FLT_MAX);
    cr_assert_stdout_eq_str("hello world340282346638528859811704183484516925440.000000");
}
Test(printf_extreme, flt_min_f, .init = redirect_all_std)
{
    my_printf("hello world%f", FLT_MIN);
    cr_assert_stdout_eq_str("hello world0.000000");
}
Test(printf_extreme, flt_max_F, .init = redirect_all_std)
{
    my_printf("hello world%F", FLT_MAX);
    cr_assert_stdout_eq_str("hello world340282346638528859811704183484516925440.000000");
}
Test(printf_extreme, flt_min_F, .init = redirect_all_std)
{
    my_printf("hello world%F", FLT_MIN);
    cr_assert_stdout_eq_str("hello world0.000000");
}
Test(printf_extreme, flt_max_e, .init = redirect_all_std)
{
    my_printf("hello world%e", FLT_MAX);
    cr_assert_stdout_eq_str("hello world3.402823e+38");
}
Test(printf_extreme, flt_max_E, .init = redirect_all_std)
{
    my_printf("hello world%E", FLT_MAX);
    cr_assert_stdout_eq_str("hello world3.402823E+38");
}
Test(printf_extreme, flt_min_e, .init = redirect_all_std)
{
    my_printf("hello world%e", FLT_MIN);
    cr_assert_stdout_eq_str("hello world1.175494e-38");
}
Test(printf_extreme, flt_min_E, .init = redirect_all_std)
{
    my_printf("hello world%E", FLT_MIN);
    cr_assert_stdout_eq_str("hello world1.175494E-38");
}
//____All edgy cases
Test(printf_edgy, multiple_flags, .init = redirect_all_std)
{
    my_printf("%%%sllo world%d%i", "he", 4, 2);
    cr_assert_stdout_eq_str("%hello world42");
}
Test(printf_edgy, multiple_flags2, .init = redirect_all_std)
{
    my_printf("hello %%%s%%d %i", "world", 42);
    cr_assert_stdout_eq_str("hello %world%d 42");
}
Test(printf_edgy, divide_by_zero, .init = redirect_all_std)
{
    my_printf("%f", 1.0/0.0);
    cr_assert_stdout_eq_str("inf");
}
Test(printf_edgy, divide_by_zero_upper, .init = redirect_all_std)
{
    my_printf("%F", 1.0/0.0);
    cr_assert_stdout_eq_str("INF");
}
Test(printf_edgy, zero_divided_by_zero, .init = redirect_all_std)
{
    my_printf("%f", 0.0/0.0);
    cr_assert_stdout_eq_str("nan");
}
Test(printf_edgy, zero_divided_by_zero_upper, .init = redirect_all_std)
{
    my_printf("%F", 0.0/0.0);
    cr_assert_stdout_eq_str("NAN");
}
Test(printf_edgy, char_to_int, .init = redirect_all_std)
{
    my_printf("hello %i", 't');
    cr_assert_stdout_eq_str("hello 116");
}

//All crash cases
Test(printf_crash, too_many_args, .init = redirect_all_std)
{
    my_printf("hello world", 42, 13);
    cr_assert_stdout_eq_str("hello world");
}

Test(printf_crash, invalid_identifier, .init = redirect_all_std)
{
    my_printf("hello world%5");
    cr_assert_stdout_eq_str("hello world%5");
}

//Using modifiers
Test(modifiers_testing, d_forced_sign_positive, .init = redirect_all_std)
{
    my_printf("test %+d test", 42);
    cr_assert_stdout_eq_str("test +42 test");
}
Test(modifiers_testing, d_forced_sign_negative, .init = redirect_all_std)
{
    my_printf("test %+d test", -42);
    cr_assert_stdout_eq_str("test -42 test");
}
Test(modifiers_testing, d_forced_sign_negative_width_four, .init = redirect_all_std)
{
    my_printf("test %+4d test", -42);
    cr_assert_stdout_eq_str("test  -42 test");
}
Test(modifiers_testing, d_forced_sign_negative_width_prev_arg, .init = redirect_all_std)
{
    my_printf("test %+*d test", 4, -42);
    cr_assert_stdout_eq_str("test  -42 test");
}
Test(modifiers_testing, d_forced_sign_positive_width_four, .init = redirect_all_std)
{
    my_printf("test %+-4d test", 42);
    cr_assert_stdout_eq_str("test +42  test");
}
Test(modifiers_testing, d_width_four_zero_padding, .init = redirect_all_std)
{
    my_printf("test %04d test", 42);
    cr_assert_stdout_eq_str("test 0042 test");
}
