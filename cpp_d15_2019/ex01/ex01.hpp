/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include <string.h>

template <typename T>
int compare(const T &a, const T &b)
{
    if (a == b)
        return (0);
    if (a < b)
        return (-1);
    if (a > b)
        return (1);
}

int compare(const char * const &a, const char * const &b)
{
    int tmp = strcmp(a, b);

    if (tmp > 0)
        return (1);
    if (tmp < 0)
        return (-1);
    return (0);
}