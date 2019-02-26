/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** matchstick bot
*/

#include "my.h"
#include "struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int line_matche(char *mapline)
{
    int nb = 0;

    for (int i = 0; mapline[i] != '\0'; i++)
        if (mapline[i] == '|')
            nb++;
    return (nb);
}

int map_matche_bis(map_t *mapt, int i, int nb)
{
    for (int y = 0; mapt->map[i][y] != '\0'; y++)
        if (mapt->map[i][y] == '|')
            nb++;
    return (nb);
}

int map_matche(map_t *mapt)
{
    int nb = 0;

    for (int i = 0; i != (mapt->size + 1); i++)
        nb = map_matche_bis(mapt, i, nb);
    return (nb);
}
