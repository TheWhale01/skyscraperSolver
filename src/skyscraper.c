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

	if (row_idx == game->size - 1) {
		for (size_t i = 0; i < game->size; i++) {
			if (game->board[i][column_idx] > max) {
				max = game->board[i][column_idx];
				count++;
			}
		}
		if (game->clues[column_idx] != count)
			return false;
	}
	return true;
}

static bool check_col_down(t_game *game, size_t column_idx, size_t row_idx) {
	size_t max = 0;
	size_t count = 0;

	if (row_idx == game->size - 1) {
		for (size_t i = game->size; i-- > 0;) {
			if (game->board[i][column_idx] > max) {
				max = game->board[i][column_idx];
				count++;
			}
		}
		if (game->clues[game->size + column_idx] != count)
			return false;
	}
	return true;
}

static bool check_row_left(t_game *game, size_t column_idx, size_t row_idx) {
	size_t max = 0;
	size_t count = 0;

	if (column_idx == game->size - 1) {
		for (size_t i = 0; i < game->size; i++) {
			if (game->board[row_idx][i] > max) {
				max = game->board[row_idx][i];
				count++;
			}
		}
		if (game->clues[(2 * game->size) + row_idx] != count)
			return false;
	}
	return true;
}

static bool check_row_right(t_game *game, size_t column_idx, size_t row_idx) {
	size_t max = 0;
	size_t count = 0;

	if (column_idx == game->size - 1) {
		for (size_t i = game->size; i-- > 0;) {
			if (game->board[row_idx][i] > max) {
				max = game->board[row_idx][i];
				count++;
			}
		}
		if (game->clues[(3 * game->size) + row_idx] != count)
			return false;
	}
	return true;
}

static bool check_case(t_game *game, size_t column_idx, size_t row_idx) {
	return check_col_up(game, column_idx, row_idx) &&
		check_col_down(game, column_idx, row_idx) &&
		check_row_left(game, column_idx, row_idx) &&
		check_row_right(game, column_idx, row_idx);
}

bool solve(t_game *game, size_t pos) {
	size_t column_idx;
	size_t row_idx;

	if (pos == game->max_pos)
		return true;
	column_idx = pos % game->size;
	row_idx = pos / game->size;
	for (size_t tower_size = 1; tower_size <= game->size; tower_size++) {
		if (check_double(game, column_idx, row_idx, tower_size)) {
			game->board[row_idx][column_idx] = tower_size;
			if (check_case(game, column_idx, row_idx) && solve(game, pos + 1))
				return true;
			game->board[row_idx][column_idx] = 0;
		}
	}
	return false;
}
