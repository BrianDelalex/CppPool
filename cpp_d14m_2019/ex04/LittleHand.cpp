/*
** EPITECH PROJECT, 2019
** LittleHand.cpp
** File description:
** 
*/

#include "LittleHand.hpp"
#include <vector>
#include <cmath>
#include "Mixer.hpp"

LittleHand::LittleHand()
{
}

LittleHand::~LittleHand() {}

void LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes)
{
    Fruit *fruit;
    std::vector <Fruit *>unsort;

    while ((fruit = unsorted.pickFruit())) {
        if (fruit->getName() == "lemon") {
            if (!lemons.putFruit(fruit))
                unsort.push_back(fruit);
        } else if (fruit->getName() == "banana") {
            if (!bananas.putFruit(fruit))
                unsort.push_back(fruit);
        } else if (fruit->getName() == "lime") {
            if (!limes.putFruit(fruit))
                unsort.push_back(fruit);
        } else {
            unsort.push_back(fruit);
        }
    }
    while (unsort.size() != 0) {
        unsorted.putFruit(unsort.back());
        unsort.pop_back();
    }
}

FruitBox *const *LittleHand::organizeCoconut(Coconut const * const *coconuts)
{
    int nbCoco = 0;
    for (; coconuts[nbCoco] != nullptr; nbCoco++);
    nbCoco = ceil(nbCoco / 6);
    FruitBox **cocoArray = new FruitBox * [nbCoco + 2];
    
    for (int i = 0; i < nbCoco + 1; i++)
        cocoArray[i] = new FruitBox(6);
    int ct = 0;
    for (int i = 0; coconuts[i]; i++) {
        if (!cocoArray[ct]->putFruit((Fruit *)coconuts[i])) {
            ct++;
            cocoArray[ct]->putFruit( (Fruit *)coconuts[i]);
        }
    }
    cocoArray[ct + 1] = nullptr;
    return (cocoArray);
}

void LittleHand::plugMixer(MixerBase &mixer)
{
    Mixer &mix = reinterpret_cast<Mixer &>(mixer);
    mix.plugMixer();
}

void LittleHand::injectVitamin(Fruit &f, int quantity)
{
    InTheMatrixFruit *fruit = reinterpret_cast<InTheMatrixFruit *>(&f);
    fruit->vitamins = quantity;
}