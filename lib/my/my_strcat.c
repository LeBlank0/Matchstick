/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** cat
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int w = 0;

    while (dest[i] != '\0') {
        i++;
    }
    while (src[w] != '\0') {
        dest[i + w] = src [w];
        w++;
    }
    dest[i + w] = '\0';
    return (dest);
}
