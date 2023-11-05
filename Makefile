##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Used for compiling unit_tests and lib
##

PRINTF_SRC	=	tests/test_my_printf.c

DBLSTR_SRC	=	tests/test_dblstr.c

NAME	=	libmy.a

all: $(NAME) clean

$(NAME):
	make -C ./lib/my/

re:
	make -C ./lib/my/ re
	make clean

clean:
	make -C ./lib/my/ clean
	find . -type f \( -name "*.gcno" -o -name "*.gcda" \) -delete

fclean:
	make -C ./lib/my/ fclean
	find . -type f \( -name "unit_tests" \) -delete

unit_test_printf: re
	gcc -o unit_test_printf $(PRINTF_SRC) -lcriterion -L./ -lmy

unit_test_dblstr: re
	gcc -o unit_test_dblstr $(DBLSTR_SRC) -lcriterion -L./ -lmy

tests_run: unit_test_printf
	./unit_test_printf --verbose

tests_run2: unit_test_dblstr
	./unit_test_dblstr --verbose
