/*
** EPITECH PROJECT, 2019
** Borg.cpp
** File description:
** 
*/

#include "Borg.hpp"
#include <iostream>
#include "Federation.hpp"

namespace Borg
{
    Ship::Ship(int weaponFrequency, short repair)
    {
        this->_side = 300;
        this->_maxWarp = 9;
        this->_home = UNICOMPLEX;
        this->_location = this->_home;
        this->_shield = 100;
        this->_weaponFrequency = weaponFrequency;
        this->_repair = repair;
        std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
        std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
        std::cout << "Resistance is futile." << std::endl;
    }

    Ship::~Ship() {}

    void Ship::setupCore(WarpSystem::Core *coreReactor)
    {
        this->_coreReactor = coreReactor;
    }

    void Ship::checkCore(void)
    {
        if (this->_coreReactor->checkReactor()) {
            std::cout << "Everything is in order." << std::endl;
        } else {
            std::cout << "Critical failure imminent." << std::endl;
        }
    }

    bool Ship::move(int warp , Destination d)
    {
        if (warp <= this->_maxWarp && d != this->_location && this->_coreReactor->checkReactor()) {
            this->_location = d;
            return (true);
        }
        return (false);
    }

    bool Ship::move(int warp)
    {
        if (warp <= this->_maxWarp && this->_location != this->_home && this->_coreReactor->checkReactor()->isStable()) {
            this->_location = this->_home;
            return (true);
        }
        return (false);
    }

    bool Ship::move(Destination d)
    {
        if (d != this->_location && this->_coreReactor->checkReactor()->isStable()) {
            this->_location = d;
            return (true);
        }
        return (false);
    }

    bool Ship::move()
    {
        if (this->_coreReactor->checkReactor()->isStable() && this->_location != this->_home) {
            this->_location = this->_home;
            return (true);
        }
        return (false);
    }

    int Ship::getShield()
    {
       return (this->_shield);
    }

    void Ship::setShield(int shield)
    {
        this->_shield = shield;
    }

    int Ship::getWeaponFrequency(void)
    {
        return (this->_weaponFrequency);
    }

    void Ship::setWeaponFrequency(int frequency)
    {
        this->_weaponFrequency = frequency;
    }

    short Ship::getRepair()
    {
        return (this->_repair);
    }

    void Ship::setRepair(short repair)
    {
        this->_repair = repair;
    }

    void Ship::fire(Federation::Starfleet::Ship *target)
    {
        std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
        target->setShield(target->getShield() - this->_weaponFrequency);
    }

    void Ship::fire(Federation::Ship *target)
    {
        std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
        target->getCore()->checkReactor()->setStability(false);
    }

    void Ship::repair()
    {
        if (this->_repair > 0) {
            std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions." << std::endl;
            this->_repair = this->_repair - 1;
            this->_shield = 100;
        } else {
            std::cout << "Energy cells depleted, shield weakening." << std::endl;
        }
    }

}
