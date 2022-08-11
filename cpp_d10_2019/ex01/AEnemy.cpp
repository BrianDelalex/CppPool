/*
** EPITECH PROJECT, 2019
** AEnemy.cpp
** File description:
** 
*/

#include "AEnemy.hpp"

AEnemy::AEnemy(int hp, const std::string &type) : _type(type)
{
    this->_hp = hp;
}

AEnemy::~AEnemy() {}

void AEnemy::takeDamage(int damage)
{
    if (damage > 0) {
        this->_hp -= damage;
    }
}

std::string const &AEnemy::getType() const
{
    return (this->_type);
}

int AEnemy::getHP() const
{
    return (this->_hp);
}