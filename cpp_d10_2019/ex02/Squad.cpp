/*
** EPITECH PROJECT, 2019
** Squad.cpp
** File description:
** 
*/

#include "Squad.hpp"

Squad::Squad()
{
}

void destroyAll(ISpaceMarine *m)
{
    delete m;
}

Squad::Squad(const Squad &s)
{
    std::for_each(this->_units.begin(), this->_units.end(), destroyAll);
    this->_units.clear();

    for (int i = 0; i < (int) s._units.size(); i++)
        this->_units.push_back(s._units.at(i)->clone());
}

Squad::~Squad()
{
    for (int i = 0; i < (int) this->_units.size(); i++) {
        delete this->_units.at(i);
    }
    this->_units.shrink_to_fit();
}

int Squad::getCount() const
{
   return (this->_units.size());
}

ISpaceMarine *Squad::getUnit(int index)
{
    if (index > getCount())
        return (nullptr);
    return (this->_units.at(index));
}

int Squad::push(ISpaceMarine *unit)
{
    if (unit == nullptr)
        return (getCount());
    for (int i = 0; i < (int) this->_units.size(); i++) {
        if (unit == this->_units.at(i))
            return (getCount());
    }
    this->_units.push_back(unit);
    return (getCount());
}

Squad &Squad::operator=(const Squad &s)
{
    std::for_each(this->_units.begin(), this->_units.end(), destroyAll);
    this->_units.clear();

    for (int i = 0; i < (int) s._units.size(); i++)
    {
        this->_units.push_back(s._units.at(i)->clone());
    }
    return (*this);
}