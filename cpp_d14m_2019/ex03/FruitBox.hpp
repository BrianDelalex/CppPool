/*
** EPITECH PROJECT, 2019
** FruitBox.hpp
** File description:
** 
*/

#ifndef FRUITBOX_HPP_
#define FRUITBOX_HPP_

#include "Fruit.hpp"
#include "FruitNode.hpp"

class FruitBox
{
public:
    FruitBox(int size);
    ~FruitBox();
    int nbFruits() const;
    bool putFruit(Fruit *f);
    Fruit *pickFruit();
    FruitNode *head() const;
    void show();
private:
    FruitNode *_list;
    int _maxSize;
};

#endif
