/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "bsq.h"
#include "my.h"

int     increment(char *buff, int **tab, int *cnt, int size)
{
    int i = 0;

    while (buff[cnt[2]] != '\0' && cnt[2] < size) {
        cnt[0] += (buff[cnt[2]] == '\n') ? 1 : 0;
        i = cnt[1];
        cnt[1] = (buff[cnt[2]] == '\n') ? 0 : cnt[1];
        if (buff[cnt[2]] != '\n' && buff[cnt[2]] != 'o' && buff[cnt[2]] != '.')
            return (-1);
        if (buff[cnt[2]] != '\n')
            tab[cnt[0]][cnt[1]++] = (buff[cnt[2]] == 'o') ? 0 : -1;
        cnt[2]++;
    }
    return (i);
}

int     bsq(int *cnt, char *buff, int fd)
{
    int **tab = malloc(sizeof(int*) * cnt[0]);
    int size = my_strlen(buff);
    int col = 0;

    while (cnt[2] < cnt[0])
        tab[cnt[2]++] = malloc(sizeof(int) * cnt[1]);
    cnt[2] = 1;
    while (buff[cnt[2] - 1] != '\0' && buff[cnt[2] - 1] != '\n')
        cnt[2]++;
    cnt[0] = 0;
    cnt[1] = 0;
    while (size != 0) {
        col = increment(buff, tab, cnt, size);
        if (col == -1)
            return (84);
        cnt[2] = 0;
        size = read(fd, buff, 29999);
        (fd != 0) ? buff[size] = '\0' : 0;
    }
    set_square(tab, cnt[0], col);
    return (0);
}

int     nb_col(char *buff)
{
    int col = 0;
    int n = 0;
    int i = 0;

    while (n != 2 && buff[i] != '\0') {
        n += (buff[i] == '\n') ? 1 : 0;
        col += (n == 1 && buff[i] != '\n') ? 1 : 0;
        i++;
    }
    return (col);
}

int     error(char *file, int *val, char *buff)
{
    struct stat AMP;
    int         oct;
    int         i = 0;
    int         tmp = val[0];

    while (tmp != 0) {
        tmp /= 10;
        i++;
    }
    i = (buff[0] == '0' && val[0] == 0) ? 1 : i;
    stat(file, &AMP);
    oct = AMP.st_size;
    if (oct == 0)
        return (84);
    if ((oct - (i + 1)) / (val[1] + 1) != val[0])
        return (84);
    if ((oct - (i + 1)) % (val[1] + 1) != 0)
        return (84);
    return (0);
}

int     main(int ac, char **av)
{
    char    buff[30000];
    int     fd = 1;
    int     size = 0;
    int     cnt[3] = {0, 0, 0};

    if (ac != 2)
        return (84);
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return (84);
    size = read(fd, buff, 29999);
    if (fd != 0)
        buff[size] = '\0';
    cnt[0] = my_getnbr(buff);
    cnt[1] = nb_col(buff);
    if (error(av[1], cnt, buff) == 84)
        return (84);
    if (bsq(cnt, buff, fd) == 84)
        return (84);
    close(fd);
    return (0);
}
