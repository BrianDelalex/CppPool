/*
** EPITECH PROJECT, 2019
** LittleHand.cpp
** File description:
** 
*/

#include "LittleHand.hpp"
#include <vector>

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