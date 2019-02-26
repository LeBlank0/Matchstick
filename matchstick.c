/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** matchstick game
*/

#include "my.h"
#include "struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int error_base(int ac, char **av)
{
    if (my_getnbr(av[1]) > 100 || my_getnbr(av[1]) <= 1 || ac > 3 || ac <= 1
        || my_getnbr(av[2]) <= 0)
        return (84);
    return (0);
}

void turn(map_t *mapt)
{
    my_putstr("Player removed ");
    my_put_nbr(mapt->matche);
    my_putstr(" match(es) from line ");
    my_put_nbr(mapt->line);
    my_putchar('\n');
    change_map(mapt);
    print_map(mapt);
}

int matchstick(int ac, char **av)
{
    map_t *mapt = malloc(sizeof(*mapt));
    int a = error_base(ac, av);

    if (a == 84)
        return (84);
    struct_set(mapt, av);
    print_map(mapt);
    for (; map_matche(mapt) != 0;) {
        a = player(mapt);
        if (a == 84)
            return (84);
        turn(mapt);
        if (map_matche(mapt) == 0) {
            my_putstr("You lost, too bad...\n");
            return (2);
        }
        a = bot(mapt);
        if (a == 1)
            return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    int a = matchstick(ac, av);

    return (a);
}
