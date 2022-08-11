/*
** EPITECH PROJECT, 2019
** Lemon.hpp
** File description:
** 
*/

#ifndef LEMON_HPP_
#define LEMON_HPP_

#include "Fruit.hpp"

class Lemon : public Fruit
{
public:
    Lemon(const std::string &name = "lemon", int vitamins = 3);
    ~Lemon();
private:
};

#endif
