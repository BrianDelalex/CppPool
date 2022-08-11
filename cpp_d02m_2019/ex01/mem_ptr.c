/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** return_intvalue_of_str_argument
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mem_ptr.h"

void  add_str(const char *str1, const char *str2, char **res)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int ct = 0;
    char *new = malloc(sizeof(char) * (len1 + len2 + 1));

    for (int i = 0; str1[i]; i++, ct++) {
        new[ct] = str1[i];
    }
    for (int i = 0; str2[i]; i++, ct++) {
        new[ct] = str2[i];
    }
    new[ct] = 0;
    *res = new;
}

void  add_str_struct(str_op_t *str_op)
{
    int len1 = strlen(str_op->str1);
    int len2 = strlen(str_op->str2);
    int ct = 0;

    str_op->res = malloc(sizeof(char) * (len1 + len2 +1));
    for (int i = 0; str_op->str1[i]; i++, ct++) {
        str_op->res[ct] = str_op->str1[i];
    }
    for (int i = 0; str_op->str2[i]; i++, ct++) {
        str_op->res[ct] = str_op->str2[i];
    }
    str_op->res[ct] = 0;
}