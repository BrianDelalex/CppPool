/*
** EPITECH PROJECT, 2019
** PapaXmasTable.cpp
** File description:
** 
*/

#include "PapaXmasTable.hpp"

PapaXmasTable::PapaXmasTable() : ITable()
{
    for (int i = 0; i < 10; i++)
        this->_items[i] = nullptr;
}

PapaXmasTable::~PapaXmasTable() {}


void PapaXmasTable::put(Object *obj)
{
    int i = 0; 
    for (; i < 10; i++)
        if (this->_items[i] == nullptr) {
            this->_items[i] = obj;
            break;
        }
    if (i == 10) {
        std::cerr << "There is no more room on the table" << std::endl;
    }
}

Object *PapaXmasTable::take(const std::string &title)
{
    for (int i = 0; i < 10; i++) {
        if (this->_items[i] != nullptr && (this->_items[i])->getTitle() == title) {
            Object *rtn = this->_items[i];
            this->_items[i] = nullptr;
            return (rtn);
        }
    }
    return (nullptr);
}

std::string *PapaXmasTable::look()
{
    std::string *titles = new std::string  [11];
    int ct = 0;

    for (int i = 0; i < 11; i++)
        titles[i] = "";
    for (int i = 0; i < 10; i++)
        if (this->_items[i] != nullptr) {
            titles[ct] = this->_items[i]->getTitle();
            ct++;
        }
    return (titles);
}