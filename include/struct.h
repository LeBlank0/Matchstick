/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** struct
*/

#include <stdio.h>

#ifndef LISTE_H_
#define LISTE_H_

typedef struct map_s
{
    int max;
    int size;
    char **map;
    char *linenbr;
    size_t sizenbr;
    int line;
    int matche;
    int a;
} map_t;

char **map_set(int size);
void struct_set(map_t *mapt, char **av);
int matchnbr(map_t *mapt);
int line_matche(char *mapline);
int map_matche(map_t *mapt);
int error_matche(map_t *mapt);
void change_map(map_t *mapt);
void print_map(map_t *mapt);
int error_line(map_t *mapt);
int player(map_t *mapt);
int bot(map_t *mapt);

#endif
