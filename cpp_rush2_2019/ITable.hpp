/*
** EPITECH PROJECT, 2019
** ITable.hpp
** File description:
** 
*/

#ifndef ITABLE_HPP_
#define ITABLE_HPP_

#include <iostream>
#include "Object.hpp"
#include <array>

class ITable
{
public:
    virtual ~ITable() {};
    virtual void put(Object *obj) = 0;
    virtual Object *take(const std::string &title) = 0;
    virtual std::string *look() = 0;
protected:
    Object *_items[10];
};

#endif
