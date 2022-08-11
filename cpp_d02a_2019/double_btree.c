/*
** EPITECH PROJECT, 2018
** cpp_d02a
** File description:
** ex01
*/

#include "double_btree.h"
#include <stdlib.h>

bool double_btree_is_empty(double_btree_t tree)
{
    return (tree == NULL);
}

unsigned int double_btree_get_size(double_btree_t tree)
{
    if (tree == NULL) {
        return (0);
    }
    return (double_btree_get_size(tree->right) + double_btree_get_size(tree->left) + 1);
}

unsigned int double_btree_get_depth(double_btree_t tree)
{
    int a = 0;
    int b = 0;

    if (tree == NULL) {
        return (0);
    }
    a = double_btree_get_depth(tree->right);
    b = double_btree_get_depth(tree->left);
    if (a > b) {
        return (a + 1);
    }
    return (b + 1);
}

bool double_btree_create_node(double_btree_t *node_ptr, double value)
{
    double_btree_t new = malloc(sizeof(doublebtree_node_t));

    if(!new) {
        return (false);
    }
    new->value = value;
    new->right = NULL;
    new->left = NULL;
    *node_ptr = new;
    return (true);
}

bool double_btree_delete(double_btree_t *root_ptr)
{
    if (root_ptr == NULL) {
        return (false);
    }
    double_btree_delete(&(*root_ptr)->right);
    double_btree_delete(&(*root_ptr)->left);
    if ((*root_ptr)->right) {
        free((*root_ptr)->right);
    }
    if ((*root_ptr)->left) {
        free((*root_ptr)->left);
    }
    free(*root_ptr);
    return (true);
}