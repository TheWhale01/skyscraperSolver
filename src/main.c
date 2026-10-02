#include "skyscraper.h"
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av) {
	t_game *game = init(ac, av);
	int status = EXIT_SUCCESS;

	if (!game)
		return EXIT_FAILURE;
	if (solve(game, 0))
		display_solution(game);
	else {
		fprintf(stderr, "Did not find any solutions\n");
		status = EXIT_FAILURE;
	}
	destroy_game(game);
	return status;
}
