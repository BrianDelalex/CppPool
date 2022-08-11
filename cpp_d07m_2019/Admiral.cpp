/*
** EPITECH PROJECT, 2019
** Admiral.cpp
** File description:
** 
*/

#include "Admiral.hpp"
#include "Borg.hpp"

namespace Federation
{
    namespace Starfleet
    {
        Admiral::Admiral(std::string name)
        {
            this->_name = name;
            this->firePtr = &Ship::fire;
            this->movePtr = &Ship::move;
            std::cout << "Admiral " << this->_name << " ready for action." << std::endl;
        }

        Admiral::~Admiral() {}

        void Admiral::fire(Ship *ship, Borg::Ship *target)
        {
            std::cout << "On order from Admiral " << this->_name << ":" << std::endl;
            (ship->*firePtr)(target);
        }

        bool Admiral::move(Ship *ship, Destination d)
        {
            return ((ship->*movePtr)(d));
        }
    }
}