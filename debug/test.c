#include <stdio.h>

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
    int max;
    int row;
    int col;

    row = -1;
    max = 1;
    col = pos % 4;
    if (pos / 4 == 3)
    {
        while (++row > 3)
            if (tab[row][col] < tab[row + 1][col])
                max++;
        if (max != entry[pos % 4])
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
            if (tab[row][col] < tab[row][col - 1])
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
            if (tab[row][col] < tab[row][col + 1])
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
    if (check_row_right(tab, pos, entry) == 1)
        return (1);
    if (check_col_down(tab, pos, entry) == 1)
        return (1);
    if (check_col_up(tab, pos, entry) == 1)
        return (1);
    return (0);
}

int solve(int tab[4][4], int entry[16], int pos)
{
    int size;

    if (pos == 16)
        return (1);
    size = 0;
    while (++size <= 4)
    {
        //checking if the number I want to place is correct
        if (check_case(tab, pos, entry, size) == 0)
        {
            tab[pos / 4][pos % 4] = size;
            //checking for next possibility
            if (solve(tab, entry, pos + 1) == 1)
                return (1);
        }
    }
    //did not find any solutions
    tab[pos / 4][pos % 4] = 0;
    return (0);
}

int main()
{
    int i;
    int j;
    int tab[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
    };
    int entry[16] = {4, 1, 2, 3, 1, 2, 2, 2, 2, 2, 2, 1, 3, 2, 4};
    i = -1;
    if (solve(tab, entry, 0) == 1)
    {
        while (++i < 4)
        {
            j = -1;
            while (++j < 4)
                printf("%d ", tab[i][j]);
            printf("\n");
        }
    }
    else
        printf("Did not find any solutions\n");
    return (0);
}