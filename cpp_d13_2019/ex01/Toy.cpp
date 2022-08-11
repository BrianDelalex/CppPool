/*
** EPITECH PROJECT, 2019
** Toy.cpp
** File description:
** 
*/

#include "Toy.hpp"

Toy::Toy()
{
    this->_type = BASIC_TOY;
    this->_picture = Picture();
    this->_name = "toy";
}

Toy::Toy(Toy::ToyType type, const std::string &name, const std::string &file)
{
    this->_type = type;
    this->_name = name;
    this->_picture = Picture(file);
}

Toy::Toy(const Toy &b)
{
    this->_picture.data = std::string(b._picture.data);
    this->_type = b.getType();
    this->_name = b.getName();
}

Toy::~Toy() {}

Toy &Toy::operator=(const Toy &b)
{
    this->_picture.data = std::string(b._picture.data);
    this->_type = b.getType();
    this->_name = b.getName();
    return (*this);
}

Toy::ToyType Toy::getType() const { return ( this->_type ); }

std::string Toy::getName() const { return ( this->_name ); }
    
void Toy::setName(const std::string &name) { this->_name = name; }

bool Toy::setAscii(const std::string &file)
{
    return ( this->_picture.getPictureFromFile(file) );
}

std::string Toy::getAscii() const
{
    return ( this->_picture.data );
}
