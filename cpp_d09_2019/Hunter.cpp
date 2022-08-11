/*
** EPITECH PROJECT, 2019
** Hunter.cpp
** File description:
** 
*/

#include "Hunter.hpp"

Hunter::Hunter(const std::string &name, int level, const std::string &weapon) : Character(name, level), Warrior(name, level, weapon), _race("Elf")
{
    this->_strenght = 9;
    this->_stamina = 9;
    this->_intelligence = 5;
    this->_spirit = 6;
    this->_agility = 25;
    std::cout << this->_name << " is born from a tree" << std::endl;
}

Hunter::~Hunter() {}

int Hunter::CloseAttack()
{
    return (this->CloseAttack2(30, 20, this->_name + " strikes with his sword"));
}

int Hunter::RangeAttack()
{
    if (this->_power < 25) {
        std::cout << this->_name << " out of power" << std::endl;
        return (0);
    }
    std::cout << this->_name << " uses his bow" << std::endl;
    this->_power -= 25;
    return (20 + this->_agility);
}

void Hunter::RestorePower()
{
    this->_power = 100;
    std::cout << this->_name << " meditates" << std::endl;
}