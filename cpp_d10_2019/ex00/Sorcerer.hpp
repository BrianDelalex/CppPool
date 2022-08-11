/*
** EPITECH PROJECT, 2019
** Sorcerer.hpp
** File description:
** 
*/

#ifndef SORCERER_HPP_
#define SORCERER_HPP_

#include <iostream>
#include "Victim.hpp"
#include "Peon.hpp"

class Sorcerer
{
public:
    Sorcerer(const std::string &name, const std::string &title);
    ~Sorcerer();
    const std::string getName(void) const;
    const std::string getTitle(void) const;
    void polymorph(const Victim &victim) const;
private:
    const std::string _name;
    const std::string _title;
};

std::ostream &operator<<(std::ostream &flux, const Sorcerer &sorcerer);

#endif
