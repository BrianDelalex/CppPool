/*
** EPITECH PROJECT, 2019
** SuperMutant.hpp
** File description:
** 
*/

#ifndef SUPERMUTANT_HPP_
#define SUPERMUTANT_HPP_

#include "AEnemy.hpp"

class SuperMutant : public AEnemy
{
public:
    SuperMutant();
    ~SuperMutant();
    void takeDamage(int damage);
private:
};

#endif
