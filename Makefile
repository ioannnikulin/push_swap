CC = cc
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror

FOLDER = .
FILENAMES = main.c
SRCS = $(addprefix $(FOLDER)/, $(FILENAMES))
OBJS = $(SRCS:.c=.o)
INCLUDES = -I. -Ilibft

all: $(NAME)

libft:
	cd libft && make re

$(NAME): libft endpoint

endpoint: $(OBJS) # TODO: remove this before submission, it causes relinking
	$(CC) -o $(NAME) $(OBJS) -Llibft -lft

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) -g

clean:
	cd libft && make clean
	rm -f $(OBJS)

fclean: clean
	cd libft && make fclean
	rm -f $(NAME)

re: fclean all

CALL = ./$(NAME) 12 "34 5555 -07" 0 9

run:
	echo $(CALL) | bash

debug: 
	gdbtui --args $(CALL:'=)

TESTF = .
TEST_NAMES = tests.c
TEST_SRCS = $(addprefix $(TESTF)/, $(TEST_NAMES))
TEST_OBJS = $(TEST_SRCS:.c=.o)

$(TEST_OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) -g

errors: $(NAME) $(TEST_OBJS)
	$(CC) -o $@ $(TEST_OBJS)
	./$@

.PHONY: all clean fclean re test libft
