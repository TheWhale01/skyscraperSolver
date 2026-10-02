#include "skyscraper.h"
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static size_t count_clues(const char *input) {
	size_t count = 0;
	size_t i = 0;

	while (input[i]) {
		if (isdigit((unsigned char)input[i])) {
			count++;
			while (isdigit((unsigned char)input[i + 1]))
				i++;
		}
		i++;
	}
	return count;
}

static bool parse_clues(t_game *game, const char *input) {
    size_t idx = 0;
    size_t i = 0;

	while (input[i]) {
	    if (isdigit((unsigned char)input[i])) {
			game->clues[idx] = strtoull(&input[i], NULL, 10);
			if (game->clues[idx] == 0 || game->clues[idx] > game->size) {
    			fprintf(stderr, "Error: clues must be between 1 and %zu.\n", game->size);
    			return false;
			}
			while (isdigit((unsigned char)input[i + 1]))
			    i++;
			idx++;
		}
		i++;
	}
	return true;
}

static bool init_input(t_game *game, const char *input) {
	game->clue_count = count_clues(input);
	if (game->clue_count == 0 || game->clue_count % 4 != 0) {
		fprintf(stderr, "Error: expected four clues per board dimension.\n");
		return false;
	}
	game->size = game->clue_count / 4;
	if (!(game->clues = calloc(game->clue_count, sizeof(*game->clues)))) {
		fprintf(stderr, "Error: could not allocate memory.\n");
		return false;
	}
	game->max_pos = game->size * game->size;
	if (!parse_clues(game, input)) {
		free(game->clues);
		game->clues = NULL;
		return false;
	}
	if (!(game->board = calloc(game->size, sizeof(*game->board)))) {
		fprintf(stderr, "Error: could not allocate memory.\n");
		free(game->clues);
		game->clues = NULL;
		return false;
	}
	for (size_t i = 0; i < game->size; i++) {
		game->board[i] = calloc(game->size, sizeof(*game->board[i]));
		if (!game->board[i]) {
			fprintf(stderr, "Error: could not allocate memory.\n");
			for (size_t j = 0; j < i; j++) {
    			free(game->board[j]);
                game->board[j] = NULL;
			}
			free(game->board);
			game->board = NULL;
			free(game->clues);
			game->clues = NULL;
			return false;
		}
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
	if (!(game = calloc(1, sizeof(*game)))) {
		fprintf(stderr, "Error: could not allocate memory.\n");
		return NULL;
	}
	if (!init_input(game, av[1])) {
		free(game);
		return NULL;
	}
	return game;
}
