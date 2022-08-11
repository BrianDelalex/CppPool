/*
** EPITECH PROJECT, 2019
** Admiral.hpp
** File description:
** 
*/

#ifndef ADMIRAL_HPP_
#define ADMIRAL_HPP_

#include <iostream>
#include "Destination.hpp"
#include "Federation.hpp"

namespace Federation
{
    namespace Starfleet
    {
        class Admiral
        {
        public:
            Admiral(std::string name);
            ~Admiral();
            bool (Ship::*movePtr)(Destination d);
            void (Ship::*firePtr)(Borg::Ship *target);
            void fire(Ship *ship, Borg::Ship *target);
            bool move(Ship *ship, Destination dest);
        private:
            std::string _name;
        };
    }
}

#endif
