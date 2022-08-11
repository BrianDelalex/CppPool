/*
** EPITECH PROJECT, 2019
** Sorcerer.cpp
** File description:
** 
*/

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(const std::string &name, const std::string &title) : _name(name), _title(title)
{
    std::cout << this->_name << ", " << this->_title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
    std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same!" << std::endl;
}

const std::string Sorcerer::getName() const
{
    return (this->_name);
}

const std::string Sorcerer::getTitle() const
{
    return (this->_title);
}

void Sorcerer::polymorph(const Victim &victim) const
{
    victim.getPolymorphed();
}

std::ostream &operator<<(std::ostream &flux, const Sorcerer &sorcerer)
{
    flux << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle() << ", and I like ponies!" << std::endl;
    return (flux);
}