#include "skyscraper.h"
#include <stdio.h>
#include <stdlib.h>

void display_solution(t_game *game)
{
	for (size_t i = 0; i < game->size; i++) {
		for (size_t j = 0; j < game->size; j++)
			printf("%zu ", game->board[i][j]);
		printf("\n");
	}
}

void destroy_game(t_game *game)
{
	if (!game)
		return;
	free(game->clues);
	game->clues = NULL;
	if (game->board) {
		for (size_t i = 0; i < game->size; i++) {
			free(game->board[i]);
			game->board[i] = NULL;
		}
		free(game->board);
		game->board = NULL;
	}
	free(game);
}
