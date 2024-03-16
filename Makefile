CC = cc
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
PREFIX =
INCLUDES = -I. -Ilibft

FOLDER = .

FILENAMES = aux.c op_swap.c op_push.c op_rot.c op_rrot.c printers.c sort_turk_price.c sort_aux.c sort_turk_price_rotation_strategies.c sort_turk_price_rotation_ops.c sort_mark_lis.c sort_turk_debut.c sort_turk_procs.c sort_mark_lis_proc.c
SRCS = $(addprefix $(FOLDER)/, $(FILENAMES))
OBJS = $(SRCS:.c=.o)

ENDPOINT_FILENAMES = main.c sorter.c sort_turk_main.c
ENDPOINT_SRCS = $(addprefix $(FOLDER)/, $(ENDPOINT_FILENAMES))
ENDPOINT_OBJS = $(ENDPOINT_SRCS:.c=.o)

all: $(NAME)

libft:
	$(PREFIX)cd libft && make re

$(NAME): libft endpoint

endpoint: $(OBJS) $(ENDPOINT_OBJS)
	$(PREFIX)$(CC) -o $(NAME) $(OBJS) $(ENDPOINT_OBJS) -Llibft -lft

$(OBJS): %.o: %.c
	$(PREFIX)$(CC) $(CFLAGS) -c $< -o $@ -g

$(ENDPOINT_OBJS): %.o: %.c
	$(PREFIX)$(CC) $(CFLAGS) -c $< -o $@ -g -DTURK=1

clean:
	$(PREFIX)cd libft && make clean
	$(PREFIX)rm -f $(OBJS) $(ENDPOINT_OBJS)

fclean: clean
	$(PREFIX)cd libft && make fclean
	$(PREFIX)rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re endpoint libft
