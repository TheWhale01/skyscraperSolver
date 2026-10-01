#pragma once

#include <stdbool.h>
#include <stddef.h>

typedef struct {
	size_t **board;
	size_t *input;
	size_t size;
	size_t squared_size;
} t_game;

t_game *init(int ac, char **av);

bool solve(t_game *game, size_t pos);
