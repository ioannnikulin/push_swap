CC = cc
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror

FOLDER = .
FILENAMES = aux.c op_swap.c op_push.c op_rot.c op_rrot.c
SRCS = $(addprefix $(FOLDER)/, $(FILENAMES))
OBJS = $(SRCS:.c=.o)
INCLUDES = -I. -Ilibft

MAINFOLDER = .
MAINFILENAME = main.c
MAINSRC = $(addprefix $(MAINFOLDER)/, $(MAINFILENAME))
MAINOBJ = $(MAINSRC:.c=.o)

all: $(NAME)

libft:
	cd libft && make re

$(NAME): libft endpoint

endpoint: $(OBJS) $(MAINOBJ)# TODO: remake all this before submission, it causes relinking
	$(CC) -o $(NAME) $(OBJS) $(MAINOBJ) -Llibft -lft

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) -g

$(MAINOBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) -g

clean:
	cd libft && make clean
	rm -f $(OBJS) $(MAINOBJ)

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
TEST_NAMES = op_tests.c err_tests.c main_test.c
TEST_SRCS = $(addprefix $(TESTF)/, $(TEST_NAMES))
TEST_OBJS = $(TEST_SRCS:.c=.o)

$(TEST_OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) -g

tests: libft $(TEST_OBJS) $(OBJS) endpoint
	$(CC) -o $@ $(TEST_OBJS) $(OBJS) -Llibft -lft

testfclean: fclean
	rm -f $(TEST_OBJS) tests

.PHONY: all clean fclean re test libft
