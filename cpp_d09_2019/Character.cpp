/*
** EPITECH PROJECT, 2019
** Character.cpp
** File description:
** 
*/

#include "Character.hpp"

Character::Character(const std::string &name, int level) : _name(name), _race("Human")
{
    this->_level = level;
    this->_health = 100;
    this->_power = 100;
    this->Range = CLOSE;
    this->_strenght = 5;
    this->_stamina = 5;
    this->_intelligence = 5;
    this->_spirit = 5;
    this->_agility = 5;
    std::cout << this->_name << " Created" << std::endl;
}

Character::~Character() {}

const std::string &Character::getName() const
{
    return (this->_name);
}

int Character::getLvl() const
{
    return (this->_level);
}

int Character::getPv() const
{
    return (this->_health);
}

int Character::getPower() const
{
    return (this->_power);
}

int Character::CloseAttack()
{
    return (CloseAttack2(10, 10, this->_name + " strikes with a wooden stick"));
}

int Character::CloseAttack2(int nrj, int dmg, std::string display)
{
    if (this->_power < nrj) {
        std::cout << this->_name << " out of power" << std::endl;
        return (0);
    }
    std::cout << display << std::endl;
    this->_power -= nrj;
    return (dmg + this->_strenght);
}

void Character::Heal()
{
    if (this->_health + 50 < 100)
        this->_health = this->_health + 50;
    else
        this->_health = 100;
    std::cout << this->_name << " takes a potion" << std::endl;
}

int Character::RangeAttack()
{
    return (CloseAttack2(10, 5, this->_name + " tosses a stone"));
}

void Character::RestorePower()
{
    this->_power = 100;
    std::cout << this->_name << " eats" << std::endl;
}

void Character::TakeDamage(int damage)
{
    if (this->_health - damage <= 0) {
        this->_health = 0;
        std::cout << this->_name << " Out of combat" << std::endl;
    } else {
        std::cout << this->_name << " takes " << damage << " damage" << std::endl;
        this->_health -= damage;
    }
}