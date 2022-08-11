/*
** EPITECH PROJECT, 2019
** Buzz.hpp
** File description:
** 
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_

#include "Toy.hpp"
#include <iostream>

class Buzz : public Toy
{
public:
    Buzz(const std::string &name, const std::string &file = "buzz.txt");
    ~Buzz();
private:
};

#endif
