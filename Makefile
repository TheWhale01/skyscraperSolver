CC=gcc

NAME=skyscraper
SRC_DIR=src/
OBJ_DIR=obj/
INCLUDES=includes/

CFILES=$(addprefix $(SRC_DIR), main.c parsing.c skyscraper.c utils.c)
OBJS=$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(CFILES))
CFLAGS=-Wall -Wextra -Werror -I $(INCLUDES) -O3 -march=native -flto

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
