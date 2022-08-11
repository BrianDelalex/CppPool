/*
** EPITECH PROJECT, 2019
** Parts.cpp
** File description:
** 
*/

#include "Parts.hpp"
#include <typeinfo>

Parts::Parts(std::string serial, bool functional)
{
    this->_serial = serial;
    this->_functional = functional;
}

Parts::~Parts() {}

bool Parts::isFunctional() const
{
    return (this->_functional);
}

std::string Parts::serial() const
{
    return (this->_serial);
}

void Parts::informations()
{
    std::cout << "[Parts] " << typeid(this).name() + 2 << " " << this->_serial << "status : ";
    if (this->_functional) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "KO" << std::endl;
    }
}

std::string Parts::getType() const
{
    return (this->type);
}

Arms::Arms(std::string serial, bool functional) : Parts(serial, functional)
{
    this->type = "Arms";
}

void Arms::informations()
{
    std::cout << "[Parts] " << typeid(this).name() + 2 << " " << this->_serial << " status : ";
    if (this->_functional) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "KO" << std::endl;
    }
}

Legs::Legs(std::string serial, bool functional) : Parts(serial, functional)
{
    this->type = "Legs";
}

void Legs::informations()
{
     std::cout << "[Parts] " << typeid(this).name() + 2 << " " << this->_serial << " status : ";
    if (this->_functional) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "KO" << std::endl;
    }
}

Head::Head(std::string serial, bool functional) : Parts(serial, functional)
{
    this->type = "Head";
}

void Head::informations()
{
     std::cout << "[Parts] " << typeid(this).name() + 2 << " " << this->_serial << " status : ";
    if (this->_functional) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "KO" << std::endl;
    }
}