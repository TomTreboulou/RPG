/*
** EPITECH PROJECT, 2018
** Visual Studio Live Share (Workspace)
** File description:
** connector.c
*/

// A LA NORME

#include "source_toolbox.h"
#include "project.h"

char *cnc(char *s1, char *s2)
{
    char *res = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 3));
    int i = 0;

    for (i = 0; s1[i] != '\0'; i++)
        res[i] = s1[i];
    for (int j = 0; s2[j] != '\0'; j++, i++)
        res[i] = s2[j];
    res[i] = '\0';
    return (res);
}

char *cni(char *s1, int nb)
{
    char *res;
    int i = 0;

    for (int tmp = nb; tmp != 0; tmp = tmp / 10, i++)
    res = malloc(sizeof(char) * (my_strlen(s1) + i + 2));
    for (i = 0; s1[i] != '\0'; i++)
        res[i] = s1[i];
    for (int tmp = nb, tmp2 = tmp, j = 1; tmp != 0; i++) {
        for (j = 1, tmp2 = tmp; tmp2 >= 10; tmp2 = tmp2 / 10)
            j *= 10;
        res[i] = tmp2 + 47;
        tmp = tmp % j;
    }
    res[i] = '\0';
    return (res);
}

char *cni2(int number)
{
    char *array;
    int i = 0;

    for (int tmp = number; tmp != 0; i++, tmp /= 10);
    array = malloc(sizeof(char) * (i + 3));
    if (number <= 0)
        return ("0");
    if (number <= 9) {
        array[0] = number + 48;
        array[1] = '\0';
        return (array);
    }
    array[i] = '\0';
    array[0] = '0';
    for (; i != 0; i--, number /= 10)
        array[i - 1] = number % 10 + 48;
    return (array);
}