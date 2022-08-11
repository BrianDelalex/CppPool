/*
** EPITECH PROJECT, 2019
** Lime.hpp
** File description:
** 
*/

#ifndef LIME_HPP_
#define LIME_HPP_

#include "Lemon.hpp"

class Lime : public Lemon
{
public:
    Lime(const std::string &name = "lime", int vitamins = 2);
    ~Lime();
private:
};

#endif
