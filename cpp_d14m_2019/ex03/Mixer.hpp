/*
** EPITECH PROJECT, 2019
** LittleHand.cpp
** File description:
** 
*/

#ifndef MIXER_HPP_
#define MIXER_HPP_

#include "MixerBase.hpp"
#include "FruitBox.hpp"

class Mixer : public MixerBase
{
public:
    Mixer();
    void plugMixer();
    int mix(FruitBox &fruits) const;
};

#endif