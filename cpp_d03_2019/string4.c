/*
** EPITECH PROJECT, 2018
** string.h
** File description:
** module string
*/

#include "./string.h"
#include <string.h>
#include <stdlib.h>

int find_c(const string_t *this, const char *str, size_t pos)
{
    int i = 0;
    int len = strlen(str);
    int ct = 0;

    if (len > (int) ( strlen(this->str) - pos) || pos > strlen(this->str)) {
        return (-1);
    }
    for (; this->str[i + pos]; i++) {
        if (this->str[i + pos] == str[ct]) {
            ct++;
        } else {
            ct = 0;
        }
        if (len == ct) {
            return (i + pos - len + 1);
        }
    }
    return (-1);
}

void insert_c(string_t *this, size_t pos, const char *str)
{
    char *new = malloc(sizeof(char) * (strlen(str) + strlen(this->str) + 1));
    int ct = 0;

    if (pos > strlen(this->str)) {
        append_c(this, str);
        free(new);
        return;
    }
    for (; ct < (int) pos; ct++) {
        new[ct] = this->str[ct];
    }
    for (int i = 0; str[i]; i++, ct++) {
        new[ct] = str[i];
    }
    for (int i = pos; this->str[i]; i++, ct++) {
        new[ct] = this->str[i];
    }
    new[ct] = 0;
    free(this->str);
    this->str = new;
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    char *new = malloc(sizeof(char) * \
    (strlen(str->str) + strlen(this->str) + 1));
    int ct = 0;

    if (pos > strlen(this->str)) {
        append_c(this, str->str);
        free(new);
        return;
    }
    for (; ct < (int) pos; ct++) {
        new[ct] = this->str[ct];
    }
    for (int i = 0; str->str[i]; i++, ct++) {
        new[ct] = str->str[i];
    }
    for (int i = pos; this->str[i]; i++, ct++) {
        new[ct] = this->str[i];
    }
    new[ct] = 0;
    free(this->str);
    this->str = new;
}

int to_int(const string_t *this)
{
    if (this->str) {
        return (atoi(this->str));
    }
    return (-1);
}

void append_s(string_t *this, const string_t *ap)
{
    this->str = realloc(this->str, sizeof(char) * \
    (strlen(this->str) + strlen(ap->str) + 1));
    this->str = strcat(this->str, ap->str);
}