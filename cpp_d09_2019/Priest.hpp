/*
** EPITECH PROJECT, 2019
** Priest.hpp
** File description:
** 
*/

#ifndef PRIEST_HPP_
#define PRIEST_HPP_

#include <iostream>
#include "Character.hpp"

class Priest : virtual public Character
{
public:
    Priest(const std::string &name, int level);
    ~Priest();
    int CloseAttack();
    int RangeAttack();
    void Heal();
    void RestorePower();
private:
    const std::string _race;
};

#endif
