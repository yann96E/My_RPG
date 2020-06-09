##
## EPITECH PROJECT, 2019
## makefile
## File description:
## make files
##

SRC	:=	my_putchar.c		\
		my_strlen.c		\
		my_strcat.c		\
		my_putstr.c		\
		my_revstr.c		\
		my_put_nbr.c		\
		my_isneg.c		\
		strcmp.c		\
		my_getnbr.c		\
		my_swap.c		\
		my_sort_int_array.c	\
		my_strstr.c		\
		my_strcpy.c		\
		my_compute_power_rec.c		\
		my_compute_square_root.c	\
		my_strncpy.c		\
		my_strncat.c		\
		my_strcapitalize.c	\
		my_strlowcase.c		\
		my_strupcase.c		\
		my_strncmp.c		\
		my_find_prime_sup.c	\
		my_is_prime.c		\
		my_tablen.c		\
		my_str_isalpha.c	\
		my_strupcase.c		\
		my_strlowcase.c		\
		my_strcapitalize.c	\
		my_str_isalpha.c	\
		my_str_isnum.c		\
		my_str_islower.c	\
		my_str_isupper.c	\
		my_str_isprintable.c	\
		my_strdup.c		\
		count_files.c		\
		my_atoa.c		\
		freeif.c		\
		parser.c	\
		read_file.c	\
		my_printf/my_printf_0.c \
		my_printf/my_printf_1.c \
		my_printf/display_printf_0.c    \
		my_printf/display_printf_1.c    \
		my_printf/my_printf.c	\

CFLAGS	+=	-Wall -Werror

OBJ	:=	$(SRC:.c=.o)

NAME	:=	$(addprefix lib, $(addsuffix .a, $(notdir $(CURDIR))))

COLOR	:=	\033[01;38;5;196m

WHITE	:=	\033[0;0m

CLEAR	:=	\033[2K

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@mv $(NAME) ../
	@echo -e "$(CLEAR)$(NAME) : $(COLOR)OK$(WHITE)"

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo -ne "$(CLEAR)Compiled $< : $(COLOR)OK$(WHITE)\r"

clean:
	@rm -f *.o

fclean: clean
	@rm -f ../$(NAME)

re:	fclean all
