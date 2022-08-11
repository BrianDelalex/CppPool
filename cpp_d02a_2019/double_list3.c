/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** return_intvalue_of_str_argument
*/

#include "double_list.h"
#include <stdlib.h>
#include <stdio.h>

double double_list_get_elem_at_back(double_list_t list)
{
    if (list == NULL) {
        return (0);
    }
    for (; list->next != NULL; list = list->next);
    return (list->value);
}

double double_list_get_elem_at_position(double_list_t list, unsigned int position)
{
    if (list == NULL || position < double_list_get_size(list)) {
        return (0);
    }
    for (unsigned int i = 0; i < position; i++, list = list->next);
    return (list->value);
}

doublelist_node_t *double_list_get_first_node_with_value(double_list_t list, double value)
{
    for (; list->next != NULL ; list = list->next) {
        if (list->value == value) {
            return (list);
        }
    }
    return (NULL);
}