/*
** EPITECH PROJECT, 2018
** square
** File description:
** square
*/

#include "my.h"
#include "bsq.h"

int     sq_valid(int **tab, int x, int y, int n)
{
    int i = 0;

    while (i < n) {
        if (tab[x + i][y] == 0 || tab[x][y + i] == 0)
            return (0);
        i++;
    }
    return (1);
}

int     all_sq(int **tab, int x, int y)
{
    int n = 1;

    while (n < tab[x][y]) {
        if (x - n < 0 || y - n < 0 || sq_valid(tab, x - n, y - n, n) == 0)
            return (n);
        n++;
    }
    return (n);
}

void    all_map(int **tab, int y, int *res)
{
    int j = 0;

    while (j < y) {
        if (tab[res[0]][j] > res[2] && all_sq(tab, res[0], j) > res[2]) {
            res[2] = all_sq(tab, res[0], j);
            res[3] = j;
            res[4] = res[0];
        }
        j++;
    }
}

int     cond(int **tab, int i, int j)
{
    int tmp1 = 0;
    int tmp2 = 0;

    if (tab[i][j] == 0)
        return (0);
    tmp1 = (i > 0) ? tab[i - 1][j] + 1 : 1;
    tmp2 = (j > 0) ? tab[i][j - 1] + 1 : 1;
    tmp1 = (tmp1 > tmp2) ? tmp2 : tmp1;
    return (tmp1);
}

void    set_square(int **tab, int x, int y)
{
    int res[5] = {0, 0, 0, 0, 0};

    while (res[0] < x) {
        res[1] = 0;
        while (res[1] < y) {
            tab[res[0]][res[1]] = cond(tab, res[0], res[1]);
            res[1]++;
        }
        res[0]++;
    }
    res[0] = 0;
    res[1] = 0;
    while (res[0] < x) {
        all_map(tab, y, res);
        res[0]++;
    }
    res[0] = x;
    res[1] = y;
    display(tab, res);
}
