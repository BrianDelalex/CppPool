/*
** EPITECH PROJECT, 2019
** Carrier.hpp
** File description:
** 
*/

#ifndef CARRIER_HPP_
#define CARRIER_HPP_

#include <iostream>
#include "Droid.hpp"

class Carrier
{
public:
    Carrier(std::string Id);
    ~Carrier();
    void operator<<(Droid *d);
    void operator>>(Droid *d);
    const Droid *operator[](const int index) const;
    size_t operator~(void);
    bool operator()(const int x, const int y);
    Carrier &operator<<(size_t &d);
    size_t getSpeed() const;
    size_t getId() const;
    size_t getEnergy() const;
private:
    std::string Id;
    size_t Energy;
    const size_t Attack;
    const size_t Toughness;
    size_t Speed;
    Droid *Droids[5];
};

std::ostream &operator<<(std::ostream &flux, const Droid &d);

#endif
