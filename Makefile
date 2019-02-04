
NAME = ft_ls

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/

INCLUDES = ./include/

SRCS =	./src/main.c\
		./src/set_env.c\
		./src/arg_way.c\
		./src/alpha_sort.c\
		./src/sort.c\
		./src/utils.c\
		./src/read_in.c\
		./src/global_padding.c\
		./src/del.c\
		./src/manag_tri.c\
		./src/print_list.c\
		./src/recursion.c\
		./src/time_sort.c\
		./src/tools.c\
		./src/error.c\
		./src/set_max.c\
		./src/manag_way.c\
		./src/padding_all/padding_gid_uid.c\
		./src/padding_all/padding_link.c\
		./src/padding_all/padding_right.c\
		./src/padding_all/padding_size.c\
		./src/padding_all/padding_time.c\

LIB = $(LIBFT)/libft.a

BIN = $(SRCS:.c=.o)

SRC = src

OBJS_PATH = objs

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(BIN) $(INCLUDES) $(LIB)
	$(CC) $(FLAGS) $(BIN) $(LIB) -I $(INCLUDES) -o $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -I $(INCLUDES) -c $< -o $@

$(LIB):
	make -C $(LIBFT)

debug: $(BIN) $(INCLUDES) $(LIB)
	$(CC) $(FLAGS) -fsanitize=address $(BIN) $(LIB) -I $(INCLUDES) -o $(NAME)

clean:
	rm -f $(BIN)
	make clean -C $(LIBFT)

fclean:clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all
