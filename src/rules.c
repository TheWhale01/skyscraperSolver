int check_double(int tab[4][4], int pos, int num)
{
	int i;

	i = -1;
	while (++i < pos / 4)
		if (tab[i][pos % 4] == num)
			return (1);
	i = -1;
	while (++i < pos % 4)
		if (tab[pos / 4][i] == num)
			return (1);
	return (0);
}

int check_col_up(int tab[4][4], int pos, int entry[16])
{
	int i;
	int max;
	int count;

	i = -1;
	count = 0;
	if (pos / 4 == 3)
	{
		while (++i < 4)
		{
			if (tab[i][pos % 4] > max)
			{
				max = tab[i][pos % 4];
				count++;
			}
		}
		if (entry[pos % 4] != count)
			return (1);
	}
	return (0);
}

int check_row_right(int tab[4][4], int pos, int entry[16])
{
	int max;
	int row;
	int col;

	max = 1;
	col = 4;
	row = pos / 4;
	if (pos % 4 == 3)
	{
		while (--col > 0)
			if (tab[row][col] < tab[row - 1][col])
				max++;
		if (max != entry[12 + pos % 4])
			return (1);
	}
	return (0);
}

int check_col_down(int tab[4][4], int pos, int entry[16])
{
	int max;
	int row;
	int col;

	row = 4;
	max = 1;
	col = pos % 4;
	if (pos / 4 == 3)
	{
		while (--row > 0)
			if (tab[row][col] < tab[row - 1][col])
				max++;
		if (max != entry[4 + pos % 4])
			return (1);
	}
	return (0);
}

int check_row_left(int tab[4][4], int pos, int entry[16])
{
	int max;
	int row;
	int col;

	max = 1;
	col = -1;
	row = pos / 4;
	if (pos % 4 == 3)
	{
		while (++col < 3)
			if (tab[row][col] < tab[row + 1][col])
				max++;
		if (max != entry[8 + pos])
			return (1);
	}
	return (0);
}

int check_case(int tab[4][4], int pos, int entry[16], int num)
{
	if (check_double(tab, pos, num) == 1)
		return (1);
	if (check_row_left(tab, pos, entry) == 1)
		return (1);
	else if (check_row_right(tab, pos, entry) == 1)
		return (1);
	else if (check_col_down(tab, pos, entry) == 1)
		return (1);
	else if (check_col_up(tab, pos, entry) == 1)
		return (1);
	return (0);
}