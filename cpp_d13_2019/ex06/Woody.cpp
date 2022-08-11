/*
** EPITECH PROJECT, 2019
** Woody.cpp
** File description:
** 
*/

#include "Woody.hpp"

Woody::Woody(const std::string &name, const std::string &file) : Toy()
{
    this->_name = name;
    this->_type = WOODY;
    this->_picture = Picture(file);
}

Woody::~Woody() {}

bool Woody::speak(const std::string &statement)
{
    std::cout << "WOODY: " << this->_name << " \"" << statement << "\"" << std::endl;
    return (true);
}