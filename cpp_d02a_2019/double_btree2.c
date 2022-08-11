/*
** EPITECH PROJECT, 2018
** cpp_d02a
** File description:
** ex01
*/

#include "double_btree.h"
#include <stdlib.h>
#include "stdio.h"

double double_btree_get_max_value(double_btree_t tree)
{
    if (tree == NULL) {
        return (0);
    }
    int a = double_btree_get_max_value(tree->right);
    int b = double_btree_get_max_value(tree->left);
    if (a > b) {
        if (tree->value > a) {
            return (tree->value);
        }
        return (a);
    }
    if (tree->value > b) {
        return (tree->value);
    }
    return (b);
}

double  double_btree_get_min_value(double_btree_t  tree)
{
    int a = 100000000;
    int b = 100000000;
    if (tree == NULL) {
        return (0);
    }
    if (tree->right) {
        a = double_btree_get_min_value(tree->right);
    }
    if (tree->left) {
        b = double_btree_get_min_value(tree->left);
    }
    if (a < b) {
        if (tree->value < a) {
            return (tree->value);
        }
        return (a);
    }
    if (tree->value < b) {
        return (tree->value);
    }
    return (b);
}