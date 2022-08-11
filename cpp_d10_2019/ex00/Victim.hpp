/*
** EPITECH PROJECT, 2019
** Victim.hpp
** File description:
** 
*/

#ifndef VICTIM_HPP_
#define VICTIM_HPP_

#include <iostream>

class Victim
{
public:
    Victim(const std::string &name);
    ~Victim();
    const std::string getName(void) const;
    virtual void getPolymorphed() const;
protected:
    const std::string _name;
};

std::ostream &operator<<(std::ostream &flux, const Victim &v);

#endif
