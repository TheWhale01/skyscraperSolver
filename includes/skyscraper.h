#pragma once

#include <stdbool.h>
#include <stddef.h>

typedef struct {
	size_t **board;
	size_t *clues;
	size_t size;
	size_t clue_count;
	size_t max_pos;
} t_game;

t_game *init(int ac, char **av);

bool solve(t_game *game, size_t pos);

void display_solution(t_game *game);
void destroy_game(t_game *game);
