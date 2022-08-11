/*
** EPITECH PROJECT, 2019
** BorgQueen.cpp
** File description:
** 
*/

#include "BorgQueen.hpp"

namespace Borg
{
    BorgQueen::BorgQueen()
    {
        this->movePtr = &Ship::move;
        this->firePtr = &Ship::fire;
        this->destroyPtr = &Ship::fire;
    }

    BorgQueen::~BorgQueen() {}

    bool BorgQueen::move(Ship *ship, Destination d) 
    {
        return ((ship->*movePtr)(d));
    }

    void BorgQueen::fire(Ship *ship, Federation::Starfleet::Ship *target)
    {
        (ship->*firePtr)(target);
    }

    void BorgQueen::destroy(Ship *ship, Federation::Ship *target)
    {
        (ship->*destroyPtr)(target);
    }
}