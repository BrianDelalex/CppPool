/*
** EPITECH PROJECT, 2019
** Character.cpp
** File description:
** 
*/

#include "Character.hpp"

Character::Character(const std::string &name) : _name(name)
{
    this->_ap = 40;
    this->_weapon = nullptr;
}

Character::~Character() {}

void Character::recoverAP()
{
    if (this->_ap + 10 > 40) {
        this->_ap = 40;
    } else {
        this->_ap += 10;
    }
}

void Character::equip(AWeapon *weapon)
{
    this->_weapon = weapon;
}

void Character::attack(AEnemy *enemy)
{
    if (this->_weapon == nullptr)
        return;
    if (this->_ap < this->_weapon->getAPCost())
        return;
    std::cout << this->_name << " attacks " << enemy->getType() << " with a " << this->_weapon->getName() << std::endl;
    this->_weapon->attack();
    this->_ap -= this->_weapon->getAPCost();
    enemy->takeDamage(this->_weapon->getDamage());
    if (enemy->getHP() <= 0)
        enemy->~AEnemy();

}

std::string const &Character::getName() const
{
    return (this->_name);
}

int Character::getAP() const
{
    return (this->_ap);
}

AWeapon *Character::getWeapon() const
{
    return (this->_weapon);
}

std::ostream &operator<<(std::ostream &flux, const Character & c)
{
    AWeapon *w = c.getWeapon();
    if (w == nullptr)
    {
        flux << c.getName() << " has " << c.getAP() << " AP and is unarmed" << std::endl;
    } else {
        flux << c.getName() << " has " << c.getAP() << " AP and wields a " << w->getName() << std::endl;
    }
    return (flux);
}