/*
** EPITECH PROJECT, 2019
** Warrior.hpp
** File description:
** 
*/

#ifndef WARRIOR_HPP_
#define WARRIOR_HPP_

#include "Character.hpp"

class Warrior : virtual public Character
{
public:
    Warrior(const std::string &name, int level, const std::string &weapon = "hache");
    int CloseAttack();
    int RangeAttack();
    ~Warrior();
private:
    const std::string _weaponName;
    const std::string _race;
};

#endif
