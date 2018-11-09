/*
** EPITECH PROJECT, 2018
** my_compute_power_rec
** File description:
** unlimited POWER!!!
*/

int     my_compute_power_rec(int nb, int p)
{
    long lnb = 0;

    if (p == 0)
        return (1);
    if (p < 0 || nb == 0)
        return (0);
    lnb = my_compute_power_rec(nb, p - 1);
    lnb *= nb;
    if (lnb  > 2147483647)
        return (0);
    if (lnb < -2147483648)
        return (0);
    return (lnb);
}
