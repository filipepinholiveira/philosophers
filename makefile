CFLAGS = -Wall -Wextra -Werror # -fsanitize=address

MAND = philosophers.c 


NAME = philosophers

OBJ_MAND = $(MAND:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_MAND)
	cc $(OBJ_MAND) $(CFLAGS) -pthread -o $(NAME)

clean:
	rm -f $(OBJ_MAND)

fclean:
	rm -f $(NAME)

re: fclean all