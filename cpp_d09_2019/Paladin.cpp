/*
** EPITECH PROJECT, 2019
** Paladin.cpp
** File description:
** 
*/

#include "Paladin.hpp"

Paladin::Paladin(const std::string &name, int level, const std::string &weapon) : Character(name, level), Warrior(name, level, weapon), Priest(name, level), _race("Human")
{
    this->_strenght = 9;
    this->_stamina = 10;
    this->_intelligence = 10;
    this->_spirit = 10;
    this->_agility = 2;
    std::cout << "The light falls on " << this->_name << std::endl;
}

Paladin::~Paladin() {}

int Paladin::CloseAttack()
{
    return (((Warrior *)this)->CloseAttack());
}

int Paladin::RangeAttack()
{
    return (((Priest *)this)->RangeAttack());
}

void Paladin::RestorePower()
{
    ((Character *)this)->RestorePower();
}

void Paladin::Heal()
{
    ((Priest *)this)->Heal();
}