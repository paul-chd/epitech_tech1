##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Automatic compilation of the lib
##
SRC	=	my_printf.c				\
		my_strlen.c				\
		my_getnbr.c				\
		my_revstr.c				\
		my_strcpy.c				\
		my_strcat.c				\
		my_strupcase.c				\
		flag_t/change_flag.c			\
		flag_t/init_flag.c			\
		flag_t/left_justify.c			\
		flag_t/force_show_sign.c		\
		flag_t/add_space.c			\
		flag_t/alternative_display.c		\
		flag_t/padding_char.c			\
		my_put_functions/my_intbin.c		\
		my_put_functions/my_inthex.c		\
		my_put_functions/my_intoct.c		\
		my_put_functions/my_putchar.c		\
		my_put_functions/my_put_nbr.c		\
		my_put_functions/my_putfloat.c		\
		my_put_functions/my_putstr.c		\
		my_put_functions/my_put_uint.c		\
		my_put_functions/my_dblstr.c		\
		my_put_functions/my_dblsci.c		\
		my_put_functions/my_intstr.c		\
		show_functions/show_a.c			\
		show_functions/show_a_upcase.c		\
		show_functions/show_b.c			\
		show_functions/show_c.c			\
		show_functions/show_d_i.c		\
		show_functions/show_e.c			\
		show_functions/show_e_upcase.c		\
		show_functions/show_f.c			\
		show_functions/show_f_upcase.c		\
		show_functions/show_g.c			\
		show_functions/show_g_upcase.c		\
		show_functions/show_n.c			\
		show_functions/show_o.c			\
		show_functions/show_p.c			\
		show_functions/show_percent.c		\
		show_functions/show_s.c			\
		show_functions/show_u.c			\
		show_functions/show_x.c			\
		show_functions/show_x_upcase.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all: $(NAME) clean

clean:
	find . -type f \( -name "*.o" \) -delete

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../../

fclean: clean
	rm -f $(NAME)
	rm -f ../../$(NAME)

re:	fclean all clean
