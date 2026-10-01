CC=gcc

NAME=skyscraper
SRC_DIR=src/
OBJ_DIR=obj/
INCLUDES=includes/

CFILES=$(addprefix $(SRC_DIR), main.c parsing.c skyscraper.c)
OBJS=$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(CFILES))
CFLAGS=-Wall -Wextra -Werror -I $(INCLUDES) -g3

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ -lm

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lm

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
