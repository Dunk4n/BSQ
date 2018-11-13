/*
** EPITECH PROJECT, 2018
** display
** File description:
** display
*/

#include <stdlib.h>
#include "my.h"

void    discond(int **tab, int *res, char *str)
{
    if (res[6] > res[4] - res[2] && res[6] <= res[4] &&
res[5] > res[3] - res[2] && res[5] <= res[3])
        str[(res[6] * res[0]) + res[5] + res[6]] = 'x';
    else
        str[(res[6] * res[0]) + res[5] + res[6]] =
(tab[res[6]][res[5]] == 0) ? 'o' : '.';
}

void    display(int **tab, int *res)
{
    char    *str = malloc(res[0] * (res[1] + 1) + 1);

    while (res[6] < res[0]) {
        res[5] = 0;
        while (res[5] < res[1]) {
            discond(tab, res, str);
            res[5]++;
        }
        str[((res[6] + 1) * (res[0] + 1)) - 1] = '\n';
        res[6]++;
    }
    str[res[0] * (res[1] + 1)] = '\0';
    write(1, str, res[0] * (res[1] + 1));
}
