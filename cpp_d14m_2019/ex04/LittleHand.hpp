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
#include "Mixer.hpp"

struct InTheMatrixFruit
{
    int  vitamins;
};

class LittleHand
{
public:
    LittleHand();
    ~LittleHand();
    static void sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes);
    static FruitBox * const *organizeCoconut(Coconut const * const *coconuts);
    static void plugMixer(MixerBase &mixer);
    static void injectVitamin(Fruit &f, int quantity);
private:
};

#endif
