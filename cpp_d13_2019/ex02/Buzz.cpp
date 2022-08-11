/*
** EPITECH PROJECT, 2019
** Buzz.cpp
** File description:
** 
*/

#include "Buzz.hpp"

Buzz::Buzz(const std::string &name, const std::string &file) : Toy()
{
    this->_type = BUZZ;
    this->_name = name;
    this->_picture = Picture(file);
}

Buzz::~Buzz() {}
