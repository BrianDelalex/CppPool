/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** return_intvalue_of_str_argument
*/

#include "castmania.h"

int integer_div(int a, int b)
{
    if (b == 0) {
        return (0);
    }
    return (a / b);
}

float decimale_div(int a, int b)
{
    if (b == 0) {
        return (0);
    }
    float res = (float) a / (float) b;
    return (res);
}

void  exec_div(division_t *operation)
{
    if (operation->div_type == 0) {
        integer_op_t *op = (integer_op_t *) operation->div_op;
        op->res = integer_div(op->a, op->b);
    } else if (operation->div_type == 1) {
        decimale_op_t *op = (decimale_op_t *) operation->div_op;
        op->res = decimale_div(op->a, op->b);
    }
}