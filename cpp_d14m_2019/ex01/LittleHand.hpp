/*
** EPITECH PROJECT, 2019
** LittleHand.hpp
** File description:
** 
*/

#ifndef LITTLEHAND_HPP_
#define LITTLEHAND_HPP_

#include "FruitBox.hpp"

class LittleHand
{
public:
    LittleHand();
    ~LittleHand();
    static void sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes);
private:
};

#endif
