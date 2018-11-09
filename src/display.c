/*
** EPITECH PROJECT, 2018
** display
** File description:
** display
*/

#include "my.h"

void    discond(int **tab, int *res, int x, int y)
{
    if (y > res[4] - res[2] && y <= res[4] &&
x > res[3] - res[2] && x <= res[3])
        my_putchar('x');
    else
        my_putchar((tab[y][x] == 0) ? 'o' : '.');
}

void    display(int **tab, int *res)
{
    int x = 0;
    int y = 0;

    while (y < res[0]) {
        x = 0;
        while (x < res[1]) {
            discond(tab, res, x, y);
            x++;
        }
        my_putchar('\n');
        y++;
    }
}
