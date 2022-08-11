/*
** EPITECH PROJECT, 2019
** IConvoyerBelt.hpp
** File description:
** 
*/

#ifndef ICONVOYERBELT_HPP_
#define ICONVOYERBELT_HPP_

#include "ITable.hpp"
#include "Wrap.hpp"

class IElf
{

};

class IConveyorBelt
{
public:
    ~IConveyorBelt() {};
    virtual Object *take() = 0;
    virtual void put(Object *obj) = 0;
    virtual void setInput(IElf *input) = 0;
    // virtual void setOutput(IConveyorBelt *output) = 0;
protected:
    Object *_item;
    IElf *_input;
};

#endif
