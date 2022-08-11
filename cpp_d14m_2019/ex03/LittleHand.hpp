/*
** EPITECH PROJECT, 2019
** LittleHand.hpp
** File description:
** 
*/

#ifndef LITTLEHAND_HPP_
#define LITTLEHAND_HPP_

#include "FruitBox.hpp"
#include "Coconut.hpp"
#include "MixerBase.hpp"

class LittleHand
{
public:
    LittleHand();
    ~LittleHand();
    static void sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes);
    static FruitBox * const *organizeCoconut(Coconut const * const *coconuts);
    static void plugMixer(MixerBase &mixer);
private:
};

#endif
