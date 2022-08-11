/*
** EPITECH PROJECT, 2019
** Paladin.hpp
** File description:
** 
*/

#ifndef PALADIN_HPP_
#define PALADIN_HPP_

#include <iostream>
#include "Warrior.hpp"
#include "Priest.hpp"


class Paladin : public Warrior, public Priest
{
public:
    Paladin(const std::string &name, int level, const std::string &weapon);
    ~Paladin();
    int CloseAttack();
    int RangeAttack();
    void RestorePower();
    void Heal();
private:
    const std::string _race;
};

#endif
