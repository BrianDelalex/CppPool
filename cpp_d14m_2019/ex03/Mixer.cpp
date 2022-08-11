/*
** EPITECH PROJECT, 2019
** LittleHand.cpp
** File description:
** 
*/

#include "Mixer.hpp"


int mix(FruitBox &fruits)
{
    Fruit *fruit;
    int total = 0;
    while ((fruit = fruits.pickFruit())) {
        total += fruit->getVitamins();
    }
    return (total);
}

Mixer::Mixer()
{
    this->_plugged = false;
    this->_mixfunc = &::mix;
}

void Mixer::plugMixer()
{
    this->_plugged = true;
}

int Mixer::mix(FruitBox &fruits) const
{
    if (this->_plugged) {
        this->_mixfunc(fruits);
    }
}