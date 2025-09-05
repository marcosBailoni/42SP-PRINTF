NAME = libftprintf.a
LIBFT_PATH = libft
LIBFT_A = $(LIBFT_PATH)/libft.a
SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)
CC = gcc
FLAGS = -Wall -Werror -Wextra

# Lista de todos os .o da libft (extraídos do .a)
LIBFT_OBJS := $(patsubst $(LIBFT_PATH)/%, %, $(shell ar -t $(LIBFT_A)))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	cp $(LIBFT_A) temp_libft.a
	ar x temp_libft.a
	ar rcs $(NAME) $(OBJS) *.o
	rm -f temp_libft.a *.o

$(LIBFT_A):
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
