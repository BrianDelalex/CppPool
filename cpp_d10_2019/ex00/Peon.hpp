/*
** EPITECH PROJECT, 2019
** Peon.hpp
** File description:
** 
*/

#ifndef PEON_HPP_
#define PEON_HPP_

#include "Victim.hpp"

class Peon : public Victim
{
public:
    Peon(const std::string &name);
    void getPolymorphed() const;
    ~Peon();
private:
};

#endif
