/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** return_intvalue_of_str_argument
*/

#include "castmania.h"

int normal_add(int a, int b)
{
    return (a + b);
}

int absolute_add(int a, int b)
{
    if (a < 0) {
        a = -a;
    }
    if (b < 0) {
        b = -b;
    }
    return (a+b);
}

void exec_add(addition_t *operation)
{
    void *add_func[2] = {&normal_add, &absolute_add};
    int (*fptr)(int, int);

    fptr = add_func[operation->add_type];
    operation->add_op.res = fptr(operation->add_op.a, operation->add_op.b);
}