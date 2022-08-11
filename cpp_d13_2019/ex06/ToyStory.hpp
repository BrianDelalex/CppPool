/*
** EPITECH PROJECT, 2019
** ToyStory.hpp
** File description:
** 
*/

#ifndef TOYSTORY_HPP_
#define TOYSTORY_HPP_

#include <iostream>
#include "Toy.hpp"

class ToyStory
{
public:
    ToyStory();
    ~ToyStory();
    static void tellMeAStory(const std::string file, Toy &toy1, bool (Toy::*func1)(const std::string &), Toy &toy2, bool (Toy::*func2)(const std::string &));
private:
};

#endif
