/*
** EPITECH PROJECT, 2019
** PowerFist.hpp
** File description:
** 
*/

#ifndef POWERFIST_HPP_
#define POWERFIST_HPP_

#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
public:
    PowerFist();
    ~PowerFist();
    void attack() const;
private:
};

#endif
