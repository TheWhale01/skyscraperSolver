#include "functions.h"
#include <stdlib.h>

int check(int ac, char **av)
{
	if (ac != 2)
		return (1);
	if (ft_strlen(av[1]) != 31)
		return (1);
	return (0);
}

int *get_numbers(char *str)
{
	int i;
	int j;
	int *tab;

	if (!(tab = malloc(sizeof(int) * 16)))
		return (0);
	i = -1;
	j = 0;
	while (str[++i] != '\0')
		if (str[i] >= '0' && str[i] <= '9')
			tab[j++] = ft_atoi(str + i);
	return (tab);
}

int solve(int tab[4][4], int entry[16], int pos)
{
	int size;

	if (pos == 16)
		return (1);
	size = 0;
	while (++size <= 4)
	{
		if (check_case(tab, pos, entry, size) == 0)
		{
			tab[pos / 4][pos % 4] = size;
			if (solve(tab, entry, pos + 1) == 1)
				return (1);
		}
	}
	tab[pos / 4][pos % 4] = 0;
	return (1);
}