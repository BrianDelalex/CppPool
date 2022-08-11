/*
** EPITECH PROJECT, 2019
** Warrior.cpp
** File description:
** 
*/

#include "Warrior.hpp"

Warrior::Warrior(const std::string &name, int level, const std::string &weapon) : Character(name, level), _weaponName(weapon), _race("Dwarf")
{
    this->_strenght = 12;
    this->_stamina = 12;
    this->_intelligence = 6;
    this->_agility = 7;
    this->_spirit = 5;
    std::cout << "I'm " << this->_name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

Warrior::~Warrior() {}

int Warrior::CloseAttack()
{
    return (CloseAttack2(30, 20, this->_name + " strikes with his hammer"));
}

int Warrior::RangeAttack()
{
    if (this->_power < 10) {
        std::cout << this->_name << " out of power" << std::endl;
        this->Range = CLOSE;
        return (0);
    }
    std::cout << this->_name << " intercepts" << std::endl;
    this->_power -= 10;
    this->Range = CLOSE;
    return (0);
}