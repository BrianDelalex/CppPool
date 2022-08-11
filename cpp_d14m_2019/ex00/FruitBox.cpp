/*
** EPITECH PROJECT, 2019
** FruitBox.cpp
** File description:
** 
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int size)
{
    this->_maxSize = size;
    this->_list = nullptr;
}

FruitBox::~FruitBox() 
{
    FruitNode *next;
    for (; this->_list; this->_list = next) {
        next = this->_list->_next;
        delete this->_list;
    }
}

int FruitBox::nbFruits()
{
    FruitNode *save = this->_list;
    int i = 0;
    for (;this->_list != nullptr; i++, this->_list = this->_list->_next);
    this->_list = save;
    return (i);
}

bool FruitBox::putFruit(Fruit *f)
{
    if (nbFruits() >= _maxSize) {
        return (false);
    }
    FruitNode *save = this->_list;
    for (; this->_list; this->_list = this->_list->_next)
        if (this->_list->_value == f) {
            this->_list = save;
            return (false);
        }
    this->_list = save;
    FruitNode *add = new FruitNode;
    add->_value = f;
    add->_next = nullptr;
    if (this->_list == nullptr) {
        this->_list = add;
        return (true);
    }
    for ( ;this->_list->_next; this->_list = this->_list->_next);
    this->_list->_next = add;
    this->_list = save;
    return (true);
}

Fruit *FruitBox::pickFruit()
{
    if (this->_list == nullptr)
        return (nullptr);
    FruitNode *save = this->_list;
    Fruit *rtn = save->_value;
    this->_list = this->_list->_next;
    delete save;
    return (rtn);
}

FruitNode *FruitBox::head()
{
    return (this->_list);
}