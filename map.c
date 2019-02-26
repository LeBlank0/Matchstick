/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** matchstick map change
*/

#include "my.h"
#include "struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

void print_map(map_t *mapt)
{
    for (int i = 0; i != (mapt->size + 2); i++) {
        my_putstr(mapt->map[i]);
        my_putchar('\n');
    }
}

void change_map(map_t *mapt)
{
    for (int max = (mapt->size * 2); mapt->matche > 0 && line_matche
        (mapt->map[mapt->line]) > 0;) {
        if (mapt->map[mapt->line][max] == '|') {
            mapt->map[mapt->line][max] = ' ';
            mapt->matche -= 1;
            max -= 1;
        }
        else
            max -= 1;
    }
    mapt->matche = 0;
    mapt->line = 0;
}
