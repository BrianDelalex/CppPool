/*
** EPITECH PROJECT, 2019
** PlasmaRifle.hpp
** File description:
** 
*/

#ifndef PLASMARIFLE_HPP_
#define PLASMARIFLE_HPP_

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
public:
    PlasmaRifle();
    ~PlasmaRifle();
    void attack() const;
private:
};

#endif
