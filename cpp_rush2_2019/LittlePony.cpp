/*
** EPITECH PROJECT, 2019
** LittlePony.cpp
** File description:
** 
*/

#include "LittlePony.hpp"

LittlePony::LittlePony()
    : Toy(std::string("happy pony"))
{
}

LittlePony::~LittlePony()
{
}

void LittlePony::isTaken()
{
    std::cout << "yo man" << std::endl;
}