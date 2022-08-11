/*
** EPITECH PROJECT, 2019
** Victim.cpp
** File description:
** 
*/

#include "Victim.hpp"

Victim::Victim(const std::string &name) : _name(name)
{
    std::cout << "Some random victim called " << this->_name << " just popped!" << std::endl;
}

Victim::~Victim() 
{
    std::cout << "Victim "<< this->_name << " just died for no apparent reason!" << std::endl;
}

const std::string Victim::getName(void) const { return (this->_name); }

void Victim::getPolymorphed() const
{
    std::cout << this->_name << " has been turned into a cute little sheep!" << std::endl;
}

std::ostream &operator<<(std::ostream &flux, const Victim &v)
{
    flux << "I'm " << v.getName() << " and I like otters!" << std::endl;
    return (flux);
}