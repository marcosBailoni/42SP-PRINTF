NAME = libftprintf.a
LIBFT_PATH = libft
SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)
CC = gcc
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_PATH)/libft.a
	ar rcs $(NAME) $(OBJS) $(LIBFT_PATH)/libft.a

$(LIBFT_PATH)/libft.a:
	make -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all
