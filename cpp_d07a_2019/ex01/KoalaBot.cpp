/*
** EPITECH PROJECT, 2019
** KoalaBot.cpp
** File description:
** 
*/

#include "KoalaBot.hpp"

KoalaBot::KoalaBot(std::string name)
{
    this->_serial = name;
}

KoalaBot::~KoalaBot() {}

void KoalaBot::swapParts(Parts &part)
{
    try {
        Legs& LEGS = dynamic_cast<Legs&>(part);
        this->_leg = LEGS;
    } catch (const std::bad_cast& e) {}
    try {
        Arms& ARMS = dynamic_cast<Arms&>(part);
        this->_arm = ARMS;
    } catch (const std::bad_cast& e) {}
    try {
        Head& HEAD = dynamic_cast<Head&>(part);
        this->_head = HEAD;
    } catch (const std::bad_cast& e) { }
}

void KoalaBot::setParts(const Parts &part) 
{
    if (part.getType() == "Legs")
        this->_leg = Legs(part.serial(), part.isFunctional());
    if (part.getType() == "Head")
        this->_head = Head(part.serial(), part.isFunctional());
    if (part.getType() == "Arms")
        this->_arm = Arms(part.serial(), part.isFunctional());
}

void KoalaBot::informations()
{
    std::cout << "[KoalaBot] " << this->_serial << std::endl;
    std::cout << "     ";
    this->_arm.informations();
    std::cout << "     ";
    this->_leg.informations();
    std::cout << "     ";
    this->_head.informations();
}

bool KoalaBot::status()
{
    return (this->_arm.isFunctional() && this->_leg.isFunctional() && this->_head.isFunctional());
}