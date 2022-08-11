/*
** EPITECH PROJECT, 2019
** Fruit.cpp
** File description:
** 
*/

#include "Fruit.hpp"

Fruit::Fruit(const std::string &name, const int vitamins) : _name(name)
{
    this->vitamins = vitamins;
}

Fruit::Fruit(const Fruit &b)
{
    this->_name = b.getName();
    this->vitamins = b.getVitamins();
}

Fruit::~Fruit() {}

const std::string Fruit::getName() const
{
    return (this->_name);
}

int Fruit::getVitamins() const
{
    return (this->vitamins);
}

Fruit &Fruit::operator=(const Fruit &b)
{
    this->_name = b.getName();
    this->vitamins = b.getVitamins();
    return (*this);
}