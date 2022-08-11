/*
** EPITECH PROJECT, 2019
** Woody.hpp
** File description:
** 
*/

#ifndef WOODY_HPP_
#define WOODY_HPP_

#include "Toy.hpp"
#include <iostream>

class Woody : public Toy
{
public:
    Woody(const std::string &name, const std::string &file = "woody.txt");
    ~Woody();
    bool speak(const std::string &statement) override;
private:
};

#endif
