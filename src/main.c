#include "functions.h"

int main(int ac, char **av)
{
	int i;
	int j;
	int tab[4][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
	};
	int *entry;

	if (check(ac, av) == 1)
		return (0);
	i = -1;

	//store entered clues in an array
	entry = get_numbers(av[1]);
	solve(tab, entry, 0);

	//display solution
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			ft_putnbr(tab[i][j]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
	return (0);
}