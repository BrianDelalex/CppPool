/*
** EPITECH PROJECT, 2018
** string.h
** File description:
** module string
*/

#include "./string.h"
#include <string.h>
#include <stdlib.h>

void join_c(string_t *this, char  delim, const char * const *tab)
{
    char *new;
    int len = 0;
    int elem = 0;
    int ct = 0;

    for (; tab[elem]; elem++)
        len += strlen(tab[elem]);
    new = malloc(sizeof(char) * (len + elem));
    for (int i = 0; tab[i]; i++, ct++) {
        for (int j = 0; tab[i][j]; j++, ct++) {
            new[ct] = tab[i][j];
        }
        new[ct] = delim;
    }
    new[len + elem - 1] = 0;
    if (this->str) {
        free(this->str);
    }
    this->str = new;
}

void join_s(string_t *this, char  delim, const string_t * const *tab)
{
    char *new;
    int len = 0;
    int elem = 0;
    int ct = 0;

    for (; tab[elem]; elem++)
        len += strlen(tab[elem]->str);
    new = malloc(sizeof(char) * (len + elem));
    for (int i = 0; tab[i]; i++, ct++) {
        for (int j = 0; tab[i]->str[j]; j++, ct++) {
            new[ct] = tab[i]->str[j];
        }
        new[ct] = delim;
    }
    new[len + elem - 1] = 0;
    if (this->str) {
        free(this->str);
    }
    this->str = new;
}

string_t *substr(const string_t *this, int offset, int length)
{
    string_t *new = malloc(sizeof(string_t));
    int start = offset > 0 ? offset : (int) strlen(this->str) + offset;
    int length_sign = length / abs(length);
    int i = 0;

    new->str = malloc(sizeof(char) * (abs(length) + 1));
    for (; start >= 0x0 && this->str[start] && i < abs(length); \
    start = start + length_sign, i++) {
        new->str[i] = this->str[start];
    }
    new->str[i] = 0;
    return (new);
}