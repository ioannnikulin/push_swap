CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
BONUS_NAME = checker
PREFIX =
INCLUDES = -I. -Ilibft

FOLDER = .

FILENAMES = aux.c op_swap.c op_push.c op_rot.c op_rrot.c printers.c sort_turk_price.c sort_aux.c sort_turk_price_rotation_strategies.c sort_turk_price_rotation_ops.c sort_mark_lis.c sort_turk_debut.c sort_turk_procs.c sort_mark_lis_proc.c sorter.c sort_turk_main.c 
SRCS = $(addprefix $(FOLDER)/, $(FILENAMES))
OBJS = $(SRCS:.c=.o)
OOBJS = $(SRCS:.c=.oo)
DEPENDS = $(SRCS:.c=.d)

ENDPOINT_FILENAMES = main.c checker.c
ENDPOINT_SRCS = $(addprefix $(FOLDER)/, $(ENDPOINT_FILENAMES))
ENDPOINT_OBJS = $(ENDPOINT_SRCS:.c=.o)
ENDPOINT_OOBJS = $(ENDPOINT_SRCS:.c=.oo)
ENDPOINT_DEPENDS = $(ENDPOINT_SRCS:.c=.d)

-include $(DEPENDS) $(ENDPOINT_DEPENDS)

all: $(NAME)

libft:
	$(PREFIX)cd libft && make re

$(NAME): BONUSFLAG = -DCHECKER=0
$(NAME): EXEC_NAME = $(NAME)
$(NAME): libft endpoint

endpoint: $(OBJS) $(ENDPOINT_OBJS)
	$(PREFIX)$(CC) -o $(EXEC_NAME) $(OBJS) $(ENDPOINT_OBJS) -Llibft -lft

$(OBJS): %.o: %.c
	$(PREFIX)$(CC) $(CFLAGS) $(BONUSFLAG) -MMD -MP -c $< -o $@ $(INCLUDES) -g

$(ENDPOINT_OBJS): %.o: %.c
	$(PREFIX)$(CC) $(CFLAGS) $(BONUSFLAG) -MMD -MP -c $< -o $@ $(INCLUDES) -g

bonus: BONUSFLAG = -DCHECKER=1
bonus: EXEC_NAME = $(BONUS_NAME)
bonus: libft oendpoint

oendpoint: $(OOBJS) $(ENDPOINT_OOBJS) 
	$(PREFIX)$(CC) -o $(EXEC_NAME) $(OOBJS) $(ENDPOINT_OOBJS) -Llibft -lft

$(OOBJS): %.oo: %.c
	$(PREFIX)$(CC) $(CFLAGS) $(BONUSFLAG) -MMD -MP -c $< -o $@ $(INCLUDES) -g

$(ENDPOINT_OOBJS): %.oo: %.c
	$(PREFIX)$(CC) $(CFLAGS) $(BONUSFLAG) -MMD -MP -c $< -o $@ $(INCLUDES) -g

clean:
	$(PREFIX)cd libft && make clean
	$(PREFIX)rm -f $(OBJS) $(OOBJS) $(ENDPOINT_OBJS) $(ENDPOINT_OOBJS) $(DEPENDS) $(ENDPOINT_DEPENDS)

fclean: clean
	$(PREFIX)cd libft && make fclean
	$(PREFIX)rm -f push_swap checker
re: fclean all

.PHONY: all clean fclean re libft bonus endpoint oendpoint
