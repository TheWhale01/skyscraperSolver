#include "skyscraper.h"
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static inline size_t get_perfect_square(size_t nb) {
	size_t squared = sqrt(nb);

	return squared * squared == nb ? squared : 0;
}

bool init_input(t_game *game, char *input) {
	size_t idx = 0;
	size_t len = strlen(input);
	game->size = 0;
	game->squared_size = 0;

	for (size_t i = 0; i < len; i++)
		if (isdigit(input[i]))
			game->size++;
	game->squared_size = get_perfect_square(game->size);
	if (!game->squared_size)
		return false;
	if (!(game->input = malloc(sizeof(size_t) * game->size)))
		return false;
	memset(game->input, 0, sizeof(size_t) * game->size);
	for (size_t i = 0; i < len; i++) {
		if (isdigit(input[i])) {
			game->input[idx] = atoi(&input[i]);
			idx++;
		}
	}
	if (!(game->board = malloc(sizeof(int*) * game->squared_size))) {
		free(game->input);
		return false;
	}
	for (size_t i = 0; i < game->squared_size; i++) {
		if (!(game->board[i] = malloc(sizeof(size_t) * game->squared_size))) {
			for (size_t j = 0; j < i; j++)
				free(game->board[j]);
			return false;
		}
		memset(game->board[i], 0, sizeof(size_t) * game->squared_size);
	}
	return true;
}


t_game *init(int ac, char **av)
{
	t_game *game;

	if (ac != 2) {
		fprintf(stderr, "Error: %s <board>\n", av[0]);
		return NULL;
	}
	if (!(game = malloc(sizeof(t_game) * 1)))
		return NULL;
	if (!init_input(game, av[1])) {
		free(game);
		return NULL;
	}
	return game;
}
