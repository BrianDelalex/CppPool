/*
** EPITECH PROJECT, 2019
** FruitNode.hpp
** File description:
** 
*/

#ifndef FRUITNODE_HPP_
#define FRUITNODE_HPP_

#include "Fruit.hpp"

typedef struct FruitNode_s
{
    Fruit *_value;
    FruitNode_s *next;
} FruitNode;
#endif
