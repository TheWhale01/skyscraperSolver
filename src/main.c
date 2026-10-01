#include "skyscraper.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void display_solution(t_game *game) {
	for (size_t i = 0; i < game->squared_size; i++) {
		for (size_t j = 0; j < game->squared_size; j++) {
			printf("%ld ", game->board[i][j]);
		}
		printf("\n");
	}
}

int main(int ac, char **av)
{
    bool result;
	t_game *game = NULL;

	game = init(ac, av);
	if (!game)
		return EXIT_FAILURE;
	result = solve(game, 0);
	display_solution(game);
	if (!result)
	    fprintf(stderr, "Did not find any solutions\n");
	free(game->input);
	for (size_t i = 0; i < game->squared_size; i++)
		free(game->board[i]);
	free(game->board);
	free(game);
	return EXIT_SUCCESS;
}
