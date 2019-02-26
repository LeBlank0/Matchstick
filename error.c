/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** matchstick error
*/

#include "my.h"
#include "struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int valid_input(char *test)
{
    for (int i = 0; test[i] != '\0' && test[i] != '\n'; i++)
        if (test[i] < 48 || test[i] > 57)
            return (1);
    return (0);
}

int error_line(map_t *mapt)
{
    if (valid_input(mapt->linenbr) == 1) {
        my_putstr("Error: invalid input (positive number expected)\nLine: ");
        mapt->linenbr = NULL;
        getline(&mapt->linenbr, &mapt->sizenbr, stdin);
        if (mapt->linenbr[0] == '\0')
            return (84);
        mapt->line = my_getnbr(mapt->linenbr);
        error_line(mapt);
    }
    if (mapt->line > mapt->size || mapt->line < 1 ||
        line_matche(mapt->map[mapt->line]) == 0) {
        my_putstr("Error: this line is out of range\nLine: ");
        mapt->linenbr = NULL;
        getline(&mapt->linenbr, &mapt->sizenbr, stdin);
        if (mapt->linenbr[0] == '\0')
            return (84);
        mapt->line = my_getnbr(mapt->linenbr);
        error_line(mapt);
    }
    return (0);
}

int error_matche_bis(map_t *mapt)
{
    my_putstr("Line: ");
    mapt->linenbr = NULL;
    getline(&mapt->linenbr, &mapt->sizenbr, stdin);
    if (mapt->linenbr[0] == '\0')
        return (84);
    mapt->line = my_getnbr(mapt->linenbr);
    error_line(mapt);
    my_putstr("Matches: ");
    mapt->linenbr = NULL;
    getline(&mapt->linenbr, &mapt->sizenbr, stdin);
    if (mapt->linenbr[0] == '\0')
        return (84);
    mapt->matche = my_getnbr(mapt->linenbr);
    return (0);
}

int error_test(map_t *mapt)
{
    int a = 0;

    my_putstr("Error: not enough matches on this line\n");
    a = error_matche_bis(mapt);
    error_matche(mapt);
    return (a);
}

int error_matche(map_t *mapt)
{
    if (mapt->matche < 0 || valid_input(mapt->linenbr) == 1) {
        my_putstr("Error: invalid input (positive number expected)\n");
        mapt->a = error_matche_bis(mapt);
        error_matche(mapt);
    }
    if (mapt->matche > mapt->max) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(mapt->max);
        my_putstr(" matches per turn\n");
        mapt->a = error_matche_bis(mapt);
        error_matche(mapt);
    }
    if (mapt->matche == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        mapt->a = error_matche_bis(mapt);
        error_matche(mapt);
    }
    if (mapt->matche > line_matche(mapt->map[mapt->line]))
        mapt->a = error_test(mapt);
    return (mapt->a);
}
