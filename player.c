/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** matchstick player
*/

#include "my.h"
#include "struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int player(map_t *mapt)
{
    int a = 0;

    my_putstr("\nYour turn:\nLine: ");
    mapt->linenbr = NULL;
    getline(&mapt->linenbr, &mapt->sizenbr, stdin);
    if (mapt->linenbr[0] == '\0')
        return (84);
    mapt->line = my_getnbr(mapt->linenbr);
    a = error_line(mapt);
    if (a == 84)
        return (84);
    my_putstr("Matches: ");
    mapt->linenbr = NULL;
    getline(&mapt->linenbr, &mapt->sizenbr, stdin);
    if (mapt->linenbr[0] == '\0')
        return (84);
    mapt->matche = my_getnbr(mapt->linenbr);
    a = error_matche(mapt);
    if (a == 84)
        return (84);
    return (0);
}
