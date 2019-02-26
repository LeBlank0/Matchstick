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

int bot(map_t *mapt)
{
    srandom((unsigned)time(NULL));
    my_putstr("\nAI's turn...\n");
    mapt->line = (random() % (mapt->size) + 1);
    while (line_matche(mapt->map[mapt->line]) < 1)
        mapt->line = (random() % (mapt->size) + 1);
    mapt->matche = (random() % (line_matche(mapt->map[mapt->line])) + 1);
    while (mapt->matche > mapt->max)
        mapt->matche = (random() % (line_matche(mapt->map[mapt->line])) + 1);
    my_putstr("AI removed ");
    my_put_nbr(mapt->matche);
    my_putstr(" match(es) from line ");
    my_put_nbr(mapt->line);
    my_putchar('\n');
    change_map(mapt);
    print_map(mapt);
    if (map_matche(mapt) == 0) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (1);
    }
    return (0);
}
