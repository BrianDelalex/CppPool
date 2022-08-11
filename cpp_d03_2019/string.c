/*
** EPITECH PROJECT, 2018
** string.h
** File description:
** module string
*/

#include "./string.h"
#include <string.h>
#include <stdlib.h>

void string_init2(string_t *this)
{
    this->insert_c = insert_c;
    this->insert_s = insert_s;
    this->to_int = to_int;
    this->split_s = split_s;
    this->split_c = split_c;
    this->join_c = join_c;
    this->join_s = join_s;
    this->substr = substr;
}

void string_init(string_t *this, const char *s)
{
    this->str = malloc(sizeof(char) * (strlen(s) + 1));
    for (int i = 0; s[i]; i++) {
        this->str[i] = s[i];
    }
    this->str[strlen(s)] = 0;
    this->assign_s = assign_s;
    this->assign_c = assign_c;
    this->append_c = append_c;
    this->append_s = append_s;
    this->at = at;
    this->clear = clear;
    this->size = size;
    this->compare_s = compare_s;
    this->compare_c = compare_c;
    this->copy = copy;
    this->c_str = c_str;
    this->empty = empty;
    this->find_s = find_s;
    this->find_c = find_c;
    this->print = print;
    string_init2(this);
}

void string_destroy(string_t *this)
{
    if (this->str != NULL) {
        free(this->str);
    }
    this = NULL;
}

void assign_s(string_t *this, const string_t *str)
{
    if (this->str)
        free(this->str);
    this->str = strdup(str->str);
}

void assign_c(string_t *this, const char *s)
{
    if (this->str)
        free(this->str);
    this->str = strdup(s);
}