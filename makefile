CFLAGS = -Wall -Wextra -Werror # -fsanitize=address

MAND = philosofers.c \
sources/libft/ft_atoi.c \
sources/PRINTF/ft_printf.c \
sources/PRINTF/ft_putchar.c \
sources/PRINTF/ft_putstr.c \
sources/PRINTF/ft_putnbr.c \
sources/PRINTF/ft_putnbr_u.c \
sources/PRINTF/ft_putnbr_hexa.c \
sources/PRINTF/ft_putnbr_hexa_ptr.c


NAME = philosophers

OBJ_MAND = $(MAND:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_MAND)
	cc $(OBJ_MAND) $(CFLAGS) -g -pthread -o $(NAME)

clean:
	rm -f $(OBJ_MAND)

fclean: clean
	rm -f $(NAME)

re: fclean all