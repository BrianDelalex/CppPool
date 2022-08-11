/*
** EPITECH PROJECT, 2018
** cpp_d02a
** File description:
** ex02
*/

#include "generic_list.h"
#include <stdlib.h>

void *list_get_elem_at_back(list_t list)
{
    if (list == NULL) {
        return (NULL);
    }
    while (list->next)
        list = list->next;
    return (list->value);
}

void *list_get_elem_at_position(list_t list, unsigned int position)
{
    if (list == NULL || list_get_size(list) < position) {
        return (NULL);
    }
    for (unsigned int i = 0; i < position; i++, list = list->next);
    return (list->value);
}

void list_dump(list_t list ,value_displayer_t val_disp)
{
    while (list) {
        val_disp(list->value);
        list = list->next;
    }
}

node_t *list_get_first_node_with_value(list_t  list , void *value ,value_comparator_t  val_comp)
{
    while (list) {
        if (val_comp(list->value, value))
        {
            return (list);
        }
        list = list->next;
    }
    return (NULL);
}