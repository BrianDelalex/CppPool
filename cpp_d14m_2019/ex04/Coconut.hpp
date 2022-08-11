/*
** EPITECH PROJECT, 2019
** Coconut.hpp
** File description:
** 
*/

#ifndef COCONUT_HPP_
#define COCONUT_HPP_

#include "Fruit.hpp"

class Coconut : public Fruit
{
public:
    Coconut(const std::string &name = "coconut", int vitamins = 15);
    ~Coconut();
private:
};

#endif
