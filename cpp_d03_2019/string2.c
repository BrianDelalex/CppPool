/*
** EPITECH PROJECT, 2018
** string.h
** File description:
** module string
*/

#include "./string.h"
#include <string.h>
#include <stdlib.h>

void append_c(string_t *this, const char *ap)
{
    this->str = realloc(this->str, sizeof(char) * \
    (strlen(this->str) + strlen(ap) + 1));
    this->str = strcat(this->str, ap);
}

char at(const string_t *this, size_t pos)
{
    int i = 0;
    if (!this->str || pos > strlen(this->str)) {
        return (-1);
    }
    for (; this->str[i] && i != (int) pos; i++);
    return (this->str[i]);
}

void clear(string_t *this)
{
    if (this->str) {
        free(this->str);
        this->str = NULL;
    }
}

int size(const string_t *this)
{
    if (!this->str) {
        return (-1);
    }
    return (strlen(this->str));
}

int compare_s(const string_t *this, const string_t *str)
{
    return (strcmp(this->str, str->str));
}