/*
** EPITECH PROJECT, 2018
** display
** File description:
** display
*/

#include <stdlib.h>
#include "my.h"

void    discond(int **tab, int *res, char *str, int lig)
{
    if (res[6] > res[4] - res[2] && res[6] <= res[4] &&
res[5] > res[3] - res[2] && res[5] <= res[3])
        str[(res[6] * (lig + 1)) + res[5]] = 'x';
    else
        str[(res[6] * (lig + 1)) + res[5]] =
(tab[res[6]][res[5]] == 0) ? 'o' : '.';
}

void    free_tab(int **tab, int size)
{
    int i = 0;

    while (i < size) {
        free(tab[i]);
        i++;
    }
    free(tab);
}

void    display(int **tab, int *res)
{
    char    *str = malloc(res[0] * (res[1] + 1) + 1);
    int     lig = 0;

    while (res[6] < res[0]) {
        res[5] = 0;
        while (res[5] < res[1]) {
            discond(tab, res, str, lig);
            res[5]++;
            lig += (res[6] == 0) ? 1 : 0;
        }
        str[(res[5]) * (res[6] + 1) + res[6]] = '\n';
        res[6]++;
    }
    str[res[0] * (res[1] + 1)] = '\0';
    write(1, str, res[0] * (res[1] + 1));
    free(str);
    free_tab(tab, res[0]);
}
