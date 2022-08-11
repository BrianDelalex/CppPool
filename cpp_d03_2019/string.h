/*
** EPITECH PROJECT, 2018
** string.h
** File description:
** module string
*/

#ifndef STRING_H_
#define STRING_H_

#include <stdlib.h>

typedef struct string_s
{
    char *str;
    void (*assign_s)();
    void (*assign_c)();
    void (*append_c)();
    void (*append_s)(struct string_s *this, const struct string_s *ap);
    char (*at)();
    void (*clear)();
    int (*size)();
    int (*compare_s)();
    int (*compare_c)();
    size_t (*copy)();
    const char *(*c_str)();
    int (*empty)();
    int (*find_s)();
    int (*find_c)();
    void (*insert_c)();
    void (*insert_s)();
    int (*to_int)();
    struct string_s **(*split_s)(const struct string_s *, char);
    char **(*split_c)(const struct string_s *this, char separator);
    void (*join_c)(struct string_s *this, char delim, const char * const *tab);
    void (*join_s)(struct string_s *this, char  delim, \
    const struct string_s * const *tab);
    struct string_s *(*substr)();
    void (*print)();
}string_t;


void string_init(string_t *this, const char *s);
void string_destroy(string_t *this);
void assign_s(string_t *this, const string_t *str);
void assign_c(string_t *this, const char *s);
void append_s(string_t *this, const string_t *ap);
void append_c(string_t *this, const char *ap);
char at(const string_t *this, size_t pos);
void clear(string_t *this);
int size(const string_t *this);
int compare_s(const string_t *this, const string_t *str);
int compare_c(const string_t *this, const char *str);
size_t copy(const string_t *this, char *s, size_t n, size_t pos);
const char *c_str(const string_t *this);
int empty(const string_t *this);
int find_s(const string_t *this, const string_t *str, size_t pos);
int find_c(const string_t *this, const char *str, size_t pos);
void insert_c(string_t *this, size_t pos, const char *str);
void insert_s(string_t *this, size_t pos, const string_t *str);
int to_int(const string_t *this);
string_t **split_s(const string_t *this, char separator);
char **split_c(const string_t *this, char separator);
void join_c(string_t *this, char delim, const char * const *tab);
void join_s(string_t *this, char  delim, const string_t * const *tab);
string_t *substr(const string_t *this, int offset, int length);
void print(const string_t *this);

#endif