/*
** EPITECH PROJECT, 2019
** Mage.cpp
** File description:
** 
*/

#include "Mage.hpp"

Mage::Mage(const std::string &name, int level) : Character(name, level), _race("Gnome")
{
    this->_strenght = 6;
    this->_stamina = 6;
    this->_intelligence = 12;
    this->_spirit = 11;
    this->_agility = 7;
    std::cout << this->_name << " teleported" << std::endl;
}

Mage::~Mage() {}

int Mage::CloseAttack()
{
    if (this->_power < 10) {
        std::cout << this->_name << " out of power" << std::endl;
        return (0);
    }
    this->_power -= 10;
    std::cout << this->_name << " blinks" << std::endl;
    return (RangeAttack());

}

int Mage::RangeAttack()
{
    if (this->_power < 25) {
        std::cout << this->_name << " out of power" << std::endl;
        return (0);
    }
    this->_power -= 25;
    std::cout << this->_name << " launches a fire ball" << std::endl;
    return (20 + this->_spirit);
}

void Mage::RestorePower()
{
    if (this->_power + 50 + this->_intelligence > 100) {
        this->_power = 100;
        std::cout << this->_name << " takes a mana potion" << std::endl;
    } else {
        this->_power = this->_power + 50 + this->_intelligence;
        std::cout << this->_name << " takes a mana potion" << std::endl;
    }
}