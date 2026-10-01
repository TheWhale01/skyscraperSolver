#include "skyscraper.h"

static bool check_double(t_game *game, size_t column_idx, size_t row_idx, size_t tower_size) {
	for (size_t i = 0; i < row_idx; i++)
		if (game->board[i][column_idx] == tower_size)
			return false;
	for (size_t i = 0; i < column_idx; i++)
		if (game->board[row_idx][i] == tower_size)
			return false;
	return true;
}

static bool check_col_up(t_game *game, size_t column_idx, size_t row_idx) {
	size_t max = 0;
	size_t count = 0;

	if (row_idx == game->squared_size - 1) {
		for (size_t i = 0; i < game->squared_size; i++) {
			if (game->board[i][column_idx] > max) {
				max = game->board[i][column_idx];
				count++;
			}
		}
		if (game->input[column_idx] != count)
			return false;
	}
	return true;
}

static bool check_col_down(t_game *game, size_t column_idx, size_t row_idx) {
	size_t max = 0;
	size_t count = 0;

	if (row_idx == game->squared_size - 1) {
		for (int i = game->squared_size - 1; i >= 0; i--) {
			if (game->board[i][column_idx] > max) {
				max = game->board[i][column_idx];
				count++;
			}
		}
		if (game->input[game->squared_size + column_idx] != count)
			return false;
	}
	return true;
}

static bool check_row_left(t_game *game, size_t column_idx, size_t row_idx) {
	size_t max = 0;
	size_t count = 0;

	if (column_idx == game->squared_size - 1) {
		for (size_t i = 0; i < game->squared_size; i++) {
			if (game->board[row_idx][i] > max) {
				max = game->board[row_idx][i];
				count++;
			}
		}
		if (game->input[(2 * game->squared_size) + row_idx] != count)
			return false;
	}
	return true;
}

static bool check_row_right(t_game *game, size_t column_idx, size_t row_idx) {
	size_t max = 0;
	size_t count = 0;

	if (column_idx == game->squared_size - 1) {
		for (int i = game->squared_size - 1; i >= 0; i--) {
			if (game->board[row_idx][i] > max) {
				max = game->board[row_idx][i];
				count++;
			}
		}
		if (game->input[(3 * game->squared_size) + row_idx] != count)
			return false;
	}
	return true;
}

static bool check_case(t_game *game, size_t column_idx, size_t row_idx) {
	if (!check_col_up(game, column_idx, row_idx) ||
		!check_col_down(game, column_idx, row_idx) ||
		!check_row_left(game, column_idx, row_idx) ||
		!check_row_right(game, column_idx, row_idx))
		return false;
	return true;
}

bool solve(t_game *game, size_t pos) {
	size_t column_idx = pos % game->squared_size;
	size_t row_idx = pos / game->squared_size;

	if (pos == game->size)
		return true;
	for (size_t tower_size = 1; tower_size <= game->squared_size; tower_size++) {
		if (check_double(game, column_idx, row_idx, tower_size))
		{
			game->board[row_idx][column_idx] = tower_size;
			if (check_case(game, column_idx, row_idx))
			{
				if (solve(game, pos + 1))
					return true;
			}
			else
				game->board[row_idx][column_idx] = 0;
		}

	}
	return false;
}
