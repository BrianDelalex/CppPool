/*
** EPITECH PROJECT, 2019
** AEnemy.hpp
** File description:
** 
*/

#ifndef AENEMY_HPP_
#define AENEMY_HPP_

#include <iostream>

class AEnemy
{
public:
    AEnemy(int hp, const std::string &type);
    virtual ~AEnemy();
    virtual void takeDamage(int damage);
    std::string const &getType() const;
    int getHP() const;
protected:
    const std::string _type;
    int _hp;
};

#endif
