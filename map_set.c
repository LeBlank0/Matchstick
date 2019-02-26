/*
** EPITECH PROJECT, 2018
** map_set
** File description:
** matchstick map
*/

#include "my.h"
#include "struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void struct_set(map_t *mapt, char **av)
{
    mapt->max = my_getnbr(av[2]);
    mapt->size = my_getnbr(av[1]);
    mapt->map = map_set(mapt->size);
    mapt->line = 0;
    mapt->matche = 0;
    mapt->a = 0;
    mapt->linenbr = NULL;
}

char **map_match(char **map, int size)
{
    int space = (size);
    int match = 1;
    int a = 0;

    for (int i = 1; i <= size; i++) {
        for (int mat = 0; mat < match; mat++) {
            map[i][space + a] = '|';
            a++;
        }
        a = 0;
        match += 2;
        space -= 1;
    }
    return (map);
}

char **map_outside(char **map, int size, int y, int i)
{
    if (y == 0 || y == (size + size))
        map[i][y] = '*';
    else if (i == 0 || i == (size + 1))
        map[i][y] = '*';
    else
        map[i][y] = ' ';
    map[i][size + size + 1] = '\0';
    return (map);
}

char **map_set(int size)
{
    char **map = malloc(sizeof(char*) * (size + 2));

    for (int i = 0; i <= (size + 1); i++) {
        map[i] = malloc(sizeof(char) * (size + size + 2));
        for (int y = 0; y <= (size + size + 1); y++)
            map = map_outside(map, size, y, i);
    }
    map = map_match(map, size);
    return (map);
}
