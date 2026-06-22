NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft

SRCS = main.c \
	   assign_indice.c bench_cnt_a.c bench_cnt_b.c bench.c \
	   complex_sort.c ft_check_args.c \
	   ft_disorder.c ft_parse_flags.c main_utils.c medium_sort.c \
	   printlist.c push.c rev_rotate.c rotate.c simple_sort.c swap.c t_list.c utils.c 

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT     = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re