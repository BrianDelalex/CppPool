/*
** EPITECH PROJECT, 2018
** cpp_d02a
** File description:
** ex02
*/

#include "generic_list.h"
#include <stdlib.h>

bool list_del_elem_at_front(list_t *front_ptr)
{
    list_t save = (*front_ptr);

    if (list_is_empty(*front_ptr) == true) {
        return (false);
    }
    *front_ptr = (*front_ptr)->next;
    free(save);
    return (true);
}

bool list_del_elem_at_back(list_t *front_ptr)
{
    list_t save = (*front_ptr);

    if (list_is_empty(*front_ptr) == true) {
        return (false);
    }
    if (list_get_size(*front_ptr) == 1) {
        *front_ptr = NULL;
        return (true);
    }
    while ((*front_ptr)->next->next) {
        *front_ptr = (*front_ptr)->next;
    }
    free((*front_ptr)->next);
    (*front_ptr)->next = NULL;
    *front_ptr = save;
    return (true);
}

bool list_del_elem_at_position(list_t *front_ptr, unsigned int position)
{
    list_t save = *front_ptr;
    list_t save2;

    if (list_is_empty(*front_ptr) == true || position < list_get_size(*front_ptr)) {
        return (false);
    }
    if (position == 0) {
        return (list_del_elem_at_front(front_ptr));
    }
    for (unsigned int i = 1; i < position; i++, *front_ptr = (*front_ptr)->next);
    save2 = (*front_ptr)->next->next;
    free((*front_ptr)->next);
    (*front_ptr)->next = save2;
    *front_ptr = save;
    return (true);
}

void list_clear(list_t *front)
{
    while (*front != NULL)
        list_del_elem_at_back(front);
}

void *list_get_elem_at_front(list_t list)
{
    if (list == NULL) {
        return (NULL);
    }
    return (list->value);
}