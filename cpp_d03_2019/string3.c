/*
** EPITECH PROJECT, 2018
** string.h
** File description:
** module string
*/

#include "./string.h"
#include <string.h>
#include <stdlib.h>

int compare_c(const string_t *this, const char *str)
{
    return (strcmp(this->str, str));
}

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    int i = 0;
    if (pos > strlen(this->str)) {
        return (0);
    }
    for (; this->str[pos + i] && i < (int) n; i++) {
        s[i] = this->str[pos + i];
    }
    if (i < (int) n && this->str[pos + i] ==  0) {
        s[i] = 0;
        i++;
    } 
    return ((size_t)i);
}

const char *c_str(const string_t *this)
{
    return (this->str);
}

int empty(const string_t *this)
{
    if (this == NULL || this->str == NULL) {
        return (1);
    }
    return (0);
}

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    int i = 0;
    int len = strlen(str->str);
    int ct = 0;

    if (len > (int) (strlen(this->str) - pos) || pos > strlen(this->str)) {
        return (-1);
    }
    for (; this->str[i + pos]; i++) {
        if (this->str[i + pos] == str->str[ct]) {
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