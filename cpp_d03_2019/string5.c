/*
** EPITECH PROJECT, 2018
** string.h
** File description:
** module string
*/

#include "./string.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int my_strlen2(const char *str, char separator)
{
    int i = 0;
    for (; str[i]; i++) {
        if (str[i] == separator) {
            return (i);
        }
    }
    return (i);
}

string_t  **split_s(const string_t *this, char separator)
{
    string_t **tab;
    int separators = 0, len = 0, ct = 0;

    for (int i = 0; this->str[i]; i++) {
        separators += this->str[i] == separator ? 1 : 0;
    }
    tab = malloc(sizeof(string_t *) * (separators + 3));
    for (int i = 0; this->str[i]; i = i + len + 1) {
        len = my_strlen2(this->str + i, separator);
        tab[ct] = malloc(sizeof(string_t));
        string_init(tab[ct], "");
        tab[ct]->str = malloc(sizeof(char) * (len + 1));
        for (int j = 0; j < len; j++)
            tab[ct]->str[j] = this->str[i + j];
        tab[ct]->str[len] = 0;
        ct++;
        if (!this->str[i + len])
            break;
    }
    tab[ct] = NULL;
    return (tab);
}

char **split_c(const string_t *this, char separator)
{
    char **tab;
    int separators = 0;
    int len = 0;
    int ct = 0;

    for (int i = 0; this->str[i]; i++) {
        separators += this->str[i] == separator ? 1 : 0;
    }
    tab = malloc(sizeof(char *) * (separators + 1));
    for (int i = 0; this->str[i]; i = i + len + 1) {
        len = my_strlen2(this->str + i, separator);
        tab[ct] = malloc(sizeof(char) * (len + 1));
        for (int j = 0; j < len; j++) {
            tab[ct][j] = this->str[i + j];
        }
        tab[ct][len] = 0;
        ct++;
    }
    tab[ct] = NULL;
    return (tab);
}

void print(const string_t *this)
{
    if (this->str)
        write(1, this->str, strlen(this->str));
}