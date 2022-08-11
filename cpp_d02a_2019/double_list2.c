/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** return_intvalue_of_str_argument
*/

#include "double_list.h"
#include <stdlib.h>

bool double_list_add_elem_at_position(double_list_t *front_ptr, double  elem, unsigned int position)
{
    double_list_t new = malloc(sizeof(doublelist_node_t));
    double_list_t save = *front_ptr;

    if (!new) {
        return (false);
    }
    if (position > double_list_get_size(*front_ptr)) {
        free(new);
        return (false);
    }
    if (position == 0) {
        free (new);
        return (double_list_add_elem_at_front(front_ptr, elem));
    }
    new->value = elem;
    for (unsigned int i = 0; i < position; i++, *front_ptr = (*front_ptr)->next);
    new->next = (*front_ptr)->next;
    (*front_ptr)->next = new;
    *front_ptr = save;
    return (true);
}

bool double_list_del_elem_at_front(double_list_t *front_ptr)
{
    double_list_t save = *front_ptr;

    if (double_list_is_empty(*front_ptr) == true) {
        return (false);
    }
    *front_ptr = (*front_ptr)->next;
    free(save);
    return (true);
}

bool double_list_del_elem_at_back(double_list_t *front_ptr)
{
    double_list_t save = *front_ptr;

    if (double_list_is_empty(*front_ptr) == true) {
        return (false);
    }
    for (; (*front_ptr)->next->next != NULL ; *front_ptr = (*front_ptr)->next);
    free((*front_ptr)->next);
    (*front_ptr)->next = NULL;
    *front_ptr = save;
    return (true);
}

bool double_list_del_elem_at_position(double_list_t *front_ptr, unsigned int position)
{
    double_list_t save = *front_ptr;
    double_list_t save2;

    if (double_list_is_empty(*front_ptr) == true || position < double_list_get_size(*front_ptr)) {
        return (false);
    }
    if (position == 0) {
        return (double_list_del_elem_at_front(front_ptr));
    }
    for (unsigned int i = 1; i < position; i++, *front_ptr = (*front_ptr)->next);
    save2 = (*front_ptr)->next->next;
    free((*front_ptr)->next);
    (*front_ptr)->next = save2;
    *front_ptr = save;
    return (true);
}

double double_list_get_elem_at_front(double_list_t list)
{
    if (list == NULL) {
        return (0);
    }
    return (list->value);
}