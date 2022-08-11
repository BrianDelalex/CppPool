/*
** EPITECH PROJECT, 2019
** TacticalMarine.hpp
** File description:
** 
*/

#ifndef TACTICALMARINE_HPP_
#define TACTICALMARINE_HPP_

#include "ISpaceMarine.hpp"
#include <iostream>

class TacticalMarine : public ISpaceMarine
{
public:
    TacticalMarine();
    ~TacticalMarine();
    TacticalMarine* clone() const;
    void battleCry() const;
    void rangedAttack() const;
    void meleeAttack() const;
private:
};

#endif
