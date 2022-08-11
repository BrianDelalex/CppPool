/*
** EPITECH PROJECT, 2019
** Teddy.cpp
** File description:
** 
*/

#include "Teddy.hpp"

Teddy::Teddy()
    : Toy(std::string("cuddles"))
{
}

Teddy::~Teddy() {}

void Teddy::isTaken()
{
    std::cout << "gra hu" << std::endl;
}