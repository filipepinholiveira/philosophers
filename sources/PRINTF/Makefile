#-*MAKEFILE*-

# target:   dependencies
#           action


CC			= cc
CFLAGS		= -Wall -Wextra -Werror

NAME		= libftprintf.a

MAND		= ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putnbr_u.c ft_putnbr_hexa.c ft_putnbr_hexa_ptr.c

OBJ_MAND	= $(MAND:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_MAND)
	ar rc $(NAME) $(OBJ_MAND)

clean:
	rm -rf $(OBJ_MAND)

fclean: clean
	rm -rf $(NAME)

re: fclean all

