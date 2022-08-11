/*
** EPITECH PROJECT, 2019
** Federation.cpp
** File description:
** 
*/

#include "Federation.hpp"
#include <iostream>

// Federation::Federation()
// {
// }

// Federation::~Federation() {}
namespace Federation
{
    Ship::Ship(int length, int width, std::string name)
    {
        this->_lenght = length;
        this->_width = width;
        this->_name = name;
        this->_maxWarp = 1;
        this->_home = VULCAN;
        this->_location = this->_home;
        std::cout << "The independent ship " << this->_name << " just finished its construction." << std::endl;
        std::cout << "It is " << this->_lenght << " m in length and " << this->_width << " m in width." << std::endl;
    }

    Ship::~Ship() {}

    void Ship::setupCore(WarpSystem::Core *coreReactor)
    {
        this->_coreReactor = coreReactor;
        std::cout  << this->_name << ": The core is set." << std::endl;
    }

    void Ship::checkCore()
    {
        if (this->_coreReactor->checkReactor()->isStable()) {
            std::cout << this->_name << ": The core is stable at the time." << std::endl;
        } else {
            std::cout << this->_name << ": The core is unstable at the time." << std::endl;
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

    WarpSystem::Core *Ship::getCore()
    {
        return (this->_coreReactor);
    }

    namespace Starfleet
    {
        Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo)
        {
            this->_lenght = length;
            this->_width = width;
            this->_name = name;
            this->_maxWarp = maxWarp;
            this->_home = EARTH;
            this->_location = this->_home;
            this->_shield = 100;
            this->_photonTorpedo = torpedo;
            std::cout << "The ship USS " << this->_name << " has been finished." << std::endl;
            std::cout << "It is " << this->_lenght << " m in length and " << this->_width << " m in width." << std::endl;
            std::cout << "It can go to Warp " << this->_maxWarp << "!" << std::endl;
            if (this->_photonTorpedo != 0)
                std::cout << "Weapons are set: " << this->_photonTorpedo << " torpedoes ready." << std::endl;
        }

        Ship::Ship()
        {
            this->_lenght = 289;
            this->_width = 132;
            this->_maxWarp = 6;
            this->_name = "Entreprise";
            this->_home = EARTH;
            this->_shield = 100;
            this->_photonTorpedo = 0;
            this->_location = this->_home;
            std::cout << "The ship USS " << this->_name << " has been finished." << std::endl;
            std::cout << "It is " << this->_lenght << " m in length and " << this->_width << " m in width." << std::endl;
            std::cout << "It can go to Warp " << this->_maxWarp << "!" << std::endl;
        }
        
        Ship::~Ship() {}

        void Ship::setupCore(WarpSystem::Core *coreReactor)
        {
            this->_coreReactor = coreReactor;
            std::cout << "USS " << this->_name << ": The core is set." << std::endl;
        }

        void Ship::checkCore()
        {
            if (this->_coreReactor->checkReactor()->isStable()) {
                std::cout << "USS " << this->_name << ": The core is stable at the time." << std::endl;
            } else {
                std::cout << "USS " << this->_name << ": The core is unstable at the time." << std::endl;
            }
        }

        void Ship::promote(Captain *captain)
        {
            this->_captain = captain;
            std::cout << this->_captain->getName() << ": I'm glad to be the captain of the USS " << this->_name << "." << std::endl;
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

        int Ship::getTorpedo()
        {
            return (this->_photonTorpedo);
        }

        void Ship::setTorpedo(int torpedo)
        {
            this->_photonTorpedo = torpedo;
        }

        void Ship::fire(Borg::Ship *target)
        {
            if (this->_photonTorpedo != 0) {
                this->_photonTorpedo = this->_photonTorpedo - 1;
                target->setShield(target->getShield() - 50);
                std::cout << this->_name << ": Firing on target. " << this->_photonTorpedo <<  " torpedoes remaining." << std::endl;
            } else {
                std::cout << this->_name << ": No enough torpedoes to fire, " << this->_captain->getName() << "!" << std::endl;
            }
        }

        void Ship::fire(int torpedoes, Borg::Ship *target)
        {
            if (torpedoes < this->_photonTorpedo) {
                this->_photonTorpedo = this->_photonTorpedo - torpedoes;
                target->setShield(target->getShield() - 50 * torpedoes);
                std::cout << this->_name << ": Firing on target. " << this->_photonTorpedo <<  " torpedoes remaining." << std::endl;
            } else if (this->_photonTorpedo != 0) {
                target->setShield(target->getShield() - 50 * this->_photonTorpedo);
                this->_photonTorpedo = 0;
                std::cout << this->_name << ": No more torpedo to fire, " << this->_captain->getName() << "!" << std::endl;
            } else {
                std::cout << this->_name << ": No enough torpedoes to fire, " << this->_captain->getName() << "!" << std::endl;
            }
        }

        Captain::Captain(std::string name)
        {
            this->_name = name;
        }

        Captain::~Captain() {}

        std::string Captain::getName()
        {
            return (this->_name);
        }

        int Captain::getAge()
        {
            return (this->_age);
        }

        void Captain::setAge(int age)
        {
            this->_age = age;
        }

        Ensign::Ensign(std::string name)
        {
            this->_name = name;
            std::cout << "Ensign " << this->_name << ", awaiting orders." << std::endl;
        }

        Ensign::~Ensign() {}
    }
}