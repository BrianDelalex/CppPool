/*
** EPITECH PROJECT, 2019
** Hunter.hpp
** File description:
** 
*/

#ifndef HUNTER_HPP_
#define HUNTER_HPP_

#include "Warrior.hpp"
#include <iostream>

class Hunter : public Warrior
{
public:
    Hunter(const std::string &name, int level, const std::string &weapon);
    ~Hunter();
    int CloseAttack();
    int RangeAttack();
    void RestorePower();
private:
    const std::string _race;
};

#endif
