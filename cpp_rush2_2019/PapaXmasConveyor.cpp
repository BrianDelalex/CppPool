/*
** EPITECH PROJECT, 2019
** PapaXmasConveyer.cpp
** File description:
** 
*/

#include "PapaXmasConveyor.hpp"

PapaXmasConveyor::PapaXmasConveyor() : IConveyorBelt()
{
    this->_item = nullptr;
}

PapaXmasConveyor::~PapaXmasConveyor() {}

Object *PapaXmasConveyor::take()
{
    Object *rtn = this->_item;
    this->_item = nullptr;
    return (rtn);
}

void PapaXmasConveyor::put(Object *obj)
{
    if (this->_item == nullptr)
        this->_item = obj;
}

void PapaXmasConveyor::setInput(IElf *input)
{
    this->_input = input;
}

void PapaXmasConveyor::out()
{
    delete this->_item;
}