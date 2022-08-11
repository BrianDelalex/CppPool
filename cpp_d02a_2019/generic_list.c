/*
** EPITECH PROJECT, 2018
** cpp_d02a
** File description:
** ex02
*/

#include "generic_list.h"
#include <stdlib.h>

unsigned int list_get_size(list_t list)
{
    unsigned int i = 0;

    if (list == NULL) {
        return (0);
    }
    while (list) {
        i++;
        list = list->next;
    }
    return (i);
}

bool list_is_empty(list_t list)
{
    return (list == NULL);
}

bool list_add_elem_at_front(list_t *front_ptr,void *elem)
{
    list_t new = malloc(sizeof(node_t));

    if (!new) {
        return (false);
    }
    new->value = elem;
    new->next = *front_ptr;
    *front_ptr = new;
    return (true);
}

bool list_add_elem_at_back(list_t *front_ptr, void *elem)
{
    list_t new = malloc(sizeof(node_t));
    list_t save = *front_ptr;

    if (!new) {
        return (false);
    }
    new->value = elem;
    new->next = NULL;
    if ((*front_ptr) == NULL) {
        *front_ptr = new;
        return (true);
    }
    while ((*front_ptr)->next) {
        *front_ptr = (*front_ptr)->next;
    }
    (*front_ptr)->next = new;
    *front_ptr = save;
    return (true);
}

bool list_add_elem_at_position(list_t *front_ptr, void *elem, unsigned int pos)
{
    list_t new = malloc(sizeof(node_t));
    list_t save = *front_ptr;

    if (!new) {
        return (false);
    }
    if (list_get_size(*front_ptr) < pos) {
        free(new);
        return (false);
    }
    if (pos == 0) {
        return (list_add_elem_at_front(front_ptr, elem));
    }
    new->value = elem;
    for (unsigned int i = 0; i < pos; i++, *front_ptr = (*front_ptr)->next);
    new->next = (*front_ptr)->next;
    (*front_ptr)->next = new;
    *front_ptr = save;
    return (true);
}