/*
** EPITECH PROJECT, 2019
** AWeapon.hpp
** File description:
** 
*/

#ifndef AWEAPON_HPP_
#define AWEAPON_HPP_

#include <iostream>

class AWeapon
{
public:
    AWeapon(const std::string &name, int apcost, int damage);
    virtual ~AWeapon();
    std::string const &getName() const;
    int getAPCost() const;
    int getDamage() const;
    virtual void attack() const = 0;
protected:
    const std::string _name;
    int _apcost;
    int _damage;
};

#endif
