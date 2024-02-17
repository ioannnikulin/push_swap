CC = cc
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
PREFIX =
INCLUDES = -I. -Ilibft

FOLDER = .

FILENAMES = aux.c op_swap.c op_push.c op_rot.c op_rrot.c printers.c sort_turk_price.c# sorter.c
SRCS = $(addprefix $(FOLDER)/, $(FILENAMES))
OBJS = $(SRCS:.c=.o)
DEPENDS = $(SRCS:.c=.d)

ENDPOINT_FILENAMES = main.c sorter.c sort_manual.c
ENDPOINT_SRCS = $(addprefix $(FOLDER)/, $(ENDPOINT_FILENAMES))
ENDPOINT_OBJS = $(ENDPOINT_SRCS:.c=.o)
ENDPOINT_DEPENDS = $(SRCS:.c=.d)

all: $(NAME)

libft:
	$(PREFIX)cd libft && make re

$(NAME): libft endpoint

# TODO remove tests folder from libft, it has stdio::printf!

endpoint: $(OBJS) $(ENDPOINT_OBJS)
	$(PREFIX)$(CC) -o $(NAME) $(OBJS) $(ENDPOINT_OBJS) -Llibft -lft

-include $(DEPENDS) $(ENDPOINT_DEPENDS)

$(OBJS): %.o: %.c
	$(PREFIX)$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ $(INCLUDES) -g

$(ENDPOINT_OBJS): %.o: %.c
	$(PREFIX)$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ $(INCLUDES) -g -DMANUAL=1

clean:
	$(PREFIX)cd libft && make clean
	$(PREFIX)rm -f $(OBJS) $(ENDPOINT_OBJS) $(DEPENDS) $(ENDPOINT_DEPENDS)

fclean: clean
	$(PREFIX)cd libft && make fclean
	$(PREFIX)rm -f $(NAME)

re: fclean all

CALL = ./tests 0 3 4 6 7 5 2

run: #dont try this with manual sorting!
	$(PREFIX)echo $(CALL) | bash

debug:
	$(PREFIX)@gdbtui --args $(CALL:'=)

TESTF = .
TEST_NAMES = op_tests.c err_tests.c main_test.c sort_turk_price_tests.c
TEST_SRCS = $(addprefix $(TESTF)/, $(TEST_NAMES))
TEST_OBJS = $(TEST_SRCS:.c=.o)

$(TEST_OBJS): %.o: %.c
	$(PREFIX)$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) -g

tests: libft $(TEST_OBJS) $(OBJS) endpoint
	$(PREFIX)$(CC) -o $@ $(TEST_OBJS) $(OBJS) -Llibft -lft

testfclean: fclean
	$(PREFIX)rm -f $(TEST_OBJS) tests

.PHONY: all clean fclean re test libft
