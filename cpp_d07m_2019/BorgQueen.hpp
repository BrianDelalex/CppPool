/*
** EPITECH PROJECT, 2019
** BorgQueen.hpp
** File description:
** 
*/

#ifndef BORGQUEEN_HPP_
#define BORGQUEEN_HPP_

#include "Borg.hpp"
#include "Destination.hpp"

namespace Borg
{
    class BorgQueen
    {
    public:
        BorgQueen();
        ~BorgQueen();
        bool (Ship::*movePtr)(Destination d);
        void (Ship::*firePtr)(Federation::Starfleet::Ship *target);
        void (Ship::*destroyPtr)(Federation::Ship *target);
        bool move(Borg::Ship *ship, Destination dest);
        void fire(Borg::Ship *ship, Federation::Starfleet::Ship *target);
        void destroy(Borg::Ship *ship, Federation::Ship *target);
    };
}

#endif
