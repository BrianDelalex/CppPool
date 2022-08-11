/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** return_intvalue_of_str_argument
*/

#include "ptr_tricks.h"

int get_array_nb_elem(const int *ptr1, const int *ptr2)
{
    int i = 0;

    if (ptr1 < ptr2) {
        for (; ptr1 != ptr2; ptr1++, i++);
        return (i);
    } else {
        for (; ptr2 != ptr1; ptr2++, i++);
        return (i);
    }
}

whatever_t *get_struct_ptr(const int *member_ptr)
{
    char *ptr = (char *) member_ptr;
    int max = sizeof(whatever_t);

    for (int i = 0; i < max ; i++) {
        whatever_t *ptr2 = (whatever_t *)(ptr + i);
        if (&(ptr2->member) == member_ptr) {
            return (ptr2);
        }
        ptr2 = (whatever_t *)(ptr - i);
        if (&(ptr2->member) == member_ptr) {
            return (ptr2);
        }
    }
}