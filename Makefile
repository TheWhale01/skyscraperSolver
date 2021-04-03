CC=gcc
CFILES=$(shell find src -name "*.c" ! -name "test.c")
HEADERS_DIR=includes/
CFLAGS=-Wall -Wextra -Werror -I $(HEADERS_DIR)
NAME=skyscraper
OBJS=${CFILES:.c=.o}

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

debug:
	$(CC) $(CFLAGS) -g src/test.c

clean:
	rm -f src/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all