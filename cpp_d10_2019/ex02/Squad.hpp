/*
** EPITECH PROJECT, 2019
** Squad.hpp
** File description:
** 
*/

#include "ISquad.hpp"
#include <vector>
#include <algorithm>
#include "TacticalMarine.hpp"

#ifndef SQUAD_HPP_
#define SQUAD_HPP_

class Squad : public ISquad
{
public:
    Squad();
    Squad(const Squad &);
    ~Squad();
    int getCount() const;
    ISpaceMarine *getUnit(int index);
    int push(ISpaceMarine *);
    Squad &operator=(const Squad &s);
private:
    std::vector<ISpaceMarine *>_units;
};

#endif
