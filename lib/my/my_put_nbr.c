/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** display number
*/

int     my_putchar(char c);

int     my_put_nbr(int nb)
{
    int n = 1;

    if (nb < 0) {
        nb *= -1;
        my_putchar('-');
        n++;
    }
    if (nb < 10)
        my_putchar(nb + '0');
    else {
        n += my_put_nbr(nb / 10);
        my_putchar(nb % 10 + '0');
    }
    return (n);
}
