/*
** EPITECH PROJECT, 2019
** Priest.cpp
** File description:
** 
*/

#include "Priest.hpp"

Priest::Priest(const std::string &name, int level) : Character(name, level), _race("Orc")
{
    this->_strenght = 4;
    this->_stamina = 4;
    this->_intelligence = 42;
    this->_spirit = 21;
    this->_agility = 2;
    std::cout << this->_name << " enters in the order" << std::endl;
}

Priest::~Priest() {}

int Priest::CloseAttack()
{
    if (this->_power < 10) {
        std::cout << this->_name << " out of power" << std::endl;
        return (0);
    }
    this->_power -= 10;
    std::cout << this->_name << " uses a spirit explosion" << std::endl;
    return (10 + this->_spirit + RangeAttack());

}

int Priest::RangeAttack()
{
    if (this->_power < 25) {
        std::cout << this->_name << " out of power" << std::endl;
        return (0);
    }
    this->_power -= 25;
    std::cout << this->_name << " launches a fire ball" << std::endl;
    return (20 + this->_spirit);
}

void Priest::Heal()
{
    if (this->_power < 10) {
        std::cout << this->_name << " out of power" << std::endl;
    } else {
        this->_power -= 10;
        if (this->_health + 70 > 100) {
            this->_health = 100;
        } else {
            this->_health += 70;
        }
        std::cout << this->_name << " casts a little heal spell" << std::endl;
    }
}

void Priest::RestorePower()
{
    if (this->_power + 50 + this->_intelligence > 100) {
        this->_power = 100;
        std::cout << this->_name << " takes a mana potion" << std::endl;
    } else {
        this->_power = this->_power + 50 + this->_intelligence;
        std::cout << this->_name << " takes a mana potion" << std::endl;
    }
}