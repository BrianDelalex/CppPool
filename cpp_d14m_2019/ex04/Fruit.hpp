/*
** EPITECH PROJECT, 2019
** Fruit.hpp
** File description:
** 
*/

#ifndef FRUIT_HPP_
#define FRUIT_HPP_

#include <iostream>

class Fruit
{
public:
    Fruit(const std::string &name, const int vitamins);
    Fruit(const Fruit &b);
    ~Fruit();
    const std::string getName() const;
    int getVitamins() const;
    Fruit &operator=(const Fruit &b);
protected:
    int vitamins;
    std::string _name;
};

#endif
