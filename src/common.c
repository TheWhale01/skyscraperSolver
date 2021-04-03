#include <unistd.h>

// Prints a single char
void ft_putchar(char c)
{
	write(1, &c, 1);
}

//prints a list of characters
void ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

//gives the length of a list of character (strlen)
int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

//similar to (atoi() in stdlib.h)
int ft_atoi(char *str)
{
	int i;
	int nbr;
	int nbrminus;

	i = 0;
	nbr = 0;
	nbrminus = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			nbrminus++;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = nbr * 10 + (str[i++] - '0');
	if (nbrminus % 2 == 1)
		return (nbr * -1);
	return (nbr);
}

//prints a number in the standart output
void ft_putnbr(int nb)
{
	unsigned int nbr;

	if (nb < 0)
	{
		ft_putchar('-');
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr / 10 != 0)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + 48);
}
