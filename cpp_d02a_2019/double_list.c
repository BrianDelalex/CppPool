/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** return_intvalue_of_str_argument
*/

#include "double_list.h"
#include <stdlib.h>
#include <stdio.h>

unsigned int double_list_get_size(double_list_t list)
{
    unsigned int i = 0;

    for (; list != NULL; i++, list = list->next);
    return (i);
}

bool double_list_is_empty(double_list_t list)
{
    return (list == NULL);
}

void double_list_dump(double_list_t list)
{
    for (; list != NULL; list = list->next) {
        printf("%f\n", list->value);
    }
}

bool double_list_add_elem_at_front(double_list_t *front_ptr, double elem)
{
    double_list_t new = malloc(sizeof(doublelist_node_t));

    if (!new) {
        return (false);
    }
    new->value = elem;
    if (*front_ptr)
        new->next = *front_ptr;
    else
        new->next = NULL;
    *front_ptr = new;
    return (true);
}

bool  double_list_add_elem_at_back(double_list_t *front_ptr , double  elem)
{
    double_list_t new = malloc(sizeof(doublelist_node_t));
    double_list_t save_ptr = *front_ptr;

    if (!new) {
        return (false);
    }
    new->value = elem;
    new->next = NULL;
    if (*front_ptr == NULL) {
        *front_ptr = new;
        return (true);
    }
    for (; (*front_ptr)->next != NULL; *front_ptr = (*front_ptr)->next);
    (*front_ptr)->next = new;
    *front_ptr = save_ptr;
    return (true);
}
