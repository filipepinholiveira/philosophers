CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread

MAND = philo.c \
parse.c \
ft_atoi.c \
init_data.c \
eat.c \
time.c \
routine.c \
setter.c \
get_utils.c \
checker.c \
take_fork_utils.c \
take_fork_utils_2.c \
utils.c \
sleep.c \
think.c \

NAME = philo
OBJ_MAND = $(MAND:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_MAND)
	cc $(OBJ_MAND) $(CFLAGS) -g -pthread -o $(NAME)

clean:
	rm -f $(OBJ_MAND)

fclean: clean
	rm -f $(NAME)

re: fclean all