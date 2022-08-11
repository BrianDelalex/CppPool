/*
** EPITECH PROJECT, 2019
** Mage.hpp
** File description:
** 
*/

#ifndef MAGE_HPP_
#define MAGE_HPP_

#include "Character.hpp"

class Mage : public Character
{
public:
    Mage(const std::string &name, int level);
    ~Mage();
    int CloseAttack();
    int RangeAttack();
    void RestorePower();
private:
    const std::string _race;
};

#endif
