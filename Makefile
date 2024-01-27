CC = cc
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror

FOLDER = .
FILENAMES = aux.c op_swap.c op_push.c op_rot.c op_rrot.c printers.c sorter.c
SRCS = $(addprefix $(FOLDER)/, $(FILENAMES))
OBJS = $(SRCS:.c=.o)
INCLUDES = -I. -Ilibft

MAINFOLDER = .
MAINFILENAME = main.c
MAINSRC = $(addprefix $(MAINFOLDER)/, $(MAINFILENAME))
MAINOBJ = $(MAINSRC:.c=.o)
PREFIX = @

all: $(NAME)

libft:
	$(PREFIX)cd libft && make re

$(NAME): libft endpoint

# TODO remove tests folder from libft, it has stdio::printf!

endpoint: $(OBJS) $(MAINOBJ)# TODO: remake all this before submission, it causes relinking
	$(PREFIX)$(CC) -o $(NAME) $(OBJS) $(MAINOBJ) -Llibft -lft

$(OBJS): %.o: %.c
	$(PREFIX)$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) -g

$(MAINOBJ): %.o: %.c
	$(PREFIX)$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) -g

clean:
	$(PREFIX)cd libft && make clean
	$(PREFIX)rm -f $(OBJS) $(MAINOBJ)

fclean: clean
	$(PREFIX)cd libft && make fclean
	$(PREFIX)rm -f $(NAME)

re: fclean all

CALL = ./$(NAME) 5 2 7 1 6 3 9 4 8

run:
	$(PREFIX)echo $(CALL) | bash

debug: 
	$(PREFIX)@gdbtui --args $(CALL:'=)

TESTF = .
TEST_NAMES = op_tests.c err_tests.c main_test.c
TEST_SRCS = $(addprefix $(TESTF)/, $(TEST_NAMES))
TEST_OBJS = $(TEST_SRCS:.c=.o)

$(TEST_OBJS): %.o: %.c
	$(PREFIX)$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) -g

tests: libft $(TEST_OBJS) $(OBJS) endpoint
	$(PREFIX)$(CC) -o $@ $(TEST_OBJS) $(OBJS) -Llibft -lft

testfclean: fclean
	$(PREFIX)rm -f $(TEST_OBJS) tests

.PHONY: all clean fclean re test libft
